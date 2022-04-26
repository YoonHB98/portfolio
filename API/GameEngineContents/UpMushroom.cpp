#include "UpMushroom.h"
#include "UP1.h"
#include "Point.h"
#include "Coin.h"
#include "Sound.h"
#include "Pause.h"
#include "Point100.h"
#include "LevelIntro.h"
#include "WorldCount.h"

UpMushroom::UpMushroom()
{
}

UpMushroom::~UpMushroom()
{
}

void UpMushroom::CreateUpMushroom(const float4& _Pivot)
{
	{
		float4 Pivot = _Pivot;
		float4 CoPivot = Pivot;
		CoPivot.y = Pivot.y + 18;

		SetPosition(Pivot);
	}
}

void UpMushroom::Start()
{

	UpMushroomCollision = CreateCollision("UpMushroom", { 40, 5 }, { 0, 20 });
	UpMushroomHitBox = CreateCollision("UpMushroom", { 40, 40 }, { 0, 0 });
	MushroomColor = CreateCollision("NNN", { 5, 5 }, { 20, 0 });
	MushroomDownColor = CreateCollision("NNN", { 5, 5 }, { -20, 19 });

	Actor = CreateRenderer("UpMushroom.bmp");

	
	Time_ = 400;
	Speed_ = 120;

	


}

void UpMushroom::Update()
{
	if (Pause::pause
		||Pause::death
		||Pause::end)
	{
		return;
	}

	ColMap();
	float4 NextPos = GetPosition() + float4{ 20, 0 } + (MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
	float4 CheckPos = NextPos;
	float4 CheckDown = NextPos + float4{ -20 , 19 };
	int Color = ColMap_->GetImagePixel(CheckPos);
	int ColorDown = ColMap_->GetImagePixel(CheckDown);

	Time_ = Time_ - GameEngineTime::GetDeltaTime();

	if (up == 1)
	{
		if (Time_ > 4.8f)
		{
			SetMove(float4::UP * GameEngineTime::GetDeltaTime() * 100.0f);
		}
		else
		{
			SetMove(float4::UP * GameEngineTime::GetDeltaTime() * 27.0f);
		}

		if (Time_ < 4.1f)
		{
			MoveDir = float4::RIGHT;
			up = 0;
			down = 1;
			Point::PointUI = Point::PointUI + 200;
		}
		return;
	}
	if (down == 1)
	{
		if (RGB(0, 0, 255) == ColorDown)
		{
			Death(0.2f);
		}
		if (true == UpMushroomHitBox->CollisionCheck("PlayerItem", CollisionType::Rect, CollisionType::Rect))
		{
			GameEngineSound::SoundPlayOneShot("mushroomeat.wav", 0);
			LevelIntro::DeathCount  +=  1;
			UP1* Actor = GetLevel()->CreateActor<UP1>(2);
			Actor->SetPosition(GetPosition());
			Death();
		}
		if (RGB(255, 255, 255) == ColorDown && true != MushroomDownColor->CollisionCheck("Move", CollisionType::Rect, CollisionType::Rect))
		{
			MoveDir = float4::RIGHT + float4::DOWN * 1.5;
		}
		if (RGB(255, 255, 255) != ColorDown || true == MushroomDownColor->CollisionCheck("Move", CollisionType::Rect, CollisionType::Rect))
		{
			MoveDir.y = 0.0f;
		}
		if (RGB(255, 255, 255) != Color)
		{
			MoveDir = MoveDir * float4{ -1, 1 };
			SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
			return;
		}
		if (RGB(255, 255, 255) == Color || true != MushroomDownColor->CollisionCheck("Move", CollisionType::Rect, CollisionType::Rect))
		{
			SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		}
		return;
	}


	if (true == UpMushroomCollision->CollisionCheck("PlayerHitBox", CollisionType::Rect, CollisionType::Rect))
	{
		up = 1;
		Time_ = 5.0f;
		GameEngineSound::SoundPlayOneShot("mushroomappear.wav", 0);
	}

	
}

void UpMushroom::ColMap()
{
	if (WorldCount::WorldCountUI == 1)
	{
		ColMap_ = GameEngineImageManager::GetInst()->Find("11mapWhite.bmp");
	}
	else if (WorldCount::WorldCountUI == 2)
	{
		ColMap_ = GameEngineImageManager::GetInst()->Find("12mapWhite.bmp");
	}
	else if (WorldCount::WorldCountUI == 3)
	{
		ColMap_ = GameEngineImageManager::GetInst()->Find("13mapWhite.bmp");
	}
	else if (WorldCount::WorldCountUI == 4)
	{
		ColMap_ = GameEngineImageManager::GetInst()->Find("14mapWhite.bmp");
	}

}
