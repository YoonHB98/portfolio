#pragma once
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineCollision.h>
#include <GameEngine/GameEngineLevel.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineSound.h>
#include <GameEngineContents/Point.h>


class Mushroom2 : public GameEngineActor
{
public:
	// constrcuter destructer
	Mushroom2();
	~Mushroom2();

	// delete Function
	Mushroom2(const Mushroom2& _Other) = delete;
	Mushroom2(Mushroom2&& _Other) noexcept = delete;
	Mushroom2& operator=(const Mushroom2& _Other) = delete;
	Mushroom2& operator=(Mushroom2&& _Other) noexcept = delete;

	GameEngineCollision* MushroomCollision;
	GameEngineCollision* MushroomHitBox;
	void CreateMushroom(const float4& _Pivot);
	GameEngineSoundPlayer BgmPlayer;
	float4 MoveDir;
	GameEngineImage* ColMap_;
protected:

private:
	void ColMap();
	float Speed_;
	GameEngineRenderer* Actor;
	bool up ;
	int down = 0;
	float Time = 400;
	float Time_;
	bool DownFirst_ = true;
	void HitBlock();
	void Start() override;
	void Update() override;
};

