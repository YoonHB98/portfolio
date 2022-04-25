#include "Block.h"
#include "Pause.h"
#include "BlockBreak.h"
#include <GameEngineBase/GameEngineSound.h>


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
	BlockCollision = CreateCollision("Block", { 40, 1 }, { 0, 20 });

	CreateRenderer("Block.bmp");
	
	//
	/*Image_ = CreateRenderer();*/
}

void Block::Update()
{
	
	if (Pause::pause)
	{
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
		up = 1;
}
	if (true == BlockCollision->CollisionCheck("BigPlayerHitBox", CollisionType::Rect, CollisionType::Rect))
	{
		GameEngineSound::SoundPlayOneShot("blockbreak.wav");
		BlockBreak* RightTop = GetLevel()->CreateActor<BlockBreak>();
		RightTop->SetPosition(GetPosition() + float4{ 20 , -20 });
		RightTop->Dir = (float4{ 150 , -200 });
		BlockBreak* LeftTop = GetLevel()->CreateActor<BlockBreak>();
		LeftTop->SetPosition(GetPosition() + float4{ -20 , -20 });
		LeftTop->Dir = (float4{ -150 , -200 });
		BlockBreak* RightBot = GetLevel()->CreateActor<BlockBreak>();
		RightBot->SetPosition(GetPosition() + float4{ 20 , 20 });
		RightBot->Dir = (float4{ 150 , -40 });
		BlockBreak* LeftBot = GetLevel()->CreateActor<BlockBreak>();
		LeftBot->SetPosition(GetPosition() + float4{ -20 , 20 });
		LeftBot->Dir = float4{ -150 , -40 };
		Death();

	}
}

void Block::Render()
{
}

