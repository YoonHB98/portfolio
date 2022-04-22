#pragma once
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineCollision.h>
#include <GameEngine/GameEngineLevel.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>


// Ό³Έν :
class SecretBlockmushroom : public GameEngineActor
{
public:
	// constrcuter destructer
	SecretBlockmushroom();
	~SecretBlockmushroom();

	// delete Function
	SecretBlockmushroom(const SecretBlockmushroom& _Other) = delete;
	SecretBlockmushroom(SecretBlockmushroom&& _Other) noexcept = delete;
	SecretBlockmushroom& operator=(const SecretBlockmushroom& _Other) = delete;
	SecretBlockmushroom& operator=(SecretBlockmushroom&& _Other) noexcept = delete;
	GameEngineCollision* BlockCollision;
	void CreateSecretBlockmushroom(const float4& _Pivot);
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

