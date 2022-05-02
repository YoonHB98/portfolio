#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineImage.h>
#include <GameEngine/GameEngineRenderer.h>



// Ό³Έν :


class Text1 : public GameEngineActor
{
public:
	// constrcuter destructer
	Text1();
	~Text1();

	// delete Function
	Text1(const Text1& _Other) = delete;
	Text1(Text1&& _Other) noexcept = delete;
	Text1& operator=(const Text1& _Other) = delete;
	Text1& operator=(Text1&& _Other) noexcept = delete;
protected:

private:
	void Start() override;
	void Update() override;
	GameEngineRenderer* Actor;


};

