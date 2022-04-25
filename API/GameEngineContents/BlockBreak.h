#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngineBase/GameEngineTime.h>
#include "Point.h"

// Ό³Έν :
class BlockBreak : public GameEngineActor
{
public:
	// constrcuter destructer
	BlockBreak();
	~BlockBreak();

	// delete Function
	BlockBreak(const BlockBreak& _Other) = delete;
	BlockBreak(BlockBreak&& _Other) noexcept = delete;
	BlockBreak& operator=(const BlockBreak& _Other) = delete;
	BlockBreak& operator=(BlockBreak&& _Other) noexcept = delete;
	float4 Dir;

protected:

private:
	GameEngineRenderer* Actor;
	void Start() override;
	void Update() override;
};

