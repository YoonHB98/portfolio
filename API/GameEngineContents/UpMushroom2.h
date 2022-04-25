#pragma once
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineCollision.h>
#include <GameEngine/GameEngineLevel.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineSound.h>
#include <GameEngineContents/Point.h>

//Áö»ó ¹ö¼¸

class UpMushroom2 : public GameEngineActor
{
public:
	// constrcuter destructer
	UpMushroom2();
	~UpMushroom2();

	// delete Function
	UpMushroom2(const UpMushroom2& _Other) = delete;
	UpMushroom2(UpMushroom2&& _Other) noexcept = delete;
	UpMushroom2& operator=(const UpMushroom2& _Other) = delete;
	UpMushroom2& operator=(UpMushroom2&& _Other) noexcept = delete;

	GameEngineCollision* UpMushroom2Collision;
	GameEngineCollision* UpMushroom2HitBox;
	void CreateUpMushroom2(const float4& _Pivot);
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

