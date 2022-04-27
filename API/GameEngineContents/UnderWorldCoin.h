#pragma once
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineCollision.h>
#include <GameEngine/GameEngineLevel.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineSound.h>
#include <GameEngineContents/Point.h>


class UnderWorldCoin : public GameEngineActor
{
public:
	// constrcuter destructer
	UnderWorldCoin();
	~UnderWorldCoin();

	// delete Function
	UnderWorldCoin(const UnderWorldCoin& _Other) = delete;
	UnderWorldCoin(UnderWorldCoin&& _Other) noexcept = delete;
	UnderWorldCoin& operator=(const UnderWorldCoin& _Other) = delete;
	UnderWorldCoin& operator=(UnderWorldCoin&& _Other) noexcept = delete;

	GameEngineCollision* UnderWorldCoinCollision;
	GameEngineCollision* UnderWorldCoinHitBox;
	GameEngineCollision* UnderWorldCoinColor;
	GameEngineCollision* UnderWorldCoinDownColor;
	void CreateUnderWorldCoin(const float4& _Pivot);
	GameEngineSoundPlayer BgmPlayer;
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

