#pragma once
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineCollision.h>
#include <GameEngine/GameEngineLevel.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineSound.h>
#include <GameEngineContents/Point.h>


class UpMushroom : public GameEngineActor
{
public:
	// constrcuter destructer
	UpMushroom();
	~UpMushroom();

	// delete Function
	UpMushroom(const UpMushroom& _Other) = delete;
	UpMushroom(UpMushroom&& _Other) noexcept = delete;
	UpMushroom& operator=(const UpMushroom& _Other) = delete;
	UpMushroom& operator=(UpMushroom&& _Other) noexcept = delete;

	GameEngineCollision* UpMushroomCollision;
	GameEngineCollision* UpMushroomHitBox;
	void CreateUpMushroom(const float4& _Pivot);
	GameEngineSoundPlayer BgmPlayer;
	float4 MoveDir;
	GameEngineImage* ColMap_;
protected:

private:
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

