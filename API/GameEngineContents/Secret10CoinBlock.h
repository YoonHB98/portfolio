#pragma once
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineCollision.h>
#include <GameEngine/GameEngineLevel.h>


// Ό³Έν :


class Secret10CoinBlock : public GameEngineActor
{
public:
	// constrcuter destructer
	Secret10CoinBlock();
	~Secret10CoinBlock();

	// delete Function
	Secret10CoinBlock(const Secret10CoinBlock& _Other) = delete;
	Secret10CoinBlock(Secret10CoinBlock&& _Other) noexcept = delete;
	Secret10CoinBlock& operator=(const Secret10CoinBlock& _Other) = delete;
	Secret10CoinBlock& operator=(Secret10CoinBlock&& _Other) noexcept = delete;
	GameEngineCollision* BlockCollision;
	void CreateSecret10CoinBlock(const float4& _Pivot);
protected:

private:
	int up = 0;
	int down = 0;
	float Time_ = 0;
	int Count = 10;
	GameEngineRenderer* Actor;
	void Start() override;
	void Update() override;
	void Render() override;

};

