#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineImage.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineCollision.h>
#include <GameEngineBase/GameEngineMath.h>


// Ό³Έν :


class Tie : public GameEngineActor
{
public:
	// constrcuter destructer
	Tie();
	~Tie();

	// delete Function
	Tie(const Tie& _Other) = delete;
	Tie(Tie&& _Other) noexcept = delete;
	Tie& operator=(const Tie& _Other) = delete;
	Tie& operator=(Tie&& _Other) noexcept = delete;
	GameEngineCollision* TieCollision;
protected:

private:
	void Start() override;
	void Update() override;
	GameEngineRenderer* Actor;


};

