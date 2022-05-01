#include "SecretBlockCoin.h"
#include "UpMushroom.h"
#include "BoxCoin.h"

SecretBlockCoin::SecretBlockCoin() 
{
}

SecretBlockCoin::~SecretBlockCoin() 
{
}

void SecretBlockCoin::CreateSecretBlockCoin(const float4& _Pivot)
{
	{
		float4 Pivot = _Pivot;
		float4 CoPivot = Pivot;
		CoPivot.y = Pivot.y + 18;

		SetPosition(Pivot);
	}
}

void SecretBlockCoin::Start()
{
	BlockCollision = CreateCollision("Block", { 40, 1 }, { 0, 20 });
	BlockCollision = CreateCollision("Move", { 40, 40 }, { 0, 0 });
}

void SecretBlockCoin::Update()
{

	if (up
		&& first)
	{
		Actor = CreateRenderer("QuestionBlockCastle.bmp");
		Actor->SetIndex(0);
		Actor->CreateAnimation("QuestionBlockCastle.bmp", "HitBlock", 4, 4, 0.15f, false);
		Actor->ChangeAnimation("HitBlock");
		BoxCoin* CoinActor = GetLevel()->CreateActor<BoxCoin>(1);
		CoinActor->CreateBoxCoin(GetPosition());
		up = false;
		first = false;
	}
	if (up)
	{
		Time_ = Time_ + GameEngineTime::GetDeltaTime();
		SetMove(float4::UP * GameEngineTime::GetDeltaTime() * 100.0f);
		if (Time_ > 0.2f)
		{
			Time_ = 0.0f;
			up = false;
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
		up = true;
	}
}
