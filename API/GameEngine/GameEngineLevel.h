#pragma once
#include "GameEngineBase/GameEngineNameObject.h"
#include <list>
#include<map>

class GameEngine;
class GameEngineActor;
class GameEngineLevel : public GameEngineNameObject
{
	friend GameEngine;
public:
	// constrcuter destructer
	GameEngineLevel();

	virtual ~GameEngineLevel();

	// delete Function
	GameEngineLevel(const GameEngineLevel& _Other) = delete;
	GameEngineLevel(GameEngineLevel&& _Other) noexcept = delete;
	GameEngineLevel& operator=(const GameEngineLevel& _Other) = delete;
	GameEngineLevel& operator=(GameEngineLevel&& _Other) noexcept = delete;

protected:
	virtual void Loading() = 0;

	// 레벨수준의 업데이트
	virtual void Update() = 0;
	//레벨이 바뀔때 뭔가 하고 싶으면
	//바뀔떄 바뀐 레벨이 실행하는 함수
	virtual void LevelChangeStart() {}
	//바뀔때 바뀌기 전 레벨이 실행하는 함수
	virtual void LevelChangeEnd() {}

	template<typename ActorType>
	ActorType* CreateActor(const std::string& _Name, int _Order)
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

		//if (FindGroup ==AllActor_.end())
		//{
		//	AllActor_.insert(std::map<int, std::list<GameEngineActor*>>::value_type());
		//}

		return nullptr;
	}

private:
	std::map<int, std::list<GameEngineActor*>> AllActor_;

	void ActorUpdate();
	void ActorRender();
};

