#include "Stage1.h"
#include "Point.h"
#include "Sound.h"
#include "WorldCount.h"
#include "SecretBlock.h"
#include "Secret10CoinBlock.h"
#include "Pause.h"
#include "Castle.h"
#include "flag.h"

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
		Map1* Actor = CreateActor<Map1>(0);
		Actor->GetRenderer()->SetImage("11map.bmp");

		float4 BackActor = {};
		BackActor.x = (Actor->GetRenderer()->GetImage()->GetScale().Half().x) - (GameEngineWindow::GetScale().Half().x);
		BackActor.y = (Actor->GetRenderer()->GetImage()->GetScale().Half().y) - (GameEngineWindow::GetScale().Half().y);

		Actor->GetRenderer()->SetPivot(BackActor);
	}
	// 블록
	{
		SecretBlock* Actor = CreateActor<SecretBlock>(2);
		Actor->CreateSecretBlock(float4{ 2580, 340 });
	}

	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 820, 380 });
	}
	{
		QuestionBlock* Actor = CreateActor<QuestionBlock>(2);
		Actor->CreateQuestionBlock(float4{  860, 380 } );
		BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
		CoinActor->CreateBoxCoin(float4{ 860, 380 });
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
		Actor->CreateQuestionBlock(float4{ 4140, 380 });
		BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
		CoinActor->CreateBoxCoin(float4{ 3140, 380 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 3090, 380 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 3110, 220 });
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
		Actor->CreateBlock(float4{ 3170, 220 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 3190, 220 });
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
		Actor->CreateQuestionBlock(float4{ 4190, 380 });
		BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
		CoinActor->CreateBoxCoin(float4{ 4190, 380 });
	}
	{
		QuestionBlock* Actor = CreateActor<QuestionBlock>(2);
		Actor->CreateQuestionBlock(float4{ 4500, 380 });
		BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
		CoinActor->CreateBoxCoin(float4{ 4500, 380 });
	}
	{
		QuestionBlock* Actor = CreateActor<QuestionBlock>(2);
		Actor->CreateQuestionBlock(float4{ 4190, 220 });
		BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
		CoinActor->CreateBoxCoin(float4{ 4190, 220 });
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
		Actor->CreateQuestionBlock(float4{ 5110, 220 });
		BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
		CoinActor->CreateBoxCoin(float4{ 5110, 220 });
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
		Actor->CreateBlock(float4{ 5110, 380 });
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
		Goomba* Actor = CreateActor<Goomba>(1);
		Actor->CreateGoomba(float4{ 900,500 });
	}
	{
		Goomba* Actor = CreateActor<Goomba>(1);
		Actor->CreateGoomba(float4{ 1620,500 });
	}
	{
		Goomba* Actor = CreateActor<Goomba>(1);
		Actor->CreateGoomba(float4{ 2060,500 });
	}
	{
		Goomba* Actor = CreateActor<Goomba>(1);
		Actor->CreateGoomba(float4{ 2120,500 });
	}
	{
		Castle* Actor = CreateActor<Castle>(1);
		Actor->CreateCastle(float4{ 8180,800 });
	}
	{
		flag* Actor = CreateActor<flag>(1);
		Actor->Createflag(float4{ 7920,280 });
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

}
void Stage1::LevelChangeStart()
{ 
	//200, 500
	//체크 14000, 500
	Mario->SetPosition(float4{ 100, 500 });
		UI->TimerReset();
		BgmPlayer.Stop();
	    BgmPlayer = GameEngineSound::SoundPlayControl("overworld.wav");

}