#pragma once
#include "GameEngineBase/GameEngineNameObject.h"
#include <list>
#include <map>

// 설명 :
class GameEngine;
class GameEngineActor;
class GameEngineLevel : public GameEngineNameObject
{
	friend GameEngine;
public:
	// constrcuter destructer
	GameEngineLevel();

	// 면접때 물어보면 알아야 합니다.
	// 이건 정말 중요하기 때문
	virtual ~GameEngineLevel();

	// delete Function
	GameEngineLevel(const GameEngineLevel& _Other) = delete;
	GameEngineLevel(GameEngineLevel&& _Other) noexcept = delete;
	GameEngineLevel& operator=(const GameEngineLevel& _Other) = delete;
	GameEngineLevel& operator=(GameEngineLevel&& _Other) noexcept = delete;

	template<typename ActorType>
	ActorType* CreateActor(int _Order = 0, const std::string& _Name = "")
	{
		ActorType* NewActor = new ActorType();
		GameEngineActor* StartActor = NewActor;
		//이름 세팅
		NewActor->SetName(_Name);
		//레벨 세팅
		NewActor->SetLevel(this);
		//세팅 다 하고 시작
		StartActor->Start();
		std::list<GameEngineActor*>& Group = AllActor_[_Order];
		Group.push_back(NewActor);

		return NewActor;
	}

protected:

	//레벨 수준의 업데이트
	virtual void Loading() = 0;
	// 이 레벨이 현재 레벨일때 해야할일을 실행한다.
	virtual void Update() = 0;
	// Current레벨 => Next레벨로 이전할때 현재레벨이 실행하는 함수.
	virtual void LevelChangeStart() {}
	// Current레벨 => Next레벨로 이전할때 이전레벨이 실행하는 함수.
	virtual void LevelChangeEnd() {}

private:
	std::map<int, std::list<GameEngineActor*>> AllActor_;

	void ActorUpdate();
	void ActorRender();
	void ActorRelease();
};

