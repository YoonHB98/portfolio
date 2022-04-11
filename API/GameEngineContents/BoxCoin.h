#pragma once
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineCollision.h>
#include <GameEngine/GameEngineLevel.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineSound.h>
#include <GameEngineContents/Point.h>


class BoxCoin : public GameEngineActor
{
public:
	// constrcuter destructer
	BoxCoin();
	~BoxCoin();

	// delete Function
	BoxCoin(const BoxCoin& _Other) = delete;
	BoxCoin(BoxCoin&& _Other) noexcept = delete;
	BoxCoin& operator=(const BoxCoin& _Other) = delete;
	BoxCoin& operator=(BoxCoin&& _Other) noexcept = delete;

	GameEngineCollision* BoxCoinCollision;
	void CreateBoxCoin(const float4& _Pivot);
	GameEngineSoundPlayer BgmPlayer;
protected:

private:
	GameEngineRenderer* Actor;
	bool up ;
	int down = 0;
	float Time = 400;
	float Time_;
	void HitBlock();
	void Start() override;
	void Update() override;
};

