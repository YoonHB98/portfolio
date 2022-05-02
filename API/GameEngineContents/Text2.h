#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineImage.h>
#include <GameEngine/GameEngineRenderer.h>



// Ό³Έν :


class Text2 : public GameEngineActor
{
public:
	// constrcuter destructer
	Text2();
	~Text2();

	// delete Function
	Text2(const Text2& _Other) = delete;
	Text2(Text2&& _Other) noexcept = delete;
	Text2& operator=(const Text2& _Other) = delete;
	Text2& operator=(Text2&& _Other) noexcept = delete;
protected:

private:
	void Start() override;
	void Update() override;
	GameEngineRenderer* Actor;


};

