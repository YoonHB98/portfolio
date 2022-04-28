#include "Stage1Under.h"
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

Stage1Under::Stage1Under() 
{
}

Stage1Under::~Stage1Under() 
{
}

void Stage1Under::Loading()
{
	GameEngineInput::GetInst()->Reset();
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
		Actor->GetRenderer()->SetImage("11under.bmp");

		float4 BackActor = {};
		BackActor.x = (Actor->GetRenderer()->GetImage()->GetScale().Half().x);
		BackActor.y = (Actor->GetRenderer()->GetImage()->GetScale().Half().y);

		Actor->GetRenderer()->SetPivot(BackActor);
	}
	// ºí·Ï
	{
		UnderWorldCoin* Pointer = CreateActor<UnderWorldCoin>(2);
		Pointer->SetPosition(float4{175, 380});
	}
	{
		UnderWorldCoin* Pointer = CreateActor<UnderWorldCoin>(2);
		Pointer->SetPosition(float4{ 215, 380 });
	}
	{
		UnderWorldCoin* Pointer = CreateActor<UnderWorldCoin>(2);
		Pointer->SetPosition(float4{ 255, 380 });
	}
	{
		UnderWorldCoin* Pointer = CreateActor<UnderWorldCoin>(2);
		Pointer->SetPosition(float4{ 295, 380 });
	}
	{
		UnderWorldCoin* Pointer = CreateActor<UnderWorldCoin>(2);
		Pointer->SetPosition(float4{ 335, 380 });
	}
	{
		UnderWorldCoin* Pointer = CreateActor<UnderWorldCoin>(2);
		Pointer->SetPosition(float4{ 375, 380 });
	}
	{
		UnderWorldCoin* Pointer = CreateActor<UnderWorldCoin>(2);
		Pointer->SetPosition(float4{ 415, 380 });
	}
	{
		UnderWorldCoin* Pointer = CreateActor<UnderWorldCoin>(2);
		Pointer->SetPosition(float4{ 175, 340 });
	}
	{
		UnderWorldCoin* Pointer = CreateActor<UnderWorldCoin>(2);
		Pointer->SetPosition(float4{ 215, 340 });
	}
	{
		UnderWorldCoin* Pointer = CreateActor<UnderWorldCoin>(2);
		Pointer->SetPosition(float4{ 255, 340 });
	}
	{
		UnderWorldCoin* Pointer = CreateActor<UnderWorldCoin>(2);
		Pointer->SetPosition(float4{ 295, 340 });
	}
	{
		UnderWorldCoin* Pointer = CreateActor<UnderWorldCoin>(2);
		Pointer->SetPosition(float4{ 335, 340 });
	}
	{
		UnderWorldCoin* Pointer = CreateActor<UnderWorldCoin>(2);
		Pointer->SetPosition(float4{ 375, 340 });
	}
	{
		UnderWorldCoin* Pointer = CreateActor<UnderWorldCoin>(2);
		Pointer->SetPosition(float4{ 415, 340 });
	}
	{
		UnderWorldCoin* Pointer = CreateActor<UnderWorldCoin>(2);
		Pointer->SetPosition(float4{ 215, 300 });
	}
	{
		UnderWorldCoin* Pointer = CreateActor<UnderWorldCoin>(2);
		Pointer->SetPosition(float4{ 255, 300 });
	}
	{
		UnderWorldCoin* Pointer = CreateActor<UnderWorldCoin>(2);
		Pointer->SetPosition(float4{ 295, 300 });
	}
	{
		UnderWorldCoin* Pointer = CreateActor<UnderWorldCoin>(2);
		Pointer->SetPosition(float4{ 335, 300 });
	}
	{
		UnderWorldCoin* Pointer = CreateActor<UnderWorldCoin>(2);
		Pointer->SetPosition(float4{ 375, 300 });
	}
	{
		PipeLeft* Pointer = CreateActor<PipeLeft>(4);
		Pointer->SetPosition(float4{ 571, 480 });
	}

	BgmPlayer = GameEngineSound::SoundPlayControl("blank.wav");
}

void Stage1Under::Update()
{
	if (WorldCount::Up)
	{
		BgmPlayer.Stop();
		GameEngine::GetInst().ChangeLevel("Stage1");
		return;
	}
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
		BgmPlayer = GameEngineSound::SoundPlayControl("underground.wav");
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
void Stage1Under::LevelChangeStart(GameEngineLevel* _PrevLevel)
{ 
	if (Pause::PlayerStatus == "small")
	{
		Mario->SetPosition(float4{ 100, 100 });
		Pause::PlayerPosition = float4{ 100, 100 };
	}else
		if (Pause::PlayerStatus == "big")
		{
			BigMario->SetPosition(float4{ 100, 100 });

		}

		UI->TimerReset();
		BgmPlayer.Stop();
	    BgmPlayer = GameEngineSound::SoundPlayControl("underground.wav");

}
