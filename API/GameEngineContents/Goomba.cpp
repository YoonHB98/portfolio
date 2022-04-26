#include "Goomba.h"
#include <GameEngineBase/GameEngineSound.h>
#include "Point100.h"
#include "Pause.h"
#include "WorldCount.h"



Goomba::Goomba() 
	:Speed_(60.0f)
{
}

Goomba::~Goomba() 
{
}

void Goomba::CreateGoomba(const float4& _Pivot)
{
	{
		float4 Pivot = _Pivot;
		float4 CoPivot = Pivot;
		CoPivot.y = Pivot.y + 36;
		SetPosition(Pivot);
		
		Actor = CreateRenderer("Goomba.bmp");
		Actor->SetIndex(0);
		Actor->CreateAnimation("Goomba.bmp", "Goomba", 0,1, 0.2f, true);
		Actor->CreateAnimation("Goomba.bmp", "Death", 2, 2, 0.2f, true);
		Actor->ChangeAnimation("Goomba");


	}
}
void Goomba::ColMap()
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


void Goomba::Start()
{
	GoombaCollision = CreateCollision("MonsterTop", { 40, 5 }, { 0, -20 });
	RightCollision = CreateCollision("MonsterRight", { 5,30 }, { 20, 5 });
	LeftCollision = CreateCollision("MonsterLeft", { 5, 30 }, { -20, 5 });
	CheckCollision = CreateCollision("CheckPos", { 40, 2400 }, { -310, 20 });
	GoombaColor = CreateCollision("NNN", { 5, 5 }, { 20, 0 });
	GoombaDownColor = CreateCollision("NNN", { 5, 5 }, { 10, 19 });
	MoveDir = float4::LEFT;
}

void Goomba::Update()
{
	if (Pause::pause
		||Pause::end
		||Pause::death)
	{
		Actor->PauseOn();
		return;
	}
	Actor->PauseOff();
	ColMap();
	float4 NextPos = GetPosition() + (MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
	float4 CheckPos = NextPos - float4(0.0f, 20.0f);
	CheckPos = CheckPos + MoveDir * float4(20.0f, 1.0f, 1.0f, 1.0f);
	float4 LeftBot = GetPosition() - float4{-20, -20}; 
	int Color = ColMap_->GetImagePixel(CheckPos);
	int ColorLeftBot = ColMap_->GetImagePixel(LeftBot);


	if (RGB(255, 255, 255) == Color)
	{
		if (up == 1)
		{
			SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		}
		
	}
	if (RGB(255, 255, 255) == ColorLeftBot&& true != GoombaDownColor->CollisionCheck("Move", CollisionType::Rect, CollisionType::Rect))
	{
		if (up == 1)
		{
			MoveDir += float4{0, 4.0f};
			if (MoveDir.y > 4.0f)
			{
				MoveDir.y = 4.0f;
			}
			SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		}

	}
	if (RGB(255, 255, 255) != ColorLeftBot || true == GoombaDownColor->CollisionCheck("Move", CollisionType::Rect, CollisionType::Rect))
	{
		MoveDir.y = 0.0f;
	}
	if (RGB(255, 255, 255) == Color && true != GoombaColor->CollisionCheck("Move", CollisionType::Rect, CollisionType::Rect))
	{
		if (up == 1)
		{
			SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		}

	}
	if (RGB(255, 255, 255) != Color)
	{
		MoveDir = MoveDir * float4{ -1 , -1 };
		if (RGB(255, 255, 255) == Color && true != GoombaColor->CollisionCheck("Move", CollisionType::Rect, CollisionType::Rect))
		{
				SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		}
	}
	if (true == RightCollision->CollisionCheck("MonsterLeft", CollisionType::Rect, CollisionType::Rect))
	{
		MoveDir = MoveDir * float4{ -1 , -1 };
		if (RGB(255, 255, 255) == Color && true != GoombaColor->CollisionCheck("Move", CollisionType::Rect, CollisionType::Rect))
		{
			SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		}
	}
	if (true == LeftCollision->CollisionCheck("MonsterRight", CollisionType::Rect, CollisionType::Rect))
	{
		MoveDir = MoveDir * float4{ -1 , -1 };
		if (RGB(255, 255, 255) == Color && true != GoombaColor->CollisionCheck("Move", CollisionType::Rect, CollisionType::Rect))
		{
			int a = 0;
			SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		}
	}

	if (true == CheckCollision->CollisionCheck("PlayerHitBox", CollisionType::Rect, CollisionType::Rect))
	{
		up = 1;
	}
	if (true == GoombaCollision->CollisionCheck("Turtle", CollisionType::Rect, CollisionType::Rect)
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
	if (true == GoombaCollision->CollisionCheck("PlayerBot", CollisionType::Rect, CollisionType::Rect)
	&& DeathFirst)
	{
		DeathFirst = false;
		Actor->ChangeAnimation("Death");
		MoveDir = float4::ZERO;
		GameEngineSound::SoundPlayOneShot("stomp.wav");
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

