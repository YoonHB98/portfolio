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
#include <GameEngineBase/GameEngineMath.h>
#include <Windows.h>



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
	static float Time_;
	void CameraPos();
	float Angle;
protected:

private:
	float EndTime_ = 0.0f;
	bool GameEnd = false;
	bool PipeDownFirst = true;
	bool PipeLeftFirst = true;
	float4 MoveDir;
	GameEngineRenderer* RenderRun;
	int Right;
	int Left;
	float Speed_;
	float AccSpeed_;
	float Gravity_;
	float AccGravity_;
	float JumpTime_ = 3.0f;
	bool FirstEnd_ = true;
	bool blank = false;
	void ColMap();
	void MapSize();
	float MapSizeX = 0;
	float MapSizeY = 0;
	bool CameraUnder = false;
	bool PosChange = true;
	GameEngineImage* ColMap_;
	GameEngineCollision* PlayerCollision;
	GameEngineCollision* PlayerRight_;
	GameEngineCollision* PlayerLeft_;
	GameEngineCollision* Down_;
	GameEngineCollision* Up_;
	GameEngineCollision* Move_;
	float nodie = 0;
	float nodiecount = 0;
	void Start() override;
	void Update() override;
	void Render() override;

	void HitBlock();
};

