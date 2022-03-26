#pragma once
#include "GameEngineBase/GameEngineNameObject.h"
#include <list>
#include <map>

// ���� :
class GameEngine;
class GameEngineActor;
class GameEngineLevel : public GameEngineNameObject
{
	friend GameEngine;
public:
	// constrcuter destructer
	GameEngineLevel();

	// ������ ����� �˾ƾ� �մϴ�.
	// �̰� ���� �߿��ϱ� ����
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
		//�̸� ����
		NewActor->SetName(_Name);
		//���� ����
		NewActor->SetLevel(this);
		//���� �� �ϰ� ����
		StartActor->Start();
		std::list<GameEngineActor*>& Group = AllActor_[_Order];
		Group.push_back(NewActor);

		return NewActor;
	}

protected:

	//���� ������ ������Ʈ
	virtual void Loading() = 0;
	// �� ������ ���� �����϶� �ؾ������� �����Ѵ�.
	virtual void Update() = 0;
	// Current���� => Next������ �����Ҷ� ���緹���� �����ϴ� �Լ�.
	virtual void LevelChangeStart() {}
	// Current���� => Next������ �����Ҷ� ���������� �����ϴ� �Լ�.
	virtual void LevelChangeEnd() {}

private:
	std::map<int, std::list<GameEngineActor*>> AllActor_;

	void ActorUpdate();
	void ActorRender();
	void ActorRelease();
};

