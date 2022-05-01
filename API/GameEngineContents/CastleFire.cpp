#include "CastleFire.h"
#include <GameEngineBase/GameEngineSound.h>
#include "Point100.h"
#include "Pause.h"
#include "WorldCount.h"




CastleFire::CastleFire() 
	:Speed_(600.0f)
{
}

CastleFire::~CastleFire() 
{
}

void CastleFire::Start()
{
	Actor = CreateRenderer("Fire.bmp");
	Actor->SetIndex(0);
	CastleFireCollision = CreateCollision("MonsterRight", { 60, 20 }, { 0, 0 });
    CheckCollision = CreateCollision("CheckPos", { 40, 2400 }, { -800,20 });;

}

void CastleFire::Update()
{
	if (true == CheckCollision->CollisionCheck("PlayerHitBox", CollisionType::Rect, CollisionType::Rect)
		&&CheckFirst)
	{
		GameEngineSound::SoundPlayOneShot("Fire.wav");
		CheckFirst = false;
	}
	if (CheckFirst == false)
	{
		MoveDir = float4::LEFT;
		SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		Death(5.0f);
	}
}

