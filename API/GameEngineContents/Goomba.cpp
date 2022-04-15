#include "Goomba.h"
#include <GameEngineBase/GameEngineSound.h>
#include "Point100.h"
#include "Pause.h"



Goomba::Goomba() 
	:Speed_(100.0f)
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


void Goomba::Start()
{
	GoombaCollision = CreateCollision("Goomba", { 40, 5 }, { 0, -20 });
	RightCollision = CreateCollision("Monster", { 5,40 }, { 20, 0 });
	LeftCollision = CreateCollision("Monster", { 5, 40 }, { -20, 0 });
	CheckCollision = CreateCollision("CheckPos", { 40, 1200 }, { -620, 20 });
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
	ColMap_ = GameEngineImageManager::GetInst()->Find("11mapWhite.bmp");
	float4 NextPos = GetPosition() + (MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
	float4 CheckPos = NextPos - float4(0.0f, 20.0f);
	CheckPos = CheckPos + MoveDir * float4(20.0f, 1.0f, 1.0f, 1.0f);
	int Color = ColMap_->GetImagePixel(CheckPos);

	if (RGB(255, 255, 255) != Color)
	{

		MoveDir = MoveDir * float4{ -1 , -1 };
	}
	if (RGB(255, 255, 255) == Color)
	{
		if (up == 1)
		{
			SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		}
		
	}

	if (true == CheckCollision->CollisionCheck("PlayerHitBox", CollisionType::Rect, CollisionType::Rect))
	{
		up = 1;
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
	if (true == RightCollision->CollisionCheck("Monster", CollisionType::Rect, CollisionType::Rect))
	{
		MoveDir = MoveDir * float4{ -1 , -1 };
	}
	if (true == LeftCollision->CollisionCheck("Monster", CollisionType::Rect, CollisionType::Rect))
	{
		MoveDir = MoveDir * float4{ -1 , -1 };
	}

}

