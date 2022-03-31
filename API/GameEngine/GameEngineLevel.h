#pragma once
#include <list>
#include <map>
#include <GameEngineBase/GameEngineNameObject.h>
#include <GameEngineBase/GameEngineMath.h>


// ���� :
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


	inline float4 GetCameraPos()
	{
		return CameraPos_;
	}

	inline void MoveCameraPos(const float4& _Value)
	{
		CameraPos_ += _Value;
	}

	inline void SetCameraPos(const float4& _Value)
	{
		CameraPos_ = _Value;
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

	float4 CameraPos_;

	void ActorUpdate();
	void ActorRender();
	void ActorRelease();
};

