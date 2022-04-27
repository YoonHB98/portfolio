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


class GameEngineImage;
class BigPlayer : public GameEngineActor
{
public:
	// constrcuter destructer
	BigPlayer();
	~BigPlayer();

	// delete Function
	BigPlayer(const BigPlayer& _Other) = delete;
	BigPlayer(BigPlayer&& _Other) noexcept = delete;
	BigPlayer& operator=(const BigPlayer& _Other) = delete;
	BigPlayer& operator=(BigPlayer&& _Other) noexcept = delete;
	float GetCurrentPosition();
	static bool Change;
	static float Time_;
protected:

private:
	void CameraPos();
	void ColMap();

	float4 MoveDir;
	GameEngineRenderer* RenderRun;
	int Right;
	int Left;
	float Speed_;
	float AccSpeed_;
	float Gravity_;
	float AccGravity_;
	bool FirstEnd_ = true;
	bool blank = false;
	bool Changefirst = true;
	GameEngineImage* ColMap_;
	GameEngineCollision* BigPlayerCollision;
	GameEngineCollision* BigPlayerRight_;
	GameEngineCollision* BigPlayerLeft_;
	GameEngineCollision* Down_;
	GameEngineCollision* Up_;
	GameEngineCollision* Move_;
	float ChangeTime = 0;
	float AnimationTime_ = 0;
	void AnimationChange(const std::string &Name);
	bool flowerAnimation = true;
	void Start() override;
	void Update() override;
	void Render() override;
	std::string animation = "";
	void HitBlock();
	bool RightBotCheck();
	bool LeftBotCheck();
};

