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

	// ���������� ������Ʈ
	virtual void Update() = 0;
	//������ �ٲ� ���� �ϰ� ������
	//�ٲ��� �ٲ� ������ �����ϴ� �Լ�
	virtual void LevelChangeStart() {}
	//�ٲ� �ٲ�� �� ������ �����ϴ� �Լ�
	virtual void LevelChangeEnd() {}

	template<typename ActorType>
	ActorType* CreateActor(const std::string& _Name, int _Order)
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

