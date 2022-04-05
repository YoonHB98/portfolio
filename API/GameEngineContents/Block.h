#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineImageManager.h>

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
	GameEngineRenderer* GetRenderer()
	{
		return Image_;
	}
protected:

private:
	void Start() override;
	void Update() override;

	GameEngineRenderer* Image_;
};

