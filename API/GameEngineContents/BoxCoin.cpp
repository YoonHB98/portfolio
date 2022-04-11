#include "BoxCoin.h"
#include "Point200.h"
#include "Point.h"
#include "Coin.h"
#include "Sound.h"


BoxCoin::BoxCoin()
{
}

BoxCoin::~BoxCoin()
{
}

void BoxCoin::CreateBoxCoin(const float4& _Pivot)
{
	{
		float4 Pivot = _Pivot;
		float4 CoPivot = Pivot;
		CoPivot.y = Pivot.y + 36;

		SetPosition(Pivot);
	}
}

void BoxCoin::Start()
{
	//Actor->SetPosition(Pivot);
	//Actor->CreateCollision("BoxCoin", { 80, 10 }, CoPivot);
	BoxCoinCollision = CreateCollision("BoxCoin", { 80, 1 }, { 0, 40 });

	Actor = CreateRenderer("BoxCoin.bmp");
	Actor->SetIndex(0);
	Actor->CreateAnimation("BoxCoin.bmp", "BoxCoin", 0, 2, 0.1f, true);
	Actor->ChangeAnimation("BoxCoin");
	
	Time_ = 400;
	//
	/*Image_ = CreateRenderer();*/
	


}

void BoxCoin::Update()
{
	Time -= GameEngineTime::GetDeltaTime();
	if (4.9 >= Time)
	{

	}
	Time_ = Time_ - GameEngineTime::GetDeltaTime();

	if (up == 1)
	{
		
		SetMove(float4::UP * GameEngineTime::GetDeltaTime() * 1200.0f);
		if (Time_ > 0.15f)
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
		Time_ = Time_ + GameEngineTime::GetDeltaTime();
		SetMove(float4::DOWN * GameEngineTime::GetDeltaTime() * 1200.0f);
		if (Time_ > 0.1f)
		{
			Time_ = 0.0f;
			down = 0;
			
		}
		return;
	}


	if (true == BoxCoinCollision->CollisionCheck("PlayerHitBox", CollisionType::Rect, CollisionType::Rect))
	{
		up = 1;
		Death(0.25f);
		Point200* Ptr = GetLevel()->CreateActor<Point200>(2);
		Ptr->SetPosition(GetPosition());
		Time = 5.0f;
		Sound::SoundPlay = "Coin";
	}
	
}
