#include "Stage2.h"
#include "Point.h"
#include "Sound.h"
#include "WorldCount.h"
#include "SecretBlock.h"
#include "Secret10CoinBlock.h"
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
	// ºí·Ï
	{
		Fire* Actor = CreateActor<Fire>(2);
		Actor->CreateFire(float4{ 100, 100 }, {20, 0});
	}
	{
		Fire* Actor = CreateActor<Fire>(2);
		Actor->CreateFire(float4{ 100, 100 }, { 40, 0 });
	}
	{
		Fire* Actor = CreateActor<Fire>(2);
		Actor->CreateFire(float4{ 100, 100 }, { 60, 0 });
	}
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

}
void Stage2::LevelChangeStart(GameEngineLevel* _PrevLevel)
{ 
	if (Pause::PlayerStatus == "small")
	{
		Mario->SetPosition(float4{ 30, 260 });
		Pause::PlayerPosition = float4{ 30, 260 };
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
