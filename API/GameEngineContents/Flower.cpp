#include "Flower.h"
#include "UP1.h"
#include "Point.h"
#include "Coin.h"
#include "Sound.h"
#include "Pause.h"
#include "Point100.h"
#include "LevelIntro.h"
#include "WorldCount.h"

Flower::Flower()
{
}

Flower::~Flower()
{
}

void Flower::CreateFlower(const float4& _Pivot)
{
	{
		float4 Pivot = _Pivot;
		float4 CoPivot = Pivot;
		CoPivot.y = Pivot.y + 18;

		SetPosition(Pivot);
	}
}

void Flower::Start()
{
	//Actor->SetPosition(Pivot);
	//Actor->CreateCollision("Flower", { 80, 10 }, CoPivot);
	FlowerHitBox = CreateCollision("Flower", { 40, 40 }, { 0, 0 });

	Actor = CreateRenderer("Flower.bmp");


	Time_ = 400;
	Speed_ = 60;
	//
	/*Image_ = CreateRenderer();*/



}

void Flower::Update()
{
	if (Pause::pause
		|| Pause::death
		|| Pause::end)
	{
		return;
	}
	ColMap();
	float4 NextPos = GetPosition() + float4{ 20, 0 } + (MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
	float4 CheckPos = NextPos;
	float4 CheckDown = NextPos + float4{ -20 , 19 };
	CheckPos = CheckPos;
	CheckDown = CheckDown;
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
			up = 0;
		}
		return;
	}
	if (true == FlowerHitBox->CollisionCheck("PlayerItem", CollisionType::Rect, CollisionType::Rect))
	{
		GameEngineSound::SoundPlayOneShot("Flowereat.wav", 0);
		if (Pause::PlayerStatus == "small")
		{
			Pause::PlayerStatus = "big";
			Pause::bigfirst = true;
		}
		else
			if (Pause::PlayerStatus == "big")
			{
				Pause::PlayerStatus = "fire";
			}
		Death();
	
		return;
	}


	if (true == FlowerCollision->CollisionCheck("PlayerHitBox", CollisionType::Rect, CollisionType::Rect))
	{
		up = 1;
		Time_ = 5.0f;
		GameEngineSound::SoundPlayOneShot("mushroomappear.wav", 0);
	}


}

void Flower::ColMap()
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
