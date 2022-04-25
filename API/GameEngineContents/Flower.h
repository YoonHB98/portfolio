#pragma once
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineCollision.h>
#include <GameEngine/GameEngineLevel.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineSound.h>
#include <GameEngineContents/Point.h>


class Flower : public GameEngineActor
{
public:
	// constrcuter destructer
	Flower();
	~Flower();

	// delete Function
	Flower(const Flower& _Other) = delete;
	Flower(Flower&& _Other) noexcept = delete;
	Flower& operator=(const Flower& _Other) = delete;
	Flower& operator=(Flower&& _Other) noexcept = delete;

	GameEngineCollision* FlowerCollision;
	GameEngineCollision* FlowerHitBox;
	void CreateFlower(const float4& _Pivot);
	GameEngineSoundPlayer BgmPlayer;
	float4 MoveDir;
	GameEngineImage* ColMap_;
protected:

private:
	void ColMap();
	float Speed_;
	GameEngineRenderer* Actor;
	bool up;
	int down = 0;
	float Time = 400;
	float Time_;
	bool DownFirst_ = true;
	void HitBlock();
	void Start() override;
	void Update() override;
};

