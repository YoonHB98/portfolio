#pragma once
#include <GameEngine/GameEngineActor.h>
// ���� : ���ʹ� �ƴϰ� ���Ϳ��� ����� ���� ������� ģ��
class GameEngineActorSubObject
{
public:
	// constrcuter destructer
	GameEngineActorSubObject();
	~GameEngineActorSubObject();

	// delete Function
	GameEngineActorSubObject(const GameEngineActorSubObject& _Other) = delete;
	GameEngineActorSubObject(GameEngineActorSubObject&& _Other) noexcept = delete;
	GameEngineActorSubObject& operator=(const GameEngineActorSubObject& _Other) = delete;
	GameEngineActorSubObject& operator=(GameEngineActorSubObject&& _Other) noexcept = delete;

	inline GameEngineActor* GetActor()
	{
		return Actor_;
	}
protected:
	inline void SetActor(GameEngineActor* _Actor)
	{
		Actor_ = _Actor;
	}


private:
	GameEngineActor* Actor_;
};

