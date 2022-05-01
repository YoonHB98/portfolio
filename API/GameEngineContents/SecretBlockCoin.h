#pragma once
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineCollision.h>
#include <GameEngine/GameEngineLevel.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>


// Ό³Έν :
class SecretBlockCoin : public GameEngineActor
{
public:
	// constrcuter destructer
	SecretBlockCoin();
	~SecretBlockCoin();

	// delete Function
	SecretBlockCoin(const SecretBlockCoin& _Other) = delete;
	SecretBlockCoin(SecretBlockCoin&& _Other) noexcept = delete;
	SecretBlockCoin& operator=(const SecretBlockCoin& _Other) = delete;
	SecretBlockCoin& operator=(SecretBlockCoin&& _Other) noexcept = delete;
	GameEngineCollision* BlockCollision;
	void CreateSecretBlockCoin(const float4& _Pivot);
protected:

private:
	bool up = false;
	bool first = true;
	int down = 0;
	float Time_ = 0;
	GameEngineRenderer* Actor;
	void Start() override;
	void Update() override;
};

