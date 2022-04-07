#pragma once
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineCollision.h>
#include <GameEngine/GameEngineLevel.h>


// Ό³Έν :


class Block : public GameEngineActor
{
public:
	// constrcuter destructer
	Block();
	~Block();

	// delete Function
	Block(const Block& _Other) = delete;
	Block(Block&& _Other) noexcept = delete;
	Block& operator=(const Block& _Other) = delete;
	Block& operator=(Block&& _Other) noexcept = delete;
	GameEngineCollision* BlockCollision;
	void CreateBlock(const float4& _Pivot);
protected:

private:
	int up = 0;
	int down = 0;
	float Time_ = 0;
	void Start() override;
	void Update() override;

};

