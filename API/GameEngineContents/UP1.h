#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngineBase/GameEngineTime.h>
#include "Point.h"

// Ό³Έν :
class UP1 : public GameEngineActor
{
public:
	// constrcuter destructer
	UP1();
	~UP1();

	// delete Function
	UP1(const UP1& _Other) = delete;
	UP1(UP1&& _Other) noexcept = delete;
	UP1& operator=(const UP1& _Other) = delete;
	UP1& operator=(UP1&& _Other) noexcept = delete;

	float Time;
protected:

private:
	void Start() override;
	void Update() override;
};

