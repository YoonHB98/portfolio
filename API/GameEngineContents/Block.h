#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineCollision.h>
#include <GameEngine/GameEngineLevel.h>
#include <GameEngine/GameEngineActor.h>

// Ό³Έν :

class GameEngineRenderer;
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
	//inline GameEngineRenderer* GetRenderer()
	//{
	//	return Image_;
	//}
	void CreateBlock(const float4& _Pivot);
protected:

private:
	void Start() override;
	void Update() override;

	GameEngineRenderer* Image_;
};

