#include "QuestionBlock.h"

QuestionBlock::QuestionBlock() 
{
}

QuestionBlock::~QuestionBlock() 
{
}

void QuestionBlock::CreateQuestionBlock(const float4& _Pivot)
{
	{
		float4 Pivot = _Pivot;
		float4 CoPivot = Pivot;
		CoPivot.y = Pivot.y + 36;

		SetPosition(Pivot);
	}
}

void QuestionBlock::Start()
{
	BlockCollision = CreateCollision("Block", { 80, 1 }, { 0, 40 });
	Actor = CreateRenderer("QuestionBlock.bmp");
	Actor->SetIndex(0);
	Actor->CreateAnimation("QuestionBlock.bmp", "Block", 0, 2, 0.15f, true);
	Actor->CreateAnimation("QuestionBlock.bmp", "HitBlock", 3, 3, 0.1f, true);
	Actor->ChangeAnimation("Block");

	
}

void QuestionBlock::Update()
{
	if (up == 1)
	{
		Time_ = Time_ + GameEngineTime::GetDeltaTime();
		SetMove(float4::UP * GameEngineTime::GetDeltaTime() * 200.0f);
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
		up = 1;
		Actor->ChangeAnimation("HitBlock");
	}
}
