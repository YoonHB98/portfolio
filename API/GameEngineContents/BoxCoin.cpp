#include "BoxCoin.h"
#include "Point100.h"

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
	

	//
	/*Image_ = CreateRenderer();*/
}

void BoxCoin::Update()
{


	if (up == 1)
	{
		Time_ = Time_ + GameEngineTime::GetDeltaTime();
		SetMove(float4::UP * GameEngineTime::GetDeltaTime() * 1200.0f);
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
		Point100* Ptr = GetLevel()->CreateActor<Point100>(2);
		Ptr->SetPosition(GetPosition());
	}
}
