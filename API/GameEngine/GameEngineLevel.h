#pragma once
#include "GameEngineBase/GameEngineNameObject.h"

// 설명 :
class GameEngine;
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
	virtual void SceneChangeStart() {}
	//바뀔때 바뀌기 전 레벨이 실행하는 함수
	virtual void SceneChangeEnd() {}

private:
	template<typename ActorType>
	ActorType* CreateActor(const std::string& _Name)
	{
		return nullptr;
	}
};

