#include "UpMushroom.h"
#include "Point200.h"
#include "Point.h"
#include "Coin.h"
#include "Sound.h"
#include "Pause.h"


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
	//Actor->SetPosition(Pivot);
	//Actor->CreateCollision("UpMushroom", { 80, 10 }, CoPivot);
	UpMushroomCollision = CreateCollision("UpMushroom", { 40, 1 }, { 0, 20 });

	Actor = CreateRenderer("UpMushroom.bmp");

	
	Time_ = 400;
	//
	/*Image_ = CreateRenderer();*/
	


}

void UpMushroom::Update()
{
	if (Pause::pause
		||Pause::death
		||Pause::end)
	{
		return;
	}

	Time_ = Time_ - GameEngineTime::GetDeltaTime();

	if (up == 1)
	{
		
		SetMove(float4::UP * GameEngineTime::GetDeltaTime() * 27.0f);
		if (Time_< 3.5f)
		{
			
			up = 0;
			down = 1;
			Point::PointUI = Point::PointUI + 200;
			Coin::CoinUI = Coin::CoinUI + 1;
		}
		return;
	}
	if (down == 1)
	{
		//SetMove(float4::DOWN * GameEngineTime::GetDeltaTime() * 600.0f);
		if (Time_ > 0.1f)
		{
			Time_ = 0.0f;
			down = 0;
			
		}
		return;
	}


	if (true == UpMushroomCollision->CollisionCheck("PlayerHitBox", CollisionType::Rect, CollisionType::Rect))
	{
		up = 1;
		Time_ = 5.0f;
		GameEngineSound::SoundPlayOneShot("mushroomeat.wav", 0);
	}
	
}
