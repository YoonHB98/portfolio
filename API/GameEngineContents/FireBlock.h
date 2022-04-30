#pragma once
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineCollision.h>
#include <GameEngine/GameEngineLevel.h>


// Ό³Έν :


class FireBlock : public GameEngineActor
{
public:
	// constrcuter destructer
	FireBlock();
	~FireBlock();

	// delete Function
	FireBlock(const FireBlock& _Other) = delete;
	FireBlock(FireBlock&& _Other) noexcept = delete;
	FireBlock& operator=(const FireBlock& _Other) = delete;
	FireBlock& operator=(FireBlock&& _Other) noexcept = delete;
	GameEngineCollision* CheckCollision;
protected:

private:
	bool Make = true;
	float Time_ = 0;
	void Start() override;
	void Update() override;

};

