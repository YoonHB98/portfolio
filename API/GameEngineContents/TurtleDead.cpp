#include "TurtleDead.h"
#include <GameEngineBase/GameEngineSound.h>
#include "Point100.h"
#include "Pause.h"
#include "WorldCount.h"



TurtleDead::TurtleDead() 
	:Speed_(500.0f)
{
}

TurtleDead::~TurtleDead() 
{
}

void TurtleDead::Start()
{
	Actor = CreateRenderer("Turtle.bmp");
	Actor->SetIndex(0);
	Actor->CreateAnimation("Turtle.bmp", "Death", 0, 0, 0.2f, true);
	Actor->ChangeAnimation("Death");


	MoveDir = float4::ZERO;
}
void TurtleDead::ColMap()
{
	if (WorldCount::WorldCountUI == 1)
	{
		ColMap_ = GameEngineImageManager::GetInst()->Find("11mapWhite.bmp");
	}
	if (WorldCount::WorldCountUI == 2)
	{
		ColMap_ = GameEngineImageManager::GetInst()->Find("11mapWhite.bmp");
	}
	if (WorldCount::WorldCountUI == 3)
	{
		ColMap_ = GameEngineImageManager::GetInst()->Find("11mapWhite.bmp");
	}
	if (WorldCount::WorldCountUI == 4)
	{
		ColMap_ = GameEngineImageManager::GetInst()->Find("11mapWhite.bmp");
	}


}

void TurtleDead::Update()
{
	if (Pause::pause
		||Pause::end
		||Pause::death)
	{
		Actor->PauseOn();
		return;
	}
	Time_ = Time_ + GameEngineTime::GetDeltaTime();
	if (Time_ < 1.0f)
	{
		return;
	}
	if (Time_ >= 1.0f
		&&First)
	{
		TurtleDeadCollision = CreateCollision("MonsterTop", { 40, 5 }, { 0, -15 });
		RightCollision = CreateCollision("Turtle", { 20,42 }, { 10, 0 });
		LeftCollision = CreateCollision("Turtle", { 20, 42 }, { -10, 0 });
		First = false;
	}
	Actor->PauseOff();
	ColMap();
	float4 NextPos = GetPosition() + (MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
	float4 CheckPos = NextPos - float4(0.0f, 30.0f);
	CheckPos = CheckPos + MoveDir * float4(20.0f, 1.0f, 1.0f, 1.0f);
	float4 LeftBot = GetPosition() - float4{-20, -30}; 
	int Color = ColMap_->GetImagePixel(CheckPos);
	int ColorLeftBot = ColMap_->GetImagePixel(LeftBot);

	if (RGB(255, 255, 255) == ColorLeftBot)
	{
			MoveDir += float4{0, 1.0f};
			if (MoveDir.y > 1.0f)
			{
				MoveDir.y = 1.0f;
			}
			SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);

	}
	if (RGB(255, 255, 255) != ColorLeftBot)
	{
		MoveDir.y = 0.0f;
	}
	if (RGB(255, 255, 255) == Color)
	{
			SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);

	}
	if (RGB(255, 255, 255) != Color)
	{
		MoveDir = MoveDir * float4{ -1 , -1 };
		if (RGB(255, 255, 255) == Color)
		{
				SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);

		}
	}
	if (true == RightCollision->CollisionCheck("PlayerItem", CollisionType::Rect, CollisionType::Rect)
		|| true == RightCollision->CollisionCheck("PlayerBot", CollisionType::Rect, CollisionType::Rect))
	{
		if (DeathFirst)
		{
			MoveDir = float4::RIGHT;
			DeathFirst = false;
			TurtleDeadCollision = CreateCollision("MonsterLeft", { 1, 10 }, { -20, 0 });
			TurtleDeadCollision = CreateCollision("MonsterRight", { 1, 10 }, { 20, 0 });
			GameEngineSound::SoundPlayOneShot("stomp.wav");
		}

	}
	if (true == RightCollision->CollisionCheck("PlayerItem", CollisionType::Rect, CollisionType::Rect)
		|| true == RightCollision->CollisionCheck("PlayerBot", CollisionType::Rect, CollisionType::Rect))
	{
		if (DeathFirst)
		{
			MoveDir = float4::LEFT;
			DeathFirst = false;
			TurtleDeadCollision = CreateCollision("MonsterLeft", { 5, 10 }, { -20, 5 });
			TurtleDeadCollision = CreateCollision("MonsterRight", { 5, 10 }, { 20, 5 });
			GameEngineSound::SoundPlayOneShot("stomp.wav");
		}

	}

	if (RGB(0, 0, 255) == ColorLeftBot
		&& DeathFirst)
	{
		DeathFirst = false;
		Actor->ChangeAnimation("Death");
		MoveDir = float4::ZERO;
		if (DeathCount == false)
		{
			Point100* Ptr = GetLevel()->CreateActor<Point100>(2);
			Ptr->SetPosition(GetPosition());
			Point::PointUI = Point::PointUI + 100;
			DeathCount = true;
		}
		Death(0.25f);
	}



}

