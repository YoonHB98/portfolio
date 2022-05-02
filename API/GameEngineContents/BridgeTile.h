#pragma once
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineCollision.h>
#include <GameEngine/GameEngineLevel.h>
#include "Bridge.h"


// Ό³Έν :


class BridgeTile : public GameEngineActor
{
public:
	// constrcuter destructer
	BridgeTile();
	~BridgeTile();

	// delete Function
	BridgeTile(const BridgeTile& _Other) = delete;
	BridgeTile(BridgeTile&& _Other) noexcept = delete;
	BridgeTile& operator=(const BridgeTile& _Other) = delete;
	BridgeTile& operator=(BridgeTile&& _Other) noexcept = delete;
	GameEngineCollision* CheckCollision;
protected:

private:
	bool Make = true;
	float Time_ = 0;
	void Start() override;
	void Update() override;
	bool A = true;
	bool B = true;
	bool C = true;
	bool D = true;
	bool E = true;
	bool F = true;
	bool G = true;
	bool H = true;
	bool I = true;
	bool J = true;
	bool K = true;
	bool L = true;
	bool M = true;
	Bridge* Bridge1;
	Bridge* Bridge2;
	Bridge* Bridge3;
	Bridge* Bridge4;
	Bridge* Bridge5;
	Bridge* Bridge6;
	Bridge* Bridge7;
	Bridge* Bridge8;
	Bridge* Bridge9;
	Bridge* Bridge10;
	Bridge* Bridge11;
	Bridge* Bridge12;
	Bridge* Bridge13;
};

