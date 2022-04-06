#include "Block.h"
#include <GameEngine/GameEngineLevel.h>
#include <GameEngine/GameEngineActor.h>

Block::Block() 
{
}

Block::~Block() 
{
}

void Block::CreateBlock(const float4& _Pivot)
{
	{
		float4 Pivot = _Pivot;
		float4 CoPivot = Pivot;
		CoPivot.y = Pivot.y + 36;
		
		SetPosition(Pivot);
	}
}

void Block::Start()
{
	//Actor->SetPosition(Pivot);
	//Actor->CreateCollision("Block", { 80, 10 }, CoPivot);
	BlockCollision = CreateCollision("Block", { 80, 1 }, { 0, 40 });

	CreateRenderer("Block.bmp");
	//
	/*Image_ = CreateRenderer();*/
}

void Block::Update()
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
	}


	if (true == BlockCollision->CollisionCheck("PlayerHitBox", CollisionType::Rect, CollisionType::Rect))
{
		
		up = 1;
}
}

