#include "Turtle.h"
#include <GameEngineBase/GameEngineSound.h>
#include "Point100.h"
#include "Pause.h"
#include "TurtleDead.h"



Turtle::Turtle() 
	:Speed_(50.0f)
{
}

Turtle::~Turtle() 
{
}

void Turtle::CreateTurtle(const float4& _Pivot)
{
	{
		float4 Pivot = _Pivot;
		float4 CoPivot = Pivot;
		CoPivot.y = Pivot.y + 36;
		SetPosition(Pivot);
		
		Actor = CreateRenderer("Turtle.bmp");
		Actor->SetIndex(0);
		Actor->CreateAnimation("Turtle.bmp", "TurtleR", 3,4, 0.2f, true);
		Actor->CreateAnimation("Turtle.bmp", "TurtleL", 1, 2, 0.2f, true);
		Actor->CreateAnimation("Turtle.bmp", "Death", 0, 0, 0.2f, true);
		Actor->ChangeAnimation("TurtleL");


	}
}


void Turtle::Start()
{
	TurtleCollision = CreateCollision("MonsterTop", { 40, 5 }, { 0, -30 });
	RightCollision = CreateCollision("MonsterRight", { 5,40 }, { 20, 0 });
	LeftCollision = CreateCollision("MonsterLeft", { 5, 40 }, { -20, 0 });
	CheckCollision = CreateCollision("CheckPos", { 40, 2400 }, { -620, 30 });
	MoveDir = float4::LEFT;
}

void Turtle::Update()
{
	if (Pause::pause
		||Pause::end
		||Pause::death)
	{
		Actor->PauseOn();
		return;
	}
	Actor->PauseOff();
	ColMap_ = GameEngineImageManager::GetInst()->Find("11mapWhite.bmp");
	float4 NextPos = GetPosition() + (MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
	float4 CheckPos = NextPos - float4(0.0f, 30.0f);
	CheckPos = CheckPos + MoveDir * float4(20.0f, 1.0f, 1.0f, 1.0f);
	float4 LeftBot = GetPosition() - float4{-20, -30}; 
	int Color = ColMap_->GetImagePixel(CheckPos);
	int ColorLeftBot = ColMap_->GetImagePixel(LeftBot);


	if (RGB(255, 255, 255) == Color)
	{
		if (up == 1)
		{
			SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		}
		
	}
	if (RGB(255, 255, 255) == ColorLeftBot)
	{
		if (up == 1)
		{
			MoveDir += float4{0, 1.0f};
			if (MoveDir.y > 1.0f)
			{
				MoveDir.y = 1.0f;
			}
			SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		}

	}
	if (RGB(255, 255, 255) != ColorLeftBot)
	{
		MoveDir.y = 0.0f;
	}
	if (RGB(255, 255, 255) == Color)
	{
		if (up == 1)
		{
			SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		}

	}
	if (RGB(255, 255, 255) != Color)
	{
		MoveDir = MoveDir * float4{ -1 , -1 };
		if (RGB(255, 255, 255) == Color)
		{
				SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
				if (MoveDir.x > 0.0f)
				{
					Actor->ChangeAnimation("TurtleR");
				}
				else
				{
					Actor->ChangeAnimation("TurtleL");
				}
		}
	}
	if (true == RightCollision->CollisionCheck("MonsterLeft", CollisionType::Rect, CollisionType::Rect))
	{
		MoveDir = MoveDir * float4{ -1 , -1 };
		if (MoveDir.x > 0.0f)
		{
			Actor->ChangeAnimation("TurtleR");
		}
		else
		{
			Actor->ChangeAnimation("TurtleL");
		}
		if (RGB(255, 255, 255) == Color)
		{
			SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		}
	}
	if (true == LeftCollision->CollisionCheck("MonsterRight", CollisionType::Rect, CollisionType::Rect))
	{
		MoveDir = MoveDir * float4{ -1 , -1 };
		if (MoveDir.x > 0.0f)
		{
			Actor->ChangeAnimation("TurtleR");
		}
		else
		{
			Actor->ChangeAnimation("TurtleL");
		}
		if (RGB(255, 255, 255) == Color)
		{
			int a = 0;
			SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		}
	}

	if (true == CheckCollision->CollisionCheck("PlayerHitBox", CollisionType::Rect, CollisionType::Rect))
	{
		up = 1;
	}
	if (true == TurtleCollision->CollisionCheck("PlayerBot", CollisionType::Rect, CollisionType::Rect)
	&& DeathFirst)
	{
		DeathFirst = false;
		Actor->ChangeAnimation("Death");
		MoveDir = float4::ZERO;
		GameEngineSound::SoundPlayOneShot("stomp.wav");
		if (DeathCount == false)
		{
			TurtleDead* Ptr = GetLevel()->CreateActor<TurtleDead>(2);
			Ptr->SetPosition(GetPosition());
			Point::PointUI = Point::PointUI + 100;
			DeathCount = true;
		}
		Death();
	}
	if (RGB(0, 0, 255) != ColorLeftBot
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

