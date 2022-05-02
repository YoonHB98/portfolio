#include "CastleFireRight.h"
#include <GameEngineBase/GameEngineSound.h>
#include "Point100.h"
#include "Pause.h"
#include "WorldCount.h"




CastleFireRight::CastleFireRight() 
	:Speed_(600.0f)
{
}

CastleFireRight::~CastleFireRight() 
{
}

void CastleFireRight::Start()
{
	Actor = CreateRenderer("Fire.bmp");
	Actor->SetIndex(0);
	CastleFireRightCollision = CreateCollision("MonsterRight", { 60, 20 }, { 0, 0 });
    CheckCollision = CreateCollision("CheckPos", { 40, 2400 }, { -800,20 });;

}

void CastleFireRight::Update()
{
	if (true == CheckCollision->CollisionCheck("PlayerHitBox", CollisionType::Rect, CollisionType::Rect)
		&&CheckFirst)
	{
		GameEngineSound::SoundPlayOneShot("Fire.wav");
		CheckFirst = false;
	}
	if (CheckFirst == false)
	{
		MoveDir = float4::RIGHT;
		SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		Death(2.0f);
	}
}

