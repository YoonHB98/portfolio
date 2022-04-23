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

enum TurtleState
{
	TurtleIdle,
	TurtleMove,

};

class Turtle : public GameEngineActor
{
public:
	// constrcuter destructer
	Turtle();
	~Turtle();

	// delete Function
	Turtle(const Turtle& _Other) = delete;
	Turtle(Turtle&& _Other) noexcept = delete;
	Turtle& operator=(const Turtle& _Other) = delete;
	Turtle& operator=(Turtle&& _Other) noexcept = delete;
	GameEngineCollision* CheckCollision;
	GameEngineCollision* TurtleCollision;
	GameEngineCollision* RightCollision;
	GameEngineCollision* LeftCollision;
	void CreateTurtle(const float4& _Pivot);
	Player* Player;
	Turtle* Goom;
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

