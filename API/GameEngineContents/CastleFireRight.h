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


class CastleFireRight : public GameEngineActor
{
public:
	// constrcuter destructer
	CastleFireRight();
	~CastleFireRight();

	// delete Function
	CastleFireRight(const CastleFireRight& _Other) = delete;
	CastleFireRight(CastleFireRight&& _Other) noexcept = delete;
	CastleFireRight& operator=(const CastleFireRight& _Other) = delete;
	CastleFireRight& operator=(CastleFireRight&& _Other) noexcept = delete;
	GameEngineCollision* CheckCollision;
	GameEngineCollision* CastleFireRightCollision;
	void CreateCastleFireRight(const float4& _Pivot, const float4& _Angle);
	bool CheckFirst = true;
protected:

private:
	float4 MoveDir;
	float Speed_;
	void Start() override;
	void Update() override;
	GameEngineRenderer* Actor;


};

