#pragma once
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineCollision.h>
#include <GameEngine/GameEngineLevel.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineSound.h>

// Ό³Έν :
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
	GameEngineSoundPlayer Hit;
protected:

private:
	GameEngineRenderer* Actor;
	bool up ;
	int down = 0;
	float Time_;
	void HitBlock();
	void Start() override;
	void Update() override;
};

