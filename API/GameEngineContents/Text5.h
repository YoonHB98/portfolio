#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineImage.h>
#include <GameEngine/GameEngineRenderer.h>



// Ό³Έν :


class Text5 : public GameEngineActor
{
public:
	// constrcuter destructer
	Text5();
	~Text5();

	// delete Function
	Text5(const Text5& _Other) = delete;
	Text5(Text5&& _Other) noexcept = delete;
	Text5& operator=(const Text5& _Other) = delete;
	Text5& operator=(Text5&& _Other) noexcept = delete;
protected:

private:
	void Start() override;
	void Update() override;
	GameEngineRenderer* Actor;


};

