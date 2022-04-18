#include "SecretBlock.h"

SecretBlock::SecretBlock() 
{
}

SecretBlock::~SecretBlock() 
{
}

void SecretBlock::CreateSecretBlock(const float4& _Pivot)
{
	{
		float4 Pivot = _Pivot;
		float4 CoPivot = Pivot;
		CoPivot.y = Pivot.y + 36;

		SetPosition(Pivot);
	}
}

void SecretBlock::Start()
{
	BlockCollision = CreateCollision("Block", { 80, 1 }, { 0, 40 });
}

void SecretBlock::Update()
{

	if (up
		&& first)
	{
		Actor = CreateRenderer("QuestionBlock.bmp");
		Actor->SetIndex(0);
		Actor->CreateAnimation("QuestionBlock.bmp", "HitBlock", 4, 4, 0.15f, false);
		Actor->ChangeAnimation("HitBlock");
		up = false;
		first = false;
	}
	if (up)
	{
		Time_ = Time_ + GameEngineTime::GetDeltaTime();
		SetMove(float4::UP * GameEngineTime::GetDeltaTime() * 200.0f);
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
		SetMove(float4::DOWN * GameEngineTime::GetDeltaTime() * 200.0f);
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
