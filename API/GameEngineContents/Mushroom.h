#pragma once
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineCollision.h>
#include <GameEngine/GameEngineLevel.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineSound.h>
#include <GameEngineContents/Point.h>


class Mushroom : public GameEngineActor
{
public:
	// constrcuter destructer
	Mushroom();
	~Mushroom();

	// delete Function
	Mushroom(const Mushroom& _Other) = delete;
	Mushroom(Mushroom&& _Other) noexcept = delete;
	Mushroom& operator=(const Mushroom& _Other) = delete;
	Mushroom& operator=(Mushroom&& _Other) noexcept = delete;

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

