#include "Bullet.h"
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineCollision.h>
#include "Player.h"
#include "WorldCount.h"


Bullet::Bullet()
{

}

Bullet::~Bullet()
{

}

void Bullet::Start()
{
	DeathTime = DeathTime + GameEngineTime::GetDeltaTime();
	Actor = CreateRenderer();
	Actor->CreateAnimation("Bullet.bmp", "Bullet", 0, 3, 0.2f, true);
	Actor->CreateAnimation("Boom.bmp", "Boom", 0, 2, 0.1f, false);
	Actor->ChangeAnimation("Bullet");
	BulletCollision = CreateCollision("Bullet", { 20, 20 }, {0, 0});
	BulletDown = CreateCollision("Bullet", { 2, 2 }, { 0, 10 });
	BulletLeft = CreateCollision("Bullet", { 2, 2 }, { -10, 0 });
	BulletRight = CreateCollision("Bullet", { 2, 2 }, { 10, 0 });

	

	YDir_ = float4::DOWN * 30.0f;
	BulletDir_ = {1, 0};
	XSpeed = 600.0f;
	YSpeed = 300.0f;
	DownSpeed = 1200.0f;
}
void Bullet::Update()
{
	ColMap();
	float4 ResultDir = float4::ZERO;
	ResultDir += BulletDir_ * GameEngineTime::GetDeltaTime() * XSpeed;
	ResultDir += YDir_ * GameEngineTime::GetDeltaTime();
	SetMove(ResultDir);
	DeathTime = DeathTime + GameEngineTime::GetDeltaTime();
	YDir_ += float4::DOWN * GameEngineTime::GetDeltaTime() * DownSpeed;

	int Color = ColMap_->GetImagePixel(GetPosition() + float4{0, 10.0f});
	int ColorRight = ColMap_->GetImagePixel(GetPosition() + float4{ 10.0f, 0.0f });
	int ColorLeft = ColMap_->GetImagePixel(GetPosition() + float4{ -10.0f, 0.0f });
	if (RGB(255, 255, 255) != Color || true == BulletDown->CollisionCheck("Move", CollisionType::Rect, CollisionType::Rect))
	{
		YDir_ = float4::UP * YSpeed;
	}
	if (RGB(0, 0, 0) == ColorRight || RGB(0, 0, 0) == ColorLeft || RGB(0, 0, 0) == ColorRight
		|| true == BulletRight->CollisionCheck("Move", CollisionType::Rect, CollisionType::Rect)
		|| true == BulletLeft->CollisionCheck("Move", CollisionType::Rect, CollisionType::Rect))
	{
		if (DeathCheck)
		{
			YDir_ = float4::ZERO;
			XSpeed = 0.0f;
			YSpeed = 0.0f;
			DownSpeed = 0.0f;
			Actor->ChangeAnimation("Boom");
			DeathTime = 3.5f;
			DeathCheck = false;
		}

	}
	if (DeathTime > 4.0f)
	{
		Death();
	}
}

void Bullet::ColMap()
{
	if (WorldCount::WorldCountUI == 1)
	{
		ColMap_ = GameEngineImageManager::GetInst()->Find("11mapWhite.bmp");
	}
	if (WorldCount::WorldCountUI == 2)
	{
		ColMap_ = GameEngineImageManager::GetInst()->Find("11mapWhite.bmp");
	}
	if (WorldCount::WorldCountUI == 3)
	{
		ColMap_ = GameEngineImageManager::GetInst()->Find("11mapWhite.bmp");
	}
	if (WorldCount::WorldCountUI == 4)
	{
		ColMap_ = GameEngineImageManager::GetInst()->Find("11mapWhite.bmp");
	}
}
