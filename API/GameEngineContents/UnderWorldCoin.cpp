#include "UnderWorldCoin.h"
#include "UP1.h"
#include "Point.h"
#include "Coin.h"
#include "Sound.h"
#include "Pause.h"
#include "Point100.h"
#include "LevelIntro.h"
#include "WorldCount.h"
#include "BigPlayer.h"

UnderWorldCoin::UnderWorldCoin()
{
}

UnderWorldCoin::~UnderWorldCoin()
{
}

void UnderWorldCoin::CreateUnderWorldCoin(const float4& _Pivot)
{
	{
		float4 Pivot = _Pivot;
		float4 CoPivot = Pivot;
		CoPivot.y = Pivot.y + 18;

		SetPosition(Pivot);
	}
}

void UnderWorldCoin::Start()
{
	UnderWorldCoinCollision = CreateCollision("UnderWorldCoin", { 40, 40 }, { 0, 0 });
	Actor = CreateRenderer("UnderWorldCoin.bmp");
	Actor->SetIndex(0);
	Actor->CreateAnimation("UnderWorldCoin.bmp", "UnderWorldCoin", 0, 1, 0.4f, true);
	Actor->ChangeAnimation("UnderWorldCoin");
}

void UnderWorldCoin::Update()
{

	if (true == UnderWorldCoinCollision->CollisionCheck("PlayerItem", CollisionType::Rect, CollisionType::Rect))
	{
		Point::PointUI += 100.0f;
		Coin::CoinUI = Coin::CoinUI + 1;
		GameEngineSound::SoundPlayOneShot("coin.wav");
		Death();
	}

	
}

