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


class Bridge : public GameEngineActor
{
public:
	// constrcuter destructer
	Bridge();
	~Bridge();

	// delete Function
	Bridge(const Bridge& _Other) = delete;
	Bridge(Bridge&& _Other) noexcept = delete;
	Bridge& operator=(const Bridge& _Other) = delete;
	Bridge& operator=(Bridge&& _Other) noexcept = delete;
	GameEngineCollision* BridgeCollision;
	void D_();
protected:

private:

	void Start() override;
	void Update() override;
	GameEngineRenderer* Actor;


};

