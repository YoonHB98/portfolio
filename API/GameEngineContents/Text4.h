#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineImage.h>
#include <GameEngine/GameEngineRenderer.h>



// Ό³Έν :


class Text4 : public GameEngineActor
{
public:
	// constrcuter destructer
	Text4();
	~Text4();

	// delete Function
	Text4(const Text4& _Other) = delete;
	Text4(Text4&& _Other) noexcept = delete;
	Text4& operator=(const Text4& _Other) = delete;
	Text4& operator=(Text4&& _Other) noexcept = delete;
protected:

private:
	void Start() override;
	void Update() override;
	GameEngineRenderer* Actor;


};

