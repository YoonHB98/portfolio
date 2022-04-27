#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngineBase/GameEngineTime.h>
#include "Point.h"

// Ό³Έν :
class TurtleDeath : public GameEngineActor
{
public:
	// constrcuter destructer
	TurtleDeath();
	~TurtleDeath();

	// delete Function
	TurtleDeath(const TurtleDeath& _Other) = delete;
	TurtleDeath(TurtleDeath&& _Other) noexcept = delete;
	TurtleDeath& operator=(const TurtleDeath& _Other) = delete;
	TurtleDeath& operator=(TurtleDeath&& _Other) noexcept = delete;
	float4 Dir;

protected:

private:
	GameEngineRenderer* Actor;
	void Start() override;
	void Update() override;
};

