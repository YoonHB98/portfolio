#include "Stage2.h"
#include "Point.h"
#include "Sound.h"
#include "WorldCount.h"
#include "SecretBlock.h"
#include "SecretBlockCoin.h"
#include "Pause.h"
#include "Castle.h"
#include "flag.h"
#include "UpMushroom.h"
#include "UpMushroom2.h"
#include "Mushroom.h"
#include "Mushroom2.h"
#include "Block2.h"
#include "SecretBlockmushroom.h"
#include "Turtle.h"
#include "GoombaDead.h"
#include "CastleFlag.h"
#include "PipeLeft.h"
#include "UnderWorldCoin.h"
#include "Fire.h"
#include "FireBlock.h"
#include "CastleFire.h"
#include "Koopa.h"
#include "Axe.h"
#include "Tie.h"
#include "BridgeTile.h"
#include "Text1.h"
#include "Text2.h"
#include "Text3.h"
#include "Text4.h"
#include "Text5.h"

Stage2::Stage2() 
{
}

Stage2::~Stage2() 
{
}

void Stage2::Loading()
{
	{
		WorldCount* UI = CreateActor<WorldCount>(2);
	}

	{
		UI = CreateActor<TopUI>(1);
	}
	{
		UICOIN = CreateActor<Coin>(2);
	}
	{
		Point* Pointer = CreateActor<Point>(2);
	}
	{
		Sound* SoundR = CreateActor<Sound>(0);
	}
	{
	Mario = CreateActor<Player>(3);

	Mario->SetPosition(float4{ 100, 500 });
	}
	{
		BigMario = CreateActor<BigPlayer>(3);

		BigMario->SetPosition(float4{ 150, -3000 });
	}
	{
		Map1Under * Actor = CreateActor<Map1Under>(0);
		Actor->GetRenderer()->SetImage("12map.bmp");

		float4 BackActor = {};
		BackActor.x = (Actor->GetRenderer()->GetImage()->GetScale().Half().x);
		BackActor.y = (Actor->GetRenderer()->GetImage()->GetScale().Half().y);

		Actor->GetRenderer()->SetPivot(BackActor);
	}
	// ????
	{
		FireBlock* Actor = CreateActor<FireBlock>(2);
		Actor->SetPosition(float4{ 1220, 420 });
	}
	{
		FireBlock* Actor = CreateActor<FireBlock>(2);
		Actor->SetPosition(float4{ 1980,260 });
	}
	{
		FireBlock* Actor = CreateActor<FireBlock>(2);
		Actor->SetPosition(float4{ 2420,260 });
	}
	{
		FireBlock* Actor = CreateActor<FireBlock>(2);
		Actor->SetPosition(float4{ 2700, 260 });
	}
	{
		SecretBlockmushroom* Actor = CreateActor<SecretBlockmushroom>(2);
		Actor->SetPosition(float4{ 1220, 260 });
	}
	{
		FireBlock* Actor = CreateActor<FireBlock>(2);
		Actor->SetPosition(float4{ 3060, 380 });
	}
	{
		FireBlock* Actor = CreateActor<FireBlock>(2);
		Actor->SetPosition(float4{ 3380, 380 });
	}
	{
		FireBlock* Actor = CreateActor<FireBlock>(2);
		Actor->SetPosition(float4{ 3540, 180 });
	}
	{
		CastleFire* Actor = CreateActor<CastleFire>(2);
		Actor->SetPosition(float4{ 4100, 330 });
	}
	{
		CastleFire* Actor = CreateActor<CastleFire>(2);
		Actor->SetPosition(float4{ 4620, 370 });
	}
	{
		CastleFire* Actor = CreateActor<CastleFire>(2);
		Actor->SetPosition(float4{ 5120, 330 });
	}
	{
		SecretBlockCoin* Actor = CreateActor<SecretBlockCoin>(2);
		Actor->CreateSecretBlockCoin(float4{ 4260, 380 });
	}
	{
		SecretBlockCoin* Actor = CreateActor<SecretBlockCoin>(2);
		Actor->CreateSecretBlockCoin(float4{ 4380, 380 });
	}
	{
		SecretBlockCoin* Actor = CreateActor<SecretBlockCoin>(2);
		Actor->CreateSecretBlockCoin(float4{ 4500, 380 });
	}
	{
		SecretBlockCoin* Actor = CreateActor<SecretBlockCoin>(2);
		Actor->CreateSecretBlockCoin(float4{ 4300, 220 });
	}
	{
		SecretBlockCoin* Actor = CreateActor<SecretBlockCoin>(2);
		Actor->CreateSecretBlockCoin(float4{ 4420, 220 });
	}
	{
		SecretBlockCoin* Actor = CreateActor<SecretBlockCoin>(2);
		Actor->CreateSecretBlockCoin(float4{ 4540, 220 });
	}
	{
		Koopa* Actor = CreateActor<Koopa>(2);
		Actor->CreateKoopa(float4{ 5450, 360 });
	}
	{
		Axe* Actor = CreateActor<Axe>(2);
		Actor->SetPosition(float4{ 5660, 340 });
	}
	{
		Tie* Actor = CreateActor<Tie>(2);
		Actor->SetPosition(float4{ 5620, 380 });
	}
	{
		BridgeTile* Actor = CreateActor<BridgeTile>(2);
		Actor->SetPosition(float4{ 5100, 420 });
	}
	BgmPlayer = GameEngineSound::SoundPlayControl("blank.wav");
}

void Stage2::Update()
{
	
	if ( Pause::death
		|| Pause::end)
	{
		BgmPlayer.Stop();
		return;
	}
	
		if (Pause::pause)
		{
			BgmPlayer.Stop();
			pausefirst_ = true;
			return;
		}
	if (pausefirst_)
	{
		BgmPlayer = GameEngineSound::SoundPlayControl("castle.wav");
		pausefirst_ = false;
	}
	if (Pause::PlayerStatus == "big"
		&& Pause::bigfirst)
	{
		Mario->SetPosition(float4{ 100, 3000 });
		BigMario->SetPosition(Pause::PlayerPosition);
		Pause::bigfirst = false;
	}
	if (Pause::PlayerStatus == "small")
	{
		BigMario->SetPosition(float4{ 100, 3000 });
		Mario->SetPosition(Pause::PlayerPosition);
	}
	if (Pause::Stage2Sound )
	{
		BgmPlayer.Stop();
		GameEngineSound::SoundPlayOneShot("castleend.wav");
		Pause::Stage2Sound = false;
	}
	if (Pause::GameRealEnd
		&&endtimefirst)
	{
		Time_ = Time_ + GameEngineTime::GetDeltaTime();
		if (Time_ >1.5f)
		{
			endtimefirst = false;
		}
	}
	if (Pause::GameRealEnd && GameRealEnd
		&& Time_ >1.5f)
	{
		Time_ = 0.0f;
		GameRealEnd = false;
		MarioText_ = true;
		BgmPlayer.Stop();
		BgmPlayer = GameEngineSound::SoundPlayControl("princessmusic.wav");
	}

	if (MarioText_)
	{
		Time_ = Time_ + GameEngineTime::GetDeltaTime();
		if (Time_ > 1.0f)
		{
			Text1* Actor = CreateActor<Text1>(2);
			Actor->SetPosition(float4{ 6120, 200 });
		}
		if (Time_ > 2.5f)
		{
			Text2* Actor = CreateActor<Text2>(2);
			Actor->SetPosition(float4{ 6100, 260 });
		}
		if (Time_ > 4.0f)
		{
			Text3* Actor = CreateActor<Text3>(2);
			Actor->SetPosition(float4{ 6100, 300 });
		}
		if (Time_ > 5.5f)
		{
			Text4* Actor = CreateActor<Text4>(2);
			Actor->SetPosition(float4{ 6100, 360 });
		}
		if (Time_ > 7.0f)
		{
			Text5* Actor = CreateActor<Text5>(2);
			Actor->SetPosition(float4{ 6100, 400 });
		}
	}
}
void Stage2::LevelChangeStart(GameEngineLevel* _PrevLevel)
{ 
	if (Pause::PlayerStatus == "small")
	{
		Mario->SetPosition(float4{ 30, 260 });
		Pause::PlayerPosition = float4{30, 260 };
	}else
		if (Pause::PlayerStatus == "big")
		{
			BigMario->SetPosition(float4{ 30, 280 });
			Pause::PlayerPosition = float4{ 30, 280 };
		}

		UI->TimerReset();
		BgmPlayer.Stop();
	    BgmPlayer = GameEngineSound::SoundPlayControl("castle.wav");

}
