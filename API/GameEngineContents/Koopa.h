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


class Koopa : public GameEngineActor
{
public:
	// constrcuter destructer
	Koopa();
	~Koopa();

	// delete Function
	Koopa(const Koopa& _Other) = delete;
	Koopa(Koopa&& _Other) noexcept = delete;
	Koopa& operator=(const Koopa& _Other) = delete;
	Koopa& operator=(Koopa&& _Other) noexcept = delete;
	GameEngineCollision* CheckCollisionRight;
	GameEngineCollision* CheckCollisionLeft;
	GameEngineCollision* KoopaCollision;
	GameEngineCollision* RightCollision;
	GameEngineCollision* LeftCollision;	
	GameEngineCollision* KoopaColor;
	GameEngineCollision* KoopaDownColor;
	void CreateKoopa(const float4& _Pivot);
	Player* Player;
	Koopa* Goom;
	float4 MoveDir;
	int up = 0;
	GameEngineImage* ColMap_;
	int Random(int _Min, int _Max);
protected:

private:
	int Random_;
	bool First_ = true;
	bool Second_ = false;
	float Time_ = 0;
	bool DeathCount = false;
	bool DeathFirst = true;
	float Speed_;
	float4 ReturnPosition();
	void ColMap();
	void Start() override;
	void Update() override;
	GameEngineRenderer* Actor;

};

