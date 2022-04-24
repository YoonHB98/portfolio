#include "Stage1.h"
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

Stage1::Stage1() 
{
}

Stage1::~Stage1() 
{
}

void Stage1::Loading()
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
		Map1* Actor = CreateActor<Map1>(0);
		Actor->GetRenderer()->SetImage("11map.bmp");

		float4 BackActor = {};
		BackActor.x = (Actor->GetRenderer()->GetImage()->GetScale().Half().x);
		BackActor.y = (Actor->GetRenderer()->GetImage()->GetScale().Half().y);

		Actor->GetRenderer()->SetPivot(BackActor);
	}
	// 블록
	{
		Block2* Actor = CreateActor<Block2>(2);
		Actor->CreateBlock2(float4{ 200, 380 });
	}
	{
		SecretBlock* Actor = CreateActor<SecretBlock>(2);
		Actor->CreateSecretBlock(float4{ 2580, 340 });
	}

	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 820, 380 });
	}
	{
		SecretBlockmushroom* Actor = CreateActor<SecretBlockmushroom>(2);
		Actor->CreateSecretBlockmushroom(float4{  860, 380 } );
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 900, 380 });
	}
	{
		QuestionBlock* Actor = CreateActor<QuestionBlock>(2);
		Actor->CreateQuestionBlock(float4{ 940, 380 });
		BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
		CoinActor->CreateBoxCoin(float4{ 940, 380 });

	}
		{
			Block* Actor = CreateActor<Block>(2);
			Actor->CreateBlock(float4{ 980, 380 });
		}
		{
			QuestionBlock* Actor = CreateActor<QuestionBlock>(2);
			Actor->CreateQuestionBlock(float4{ 900, 220 });
			BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
			CoinActor->CreateBoxCoin(float4{ 900, 220 });

		}
	

	{
		QuestionBlock* Actor = CreateActor<QuestionBlock>(2);
		Actor->CreateQuestionBlock(float4{ 660, 380 });
		BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
		CoinActor->CreateBoxCoin(float4{ 660, 380 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 3100, 380 });
	}
	{
		QuestionBlock* Actor = CreateActor<QuestionBlock>(2);
		Actor->CreateQuestionBlock(float4{ 3140, 380 });
		BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
		CoinActor->CreateBoxCoin(float4{ 3140, 380 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 3180, 380 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 3220, 220 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 3260, 220 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 3300, 220 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 3340, 220 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 3380, 220 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 3420, 220 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 3460, 220 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 3500, 220 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 3660, 220 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 3700, 220 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 3740, 220 });
	}
	{
		QuestionBlock* Actor = CreateActor<QuestionBlock>(2);
		Actor->CreateQuestionBlock(float4{3780, 220 });
		BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
		CoinActor->CreateBoxCoin(float4{ 3780, 220 });
	}
	{
	
		Secret10CoinBlock* Actor = CreateActor<Secret10CoinBlock>(2);
		Actor->CreateSecret10CoinBlock(float4{ 3780, 380 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 4020, 380 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 4060, 380 });
	}
	{
		QuestionBlock* Actor = CreateActor<QuestionBlock>(2);
		Actor->CreateQuestionBlock(float4{ 4260, 380 });
		BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
		CoinActor->CreateBoxCoin(float4{ 4260, 380 });
	}
	{
		QuestionBlock* Actor = CreateActor<QuestionBlock>(2);
		Actor->CreateQuestionBlock(float4{ 4380, 380 });
		BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
		CoinActor->CreateBoxCoin(float4{ 4380, 380 });
	}
	{
		QuestionBlock* Actor = CreateActor<QuestionBlock>(2);
		Actor->CreateQuestionBlock(float4{ 4500, 380 });
		BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
		CoinActor->CreateBoxCoin(float4{ 4500, 380 });
	}
	{
		QuestionBlock* Actor = CreateActor<QuestionBlock>(2);
		Actor->CreateQuestionBlock(float4{ 4380, 220 });
		BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
		CoinActor->CreateBoxCoin(float4{ 4380, 220 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 4740, 380 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{4860, 220 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 4900, 220 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 4940, 220 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 5140, 220 });
	}
	{
		QuestionBlock* Actor = CreateActor<QuestionBlock>(2);
		Actor->CreateQuestionBlock(float4{ 5180, 220 });
		BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
		CoinActor->CreateBoxCoin(float4{ 5180, 220 });
	}
	{
		QuestionBlock* Actor = CreateActor<QuestionBlock>(2);
		Actor->CreateQuestionBlock(float4{ 5220, 220 });
		BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
		CoinActor->CreateBoxCoin(float4{ 5220, 220 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 5260, 220 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 5180, 380 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 5220, 380 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 6740, 380 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 6780, 380 });
	}
	{
		QuestionBlock* Actor = CreateActor<QuestionBlock>(2);
		Actor->CreateQuestionBlock(float4{ 6820, 380 });
		BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
		CoinActor->CreateBoxCoin(float4{ 6820, 380 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 6860, 380 });
	}
	//몬스터
	{
		Goomba1 = CreateActor<Goomba>(1);
		Goomba1->CreateGoomba(float4{ 900,500 });
	}
	{
		Turtle* Actor = CreateActor<Turtle>(1);
		Actor->CreateTurtle(float4{ 4300,490 });
	}
	{
		Goomba2 = CreateActor<Goomba>(1);
		Goomba2->CreateGoomba(float4{ 2060,500 });
	}
	{
		Goomba3 = CreateActor<Goomba>(1);
		Goomba3->CreateGoomba(float4{ 2120,500 });
	}
	{
		Goomba4 = CreateActor<Goomba>(1);
		Goomba4->CreateGoomba(float4{ 1620,500 });
	}
	{
		Goomba5 = CreateActor<Goomba>(1);
		Goomba5->CreateGoomba(float4{ 3220,185 });
	}
	{
		Goomba6 = CreateActor<Goomba>(1);
		Goomba6->CreateGoomba(float4{ 3300,185 });
	}
	{
		Goomba7 = CreateActor<Goomba>(1);
		Goomba7->CreateGoomba(float4{ 3900,500 });
	}
	{
		Goomba8 = CreateActor<Goomba>(1);
		Goomba8->CreateGoomba(float4{ 3960,500 });
	}
	{
		Goomba9 = CreateActor<Goomba>(1);
		Goomba9->CreateGoomba(float4{ 4580,500 });
	}
	{
		Goomba10 = CreateActor<Goomba>(1);
		Goomba10->CreateGoomba(float4{ 4640,500 });
	}
	{
		Goomba11 = CreateActor<Goomba>(1);
		Goomba11->CreateGoomba(float4{ 4980,500 });
	}
	{
		Goomba12 = CreateActor<Goomba>(1);
		Goomba12->CreateGoomba(float4{ 5040,500 });
	}
	{
		Goomba13 = CreateActor<Goomba>(1);
		Goomba13->CreateGoomba(float4{ 5140,500 });
	}
	{
		Goomba14 = CreateActor<Goomba>(1);
		Goomba14->CreateGoomba(float4{ 5200,500 });
	}
	{
		Goomba15 = CreateActor<Goomba>(1);
		Goomba15->CreateGoomba(float4{ 6980,500 });
	}
	{
		Goomba16 = CreateActor<Goomba>(1);
		Goomba16->CreateGoomba(float4{ 7040,500 });
	}
	{
		Castle* Actor = CreateActor<Castle>(1);
		Actor->CreateCastle(float4{ 8180,800 });
	}
	{
		flag* Actor = CreateActor<flag>(1);
		Actor->Createflag(float4{ 7920,140 });
	}
	BgmPlayer = GameEngineSound::SoundPlayControl("blank.wav");
}

void Stage1::Update()
{
	if (Pause::pause
		|| Pause::death
		|| Pause::end)
	{
		BgmPlayer.Stop();
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
void Stage1::LevelChangeStart(GameEngineLevel* _PrevLevel)
{ 
	//200, 500
	//체크 14000, 500
	if (true != Goomba1->IsDeath())
	{
		Goomba1->SetPosition(float4{900, 500});
		Goomba1->up = 0;
	}
	if (true != Goomba2->IsDeath())
	{
		Goomba2->SetPosition(float4{ 2060, 500 });
		Goomba2->up = 0;
	}
	if (true != Goomba3->IsDeath())
	{
		Goomba3->SetPosition(float4{ 2120, 500 });
		Goomba3->up = 0;
	}
	if (true != Goomba4->IsDeath())
	{
		Goomba4->SetPosition(float4{ 1620, 500 });
		Goomba4->up = 0;
	}
	if (true != Goomba5->IsDeath())
	{
		Goomba5->SetPosition(float4{ 3220, 185 });
		Goomba5->up = 0;
	}
	if (true != Goomba6->IsDeath())
	{
		Goomba6->SetPosition(float4{ 3330, 185 });
		Goomba6->up = 0;
	}
	if (true != Goomba7->IsDeath())
	{
		Goomba7->SetPosition(float4{ 3900, 500 });
		Goomba7->up = 0;
	}
	if (true != Goomba8->IsDeath())
	{
		Goomba8->SetPosition(float4{ 3960, 500 });
		Goomba8->up = 0;
	}
	if (true != Goomba9->IsDeath())
	{
		Goomba9->SetPosition(float4{ 4580, 500 });
		Goomba9->up = 0;
	}
	if (true != Goomba10->IsDeath())
	{
		Goomba10->SetPosition(float4{ 4640, 500 });
		Goomba10->up = 0;
	}
	if (true != Goomba11->IsDeath())
	{
		Goomba11->SetPosition(float4{ 4980, 500 });
		Goomba11->up = 0;
	}
	if (true != Goomba12->IsDeath())
	{
		Goomba12->SetPosition(float4{ 5040, 500 });
		Goomba12->up = 0;
	}
	if (true != Goomba13->IsDeath())
	{
		Goomba13->SetPosition(float4{ 5140, 500 });
		Goomba13->up = 0;
	}
	if (true != Goomba14->IsDeath())
	{
		Goomba14->SetPosition(float4{ 5200, 500 });
		Goomba14->up = 0;
	}
	if (true != Goomba15->IsDeath())
	{
		Goomba15->SetPosition(float4{ 6980, 500 });
		Goomba15->up = 0;
	}
	if (true != Goomba16->IsDeath())
	{
		Goomba16->SetPosition(float4{ 7040, 500 });
		Goomba16->up = 0;
	}
	{
		Castle* Actor = CreateActor<Castle>(1);
		Actor->CreateCastle(float4{ 8180,800 });
	}
	{
		flag* Actor = CreateActor<flag>(1);
		Actor->Createflag(float4{ 7920,140 });
	}
	(Pause::PlayerPosition = (float4{ 100, 500 }));
	Mario->SetPosition(float4{ 100, 500 });
		UI->TimerReset();
		BgmPlayer.Stop();
	    BgmPlayer = GameEngineSound::SoundPlayControl("overworld.wav");

}