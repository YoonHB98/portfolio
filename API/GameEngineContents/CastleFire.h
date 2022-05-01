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


class CastleFire : public GameEngineActor
{
public:
	// constrcuter destructer
	CastleFire();
	~CastleFire();

	// delete Function
	CastleFire(const CastleFire& _Other) = delete;
	CastleFire(CastleFire&& _Other) noexcept = delete;
	CastleFire& operator=(const CastleFire& _Other) = delete;
	CastleFire& operator=(CastleFire&& _Other) noexcept = delete;
	GameEngineCollision* CheckCollision;
	GameEngineCollision* CastleFireCollision;
	void CreateCastleFire(const float4& _Pivot, const float4& _Angle);
protected:

private:
	float4 MoveDir;
	float Speed_;
	void Start() override;
	void Update() override;
	GameEngineRenderer* Actor;
	bool CheckFirst = true;

};

