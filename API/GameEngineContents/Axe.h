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


class Axe : public GameEngineActor
{
public:
	// constrcuter destructer
	Axe();
	~Axe();

	// delete Function
	Axe(const Axe& _Other) = delete;
	Axe(Axe&& _Other) noexcept = delete;
	Axe& operator=(const Axe& _Other) = delete;
	Axe& operator=(Axe&& _Other) noexcept = delete;
	GameEngineCollision* AxeCollision;
	void CreateAxe(const float4& _Pivot);
protected:

private:
	void Start() override;
	void Update() override;
	GameEngineRenderer* Actor;


};

