#include "Koopa.h"
#include <GameEngineBase/GameEngineSound.h>
#include "Point100.h"
#include "Pause.h"
#include "WorldCount.h"
#include "CastleFire.h"
#include "CastleFireRight.h"
#include <random>
#include <ctime>
#include <iostream>
#include <functional>




Koopa::Koopa() 
	:Speed_(10.0f)
{
}

Koopa::~Koopa() 
{
}

void Koopa::CreateKoopa(const float4& _Pivot)
{
	{
		float4 Pivot = _Pivot;
		float4 CoPivot = Pivot;
		CoPivot.y = Pivot.y + 36;
		SetPosition(Pivot);
		
		Actor = CreateRenderer("Koopa.bmp");
		Actor->SetIndex(0);
		Actor->CreateAnimation("Koopa.bmp", "KoopaLeft", 0,3, 0.2f, true);
		Actor->CreateAnimation("Koopa.bmp", "KoopaRight", 4, 7, 0.2f, true);
		Actor->ChangeAnimation("KoopaLeft");


	}
}

int Koopa::Random(int _Min, int _Max)
{

	std::mt19937 engine((unsigned int)time(NULL));                 
	std::uniform_int_distribution<int> distribution(_Min, _Max);       
	auto generator = bind(distribution, engine);

	return generator();

}
void Koopa::ColMap()
{
	if (WorldCount::WorldCountUI == 1)
	{
		ColMap_ = GameEngineImageManager::GetInst()->Find("11mapWhite.bmp");
	}
	if (WorldCount::WorldCountUI == 2)
	{
		ColMap_ = GameEngineImageManager::GetInst()->Find("12mapWhite.bmp");
	}
	if (WorldCount::WorldCountUI == 3)
	{
		ColMap_ = GameEngineImageManager::GetInst()->Find("13mapWhite.bmp");
	}
	if (WorldCount::WorldCountUI == 4)
	{
		ColMap_ = GameEngineImageManager::GetInst()->Find("14mapWhite.bmp");
	}


}


void Koopa::Start()
{
	KoopaCollision = CreateCollision("MonsterRight", { 40, 40 }, { -20,-20 });
	KoopaCollision = CreateCollision("MonsterRight", { 60, 60 }, { 30, 30});
	CheckCollisionRight = CreateCollision("CheckPos", { 620, 2400 }, { 310, 20 });
	CheckCollisionLeft= CreateCollision("CheckPos", { 620, 2400 }, { -310, 20 });
	KoopaColor = CreateCollision("NNN", { 5, 5 }, { 20, 0 });
	KoopaDownColor = CreateCollision("NNN", { 5, 5 }, { 10, 19 });
	MoveDir = float4::LEFT;
}

void Koopa::Update()
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
	float4 CheckPos = NextPos - float4(0.0f, 40.0f);
	CheckPos = CheckPos + MoveDir * float4(40.0f, 1.0f, 1.0f, 1.0f);
	float4 LeftBot = GetPosition() - float4{-40, -40}; 
	int Color = ColMap_->GetImagePixel(CheckPos);
	int ColorLeftBot = ColMap_->GetImagePixel(LeftBot);

	if (up ==1)
	{
		Time_ = Time_ + GameEngineTime::GetDeltaTime();
		if (Time_ < 1.00f)
		{
			MoveDir.y = -5.0f;
		}
		else if (Time_ < 2.0f)
		{
			MoveDir.y = 5.0f;
		}
		else
		{
			MoveDir.y = 0.0f;
		}
		if (Time_ > 4.0f)
		{
			Time_ = 0.0f;
		}
		if (First_ && (Time_ > 0.8f && Time_ < 0.9f))
		{
			if (Actor->IsAnimationName("KoopaLeft"))
			{
				GameEngineSound::SoundPlayOneShot("Fire.wav");
				First_ = false;
				Second_ = true;
				CastleFire* Actor = GetLevel()->CreateActor<CastleFire>();
				Actor->SetPosition(GetPosition());
				Actor->CheckFirst = false;
			}
			else
			{
				GameEngineSound::SoundPlayOneShot("Fire.wav");
				First_ = false;
				Second_ = true;
				CastleFireRight* Actor = GetLevel()->CreateActor<CastleFireRight>();
				Actor->SetPosition(GetPosition());
				Actor->CheckFirst = false;
			}

		}
		if (Second_ && Time_ > 1.9f)
		{
			if (Actor->IsAnimationName("KoopaLeft"))
			{
				GameEngineSound::SoundPlayOneShot("Fire.wav");
				First_ = true;
				Second_ = false;
				CastleFire* Actor = GetLevel()->CreateActor<CastleFire>();
				Actor->SetPosition(GetPosition());
				Actor->CheckFirst = false;
			}
			else
			{
				GameEngineSound::SoundPlayOneShot("Fire.wav");
				First_ = true;
				Second_ = false;
				CastleFireRight* Actor = GetLevel()->CreateActor<CastleFireRight>();
				Actor->SetPosition(GetPosition());
				Actor->CheckFirst = false;

			}
		}
	}



		if (up == 1
			&& true == CheckCollisionLeft->CollisionCheck("PlayerHitBox", CollisionType::Rect, CollisionType::Rect))
		{
			Actor->ChangeAnimation("KoopaLeft");
			MoveDir.x = -1.0f;
			SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		}
		else
		if (up == 1
			&& true == CheckCollisionRight->CollisionCheck("PlayerHitBox", CollisionType::Rect, CollisionType::Rect))
		{
			Actor->ChangeAnimation("KoopaRight");
			MoveDir.x = 1.0f;
			SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		}
		
	
	//if (RGB(255, 255, 255) == ColorLeftBot&& true != KoopaDownColor->CollisionCheck("Move", CollisionType::Rect, CollisionType::Rect))
	//{
	//	if (up == 1)
	//	{
	//		MoveDir += float4{0, 4.0f};
	//		if (MoveDir.y > 4.0f)
	//		{
	//			MoveDir.y = 4.0f;
	//		}
	//		SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
	//	}

	//}
	if ((RGB(255, 255, 255) != ColorLeftBot || true == KoopaDownColor->CollisionCheck("Move", CollisionType::Rect, CollisionType::Rect)))
	{
		MoveDir.y = 0.0f;
	}
	if (RGB(255, 255, 255) == Color && true != KoopaColor->CollisionCheck("Move", CollisionType::Rect, CollisionType::Rect))
	{
		if (up == 1)
		{
			SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		}

	}

	if (true == CheckCollisionLeft->CollisionCheck("PlayerHitBox", CollisionType::Rect, CollisionType::Rect))
	{
		up = 1;
	}



}

