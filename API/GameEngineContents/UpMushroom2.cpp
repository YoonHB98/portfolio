#include "UpMushroom2.h"
#include "UP1.h"
#include "Point.h"
#include "Coin.h"
#include "Sound.h"
#include "Pause.h"
#include "Point100.h"
#include "LevelIntro.h"

UpMushroom2::UpMushroom2()
{
}

UpMushroom2::~UpMushroom2()
{
}

void UpMushroom2::CreateUpMushroom2(const float4& _Pivot)
{
	{
		float4 Pivot = _Pivot;
		float4 CoPivot = Pivot;
		CoPivot.y = Pivot.y + 18;

		SetPosition(Pivot);
	}
}

void UpMushroom2::Start()
{
	//Actor->SetPosition(Pivot);
	//Actor->CreateCollision("UpMushroom2", { 80, 10 }, CoPivot);
	UpMushroom2Collision = CreateCollision("UpMushroom", { 40, 5 }, { 0, 20 });
	UpMushroom2HitBox = CreateCollision("UpMushroom", { 40, 40 }, { 0, 0 });

	Actor = CreateRenderer("UpMushroom.bmp");

	
	Time_ = 400;
	Speed_ = 60;
	//
	/*Image_ = CreateRenderer();*/
	


}

void UpMushroom2::Update()
{
	if (Pause::pause
		||Pause::death
		||Pause::end)
	{
		return;
	}
	ColMap_ = GameEngineImageManager::GetInst()->Find("11mapWhite.bmp");
	float4 NextPos = GetPosition() + (MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
	float4 CheckPos = NextPos;
	float4 CheckDown = NextPos + float4{ 0 , 21};
	CheckPos = CheckPos + MoveDir * float4(20.0f, 1.0f, 1.0f, 1.0f);
	CheckDown = CheckDown + MoveDir * float4(20.0f, 1.0f, 1.0f, 1.0f);
	int Color = ColMap_->GetImagePixel(CheckPos);
	int ColorDown = ColMap_->GetImagePixel(CheckDown);

	Time_ = Time_ - GameEngineTime::GetDeltaTime();

	if (up == 1)
	{
		
		SetMove(float4::UP * GameEngineTime::GetDeltaTime() * 27.0f);
		if (Time_< 3.5f)
		{
			MoveDir = float4::RIGHT;
			up = 0;
			down = 1;
			Point::PointUI = Point::PointUI + 200;
			Coin::CoinUI = Coin::CoinUI + 1;
		}
		return;
	}
	if (down == 1)
	{
		if (RGB(0, 0, 255) == ColorDown)
		{
			Death();
		}
		if (true == UpMushroom2HitBox->CollisionCheck("PlayerItem", CollisionType::Rect, CollisionType::Rect))
		{
			GameEngineSound::SoundPlayOneShot("mushroomeat.wav", 0);
			LevelIntro::DeathCount + 1;
			UP1* Actor = GetLevel()->CreateActor<UP1>(2);
			Actor->SetPosition(GetPosition());
			Death();
		}
		if (RGB(255, 255, 255) == ColorDown
			&& DownFirst_)
		{
			MoveDir = float4::RIGHT + float4::DOWN;
			DownFirst_ = false;
		}

		if (RGB(255, 255, 255) != ColorDown)
		{
			MoveDir = MoveDir * float4{ 1, 0 };
		}
		if (RGB(255, 255, 255) != Color)
		{
			MoveDir = MoveDir * float4{ -1, 1 };
		}
		if (RGB(255, 255, 255) == Color)
		{
				SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		}
		return;
	}


	if (true == UpMushroom2Collision->CollisionCheck("PlayerHitBox", CollisionType::Rect, CollisionType::Rect))
	{
		up = 1;
		Time_ = 5.0f;
		GameEngineSound::SoundPlayOneShot("mushroomappear.wav", 0);
	}

	
}
