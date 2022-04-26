#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngine/GameEngineImage.h>

class Bullet : public GameEngineActor
{
public:
	Bullet();
	~Bullet();

	Bullet(const Bullet& _Other) = delete;
	Bullet(Bullet&& _Other) noexcept = delete;
	Bullet& operator=(const Bullet& _Other) = delete;
	Bullet& operator=(Bullet&& _Other) noexcept = delete;

	float Time;

	float4 SetDir(float4 Dir_)
	{
		BulletDir_ = Dir_;
		return BulletDir_;
	}

protected:

private:
	float DeathTime = 0;
	bool DeathCheck = true;
	GameEngineImage* ColMap_;
	GameEngineCollision* BulletCollision;
	GameEngineCollision* BulletDown;
	GameEngineCollision* BulletLeft;
	GameEngineCollision* BulletRight;
	GameEngineRenderer* Actor;
	void Start() override;
	void Update() override;
	void ColMap();
	float XSpeed;
	float YSpeed;
	float DownSpeed;
	float4 BulletDir_;
	float4 YDir_;
	float4 ResultDir_;
};

