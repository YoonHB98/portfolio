#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineImage.h>
#include <GameEngine/GameEngineRenderer.h>



// Ό³Έν :


class Text3 : public GameEngineActor
{
public:
	// constrcuter destructer
	Text3();
	~Text3();

	// delete Function
	Text3(const Text3& _Other) = delete;
	Text3(Text3&& _Other) noexcept = delete;
	Text3& operator=(const Text3& _Other) = delete;
	Text3& operator=(Text3&& _Other) noexcept = delete;
protected:

private:
	void Start() override;
	void Update() override;
	GameEngineRenderer* Actor;


};

