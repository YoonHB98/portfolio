#include "SecretBlockmushroom.h"
#include "Mushroom2.h"
#include "Mushroom.h"
#include "Pause.h"
#include "Flower.h"

SecretBlockmushroom::SecretBlockmushroom() 
{
}

SecretBlockmushroom::~SecretBlockmushroom() 
{
}

void SecretBlockmushroom::CreateSecretBlockmushroom(const float4& _Pivot)
{
	{
		float4 Pivot = _Pivot;
		float4 CoPivot = Pivot;
		CoPivot.y = Pivot.y + 18;

		SetPosition(Pivot);
	}
}

void SecretBlockmushroom::Start()
{
	BlockCollision = CreateCollision("Block", { 40, 1 }, { 0, 20 });
	BlockCollision = CreateCollision("Move", { 40, 40 }, { 0, 0 });
	Actor = CreateRenderer("QuestionBlock.bmp");
	Actor->SetIndex(0);
	Actor->CreateAnimation("QuestionBlock.bmp", "Block", 0, 2, 0.15f, true);
	Actor->CreateAnimation("QuestionBlock.bmp", "HitBlock", 3, 3, 0.1f, false);
	Actor->ChangeAnimation("Block");
}

void SecretBlockmushroom::Update()
{


	if (up)
	{
		if (first)
		{

			if (Pause::PlayerStatus == "small")
			{
				Mushroom* CoinActor = GetLevel()->CreateActor<Mushroom>(1);
				CoinActor->CreateMushroom(GetPosition());
			}
			else
			{
				Flower* CoinActor = GetLevel()->CreateActor<Flower>(1);
				CoinActor->CreateFlower(GetPosition());
			}

			first = false;
		}
		Actor->ChangeAnimation("HitBlock");
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
