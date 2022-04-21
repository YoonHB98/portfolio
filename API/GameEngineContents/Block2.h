#pragma once
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineCollision.h>
#include <GameEngine/GameEngineLevel.h>


// Ό³Έν :


class Block2 : public GameEngineActor
{
public:
	// constrcuter destructer
	Block2();
	~Block2();

	// delete Function
	Block2(const Block2& _Other) = delete;
	Block2(Block2&& _Other) noexcept = delete;
	Block2& operator=(const Block2& _Other) = delete;
	Block2& operator=(Block2&& _Other) noexcept = delete;
	GameEngineCollision* Block2Collision;
	void CreateBlock2(const float4& _Pivot);
protected:

private:
	int up = 0;
	int down = 0;
	float Time_ = 0;
	void Start() override;
	void Update() override;
	void Render() override;

};

