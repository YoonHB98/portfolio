#include "Secret10CoinBlock.h"
#include "BoxCoin.h"



Secret10CoinBlock::Secret10CoinBlock() 
{
}

Secret10CoinBlock::~Secret10CoinBlock() 
{
}

void Secret10CoinBlock::CreateSecret10CoinBlock(const float4& _Pivot)
{
	{
		float4 Pivot = _Pivot;
		float4 CoPivot = Pivot;
		CoPivot.y = Pivot.y + 18;
		
		SetPosition(Pivot);
	}
}

void Secret10CoinBlock::Start()
{
	//Actor->SetPosition(Pivot);
	//Actor->CreateCollision("Secret10CoinBlock", { 80, 10 }, CoPivot);
	BlockCollision = CreateCollision("Block", { 40, 1 }, { 0, 20 });

	Actor = CreateRenderer("Block.bmp");
	Actor->CreateAnimation("SecretCoinBlock.bmp", "Block", 0, 0, 0.1f, false);
	Actor->CreateAnimation("SecretCoinBlock.bmp", "Hit", 1, 1, 0.1f, false);
	Actor->ChangeAnimation("Block");
	
	//
	/*Image_ = CreateRenderer();*/
}

void Secret10CoinBlock::Update()
{
	
	if (Count == 0)
	{
		Actor->ChangeAnimation("Hit");
		return;
	}
	if (up == 1)
	{
		Time_ = Time_ + GameEngineTime::GetDeltaTime();
		SetMove(float4::UP * GameEngineTime::GetDeltaTime() * 100.0f);
		if (Time_ > 0.2f)
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
		SetMove(float4::DOWN * GameEngineTime::GetDeltaTime() * 100.0f);
		if (Time_ > 0.2f)
		{
			Time_ = 0.0f;
			down = 0;
		}
		return;
	}


	if (true == BlockCollision->CollisionCheck("PlayerHitBox", CollisionType::Rect, CollisionType::Rect))
{
		BoxCoin* Ptr = GetLevel()->CreateActor<BoxCoin>(1);
		Ptr->CreateBoxCoin(float4{ 3780, 380 });
		up = 1;
		Count = Count - 1;
}
}

void Secret10CoinBlock::Render()
{
}

