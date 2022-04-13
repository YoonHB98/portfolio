#include "Goomba.h"
#include <GameEngineBase/GameEngineSound.h>
#include "Point100.h"



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
	GoombaCollision = CreateCollision("Goomba", { 80, 5 }, { 0, -40 });
	RightCollision = CreateCollision("MonsterRight", { 5,80 }, { 40, 0 });
	LeftCollision = CreateCollision("MonsterLeft", { 5, 80 }, { -40, 0 });
	CheckCollision = CreateCollision("CheckPos", { 80, 1200 }, { -1280, 40 });
	MoveDir = float4::LEFT;
}

void Goomba::Update()
{
	ColMap_ = GameEngineImageManager::GetInst()->Find("11mapWhite.bmp");
	float4 NextPos = GetPosition() + (MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
	float4 CheckPos = NextPos - float4(0.0f, 40.0f);
	CheckPos = CheckPos + MoveDir * float4(40.0f, 1.0f, 1.0f, 1.0f);
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
	if (true == GoombaCollision->CollisionCheck("PlayerBot", CollisionType::Rect, CollisionType::Rect))
	{
		Actor->ChangeAnimation("Death");
		MoveDir = float4::ZERO;
		GameEngineSound::SoundPlayOneShot("stomp.wav");
		if (DeathCount == false)
		{
			Point100* Ptr = GetLevel()->CreateActor<Point100>(2);
			Ptr->SetPosition(GetPosition());
			DeathCount = true;
		}
		Death(0.5f);
	}
	if (true == RightCollision->CollisionCheck("MonsterLeft", CollisionType::Rect, CollisionType::Rect))
	{
		MoveDir = MoveDir * float4{ -1 , -1 };
	}
	if (true == LeftCollision->CollisionCheck("MonsterRight", CollisionType::Rect, CollisionType::Rect))
	{
		MoveDir = MoveDir * float4{ -1 , -1 };
	}

}

