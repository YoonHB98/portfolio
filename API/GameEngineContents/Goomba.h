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


class Goomba : public GameEngineActor
{
public:
	// constrcuter destructer
	Goomba();
	~Goomba();

	// delete Function
	Goomba(const Goomba& _Other) = delete;
	Goomba(Goomba&& _Other) noexcept = delete;
	Goomba& operator=(const Goomba& _Other) = delete;
	Goomba& operator=(Goomba&& _Other) noexcept = delete;
	GameEngineCollision* CheckCollision;
	GameEngineCollision* GoombaCollision;
	GameEngineCollision* RightCollision;
	GameEngineCollision* LeftCollision;	
	GameEngineCollision* GoombaColor;
	GameEngineCollision* GoombaDownColor;
	void CreateGoomba(const float4& _Pivot);
	Player* Player;
	Goomba* Goom;
	float4 MoveDir;
	int up = 0;
	GameEngineImage* ColMap_;
protected:

private:
	bool DeathCount = false;
	bool DeathFirst = true;
	float Speed_;
	float4 ReturnPosition();
	void ColMap();
	void Start() override;
	void Update() override;
	GameEngineRenderer* Actor;

};

