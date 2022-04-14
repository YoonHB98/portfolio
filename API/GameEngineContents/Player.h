#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineImage.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineCollision.h>
#include <Windows.h>


enum PlayerState
{
	Idle,
	Attck,
	Move,
	Max,
};

class GameEngineImage;
class Player : public GameEngineActor
{
public:
	// constrcuter destructer
	Player();
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;
	float GetCurrentPosition();
protected:

private:
	float4 MoveDir;
	GameEngineRenderer* RenderRun;
	int Right;
	int Left;
	float Speed_;
	float AccSpeed_;
	float Gravity_;
	float AccGravity_;
	GameEngineImage* WhiteMap_;
	GameEngineCollision* PlayerCollision;
	GameEngineCollision* PlayerRight_;
	GameEngineCollision* PlayerLeft_;
	float Time_ = 0;
	void Start() override;
	void Update() override;
	void Render() override;
	
	void HitBlock();
};

