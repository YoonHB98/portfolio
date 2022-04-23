#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineImage.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineCollision.h>
#include "Player.h"


// Ό³Έν :



class TurtleDead : public GameEngineActor
{
public:
	// constrcuter destructer
	TurtleDead();
	~TurtleDead();

	// delete Function
	TurtleDead(const TurtleDead& _Other) = delete;
	TurtleDead(TurtleDead&& _Other) noexcept = delete;
	TurtleDead& operator=(const TurtleDead& _Other) = delete;
	TurtleDead& operator=(TurtleDead&& _Other) noexcept = delete;
	GameEngineCollision* CheckCollision;
	GameEngineCollision* TurtleDeadCollision;
	GameEngineCollision* RightCollision;
	GameEngineCollision* LeftCollision;
	Player* Player;
	TurtleDead* Goom;
	float4 MoveDir;
	int up = 0;
	GameEngineImage* ColMap_;
protected:

private:
	bool DeathCount = false;
	bool DeathFirst = true;
	float Speed_;
	float4 ReturnPosition();

	void Start() override;
	void Update() override;
	GameEngineRenderer* Actor;

};

