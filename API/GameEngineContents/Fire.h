#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineImage.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineCollision.h>


// Ό³Έν :


class Fire : public GameEngineActor
{
public:
	// constrcuter destructer
	Fire();
	~Fire();

	// delete Function
	Fire(const Fire& _Other) = delete;
	Fire(Fire&& _Other) noexcept = delete;
	Fire& operator=(const Fire& _Other) = delete;
	Fire& operator=(Fire&& _Other) noexcept = delete;
	GameEngineCollision* CheckCollision;
	GameEngineCollision* FireCollision;
	GameEngineCollision* RightCollision;
	GameEngineCollision* LeftCollision;	
	GameEngineCollision* FireColor;
	GameEngineCollision* FireDownColor;
	void CreateFire(const float4& _Pivot, const float4& _Angle);
	float4 AngleDir;
protected:

private:
	float4 CreateAngleDir;
	float Angle;
	bool DeathCount = false;
	bool DeathFirst = true;
	float Speed_;
	float4 ReturnPosition();
	void ColMap();
	void Start() override;
	void Update() override;
	GameEngineRenderer* Actor;

};

