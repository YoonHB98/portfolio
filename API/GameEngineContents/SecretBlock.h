#pragma once
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineCollision.h>
#include <GameEngine/GameEngineLevel.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>


// Ό³Έν :
class SecretBlock : public GameEngineActor
{
public:
	// constrcuter destructer
	SecretBlock();
	~SecretBlock();

	// delete Function
	SecretBlock(const SecretBlock& _Other) = delete;
	SecretBlock(SecretBlock&& _Other) noexcept = delete;
	SecretBlock& operator=(const SecretBlock& _Other) = delete;
	SecretBlock& operator=(SecretBlock&& _Other) noexcept = delete;
	GameEngineCollision* BlockCollision;
	void CreateSecretBlock(const float4& _Pivot);
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

