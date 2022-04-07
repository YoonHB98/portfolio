#pragma once
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineCollision.h>
#include <GameEngine/GameEngineLevel.h>
// Ό³Έν :
class Coin : public GameEngineActor
{
public:
	// constrcuter destructer
	Coin();
	~Coin();

	// delete Function
	Coin(const Coin& _Other) = delete;
	Coin(Coin&& _Other) noexcept = delete;
	Coin& operator=(const Coin& _Other) = delete;
	Coin& operator=(Coin&& _Other) noexcept = delete;

	GameEngineCollision* CoinCollision;
	void CreateCoin(const float4& _Pivot);
protected:

private:
	int up = 0;
	int down = 0;
	float Time_ = 0;
	void Start() override;
	void Update() override;
};

