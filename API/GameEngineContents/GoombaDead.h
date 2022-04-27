#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngineBase/GameEngineTime.h>
#include "Point.h"

// Ό³Έν :
class GoombaDead : public GameEngineActor
{
public:
	// constrcuter destructer
	GoombaDead();
	~GoombaDead();

	// delete Function
	GoombaDead(const GoombaDead& _Other) = delete;
	GoombaDead(GoombaDead&& _Other) noexcept = delete;
	GoombaDead& operator=(const GoombaDead& _Other) = delete;
	GoombaDead& operator=(GoombaDead&& _Other) noexcept = delete;
	float4 Dir;

protected:

private:
	GameEngineRenderer* Actor;
	void Start() override;
	void Update() override;
};

