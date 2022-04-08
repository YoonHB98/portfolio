#include "Coin.h"

Coin::Coin() 
{
}

Coin::~Coin() 
{
}

void Coin::CreateCoin(const float4& _Pivot)
{
	{
		float4 Pivot = _Pivot;
		float4 CoPivot = Pivot;
		CoPivot.y = Pivot.y + 36;

		SetPosition(Pivot);
	}
}

void Coin::Start()
{
	//Actor->SetPosition(Pivot);
	//Actor->CreateCollision("Coin", { 80, 10 }, CoPivot);
	CoinCollision = CreateCollision("Coin", { 80, 1 }, { 0, 40 });

	CreateRenderer("Coin.bmp");

	//
	/*Image_ = CreateRenderer();*/
}

void Coin::Update()
{


	if (up == 1)
	{
		Time_ = Time_ + GameEngineTime::GetDeltaTime();
		SetMove(float4::UP * GameEngineTime::GetDeltaTime() * 800.0f);
		if (Time_ > 0.15f)
		{
			Time_ = 0.0f;
			up = 0;
			down = 1;
		}
		return;
	}
	if (down == 1)
	{
		Time_ = Time_ + GameEngineTime::GetDeltaTime();
		SetMove(float4::DOWN * GameEngineTime::GetDeltaTime() * 800.0f);
		if (Time_ > 0.1f)
		{
			Time_ = 0.0f;
			down = 0;
		}
		return;
	}


	if (true == CoinCollision->CollisionCheck("PlayerHitBox", CollisionType::Rect, CollisionType::Rect))
	{
		up = 1;
		Death(0.25f);
		Sound = GameEngineSound::SoundPlayControl("coin.wav");
	}
}