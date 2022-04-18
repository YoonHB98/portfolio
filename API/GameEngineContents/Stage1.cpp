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

	Mario->SetPosition(float4{ 200, 1000 });
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
		Actor->CreateSecretBlock(float4{ 5160, 680 });
	}

	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 1640, 760 });
	}
	{
		QuestionBlock* Actor = CreateActor<QuestionBlock>(2);
		Actor->CreateQuestionBlock(float4{  1720, 760 } );
		BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
		CoinActor->CreateBoxCoin(float4{ 1720, 760 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 1800, 760 });
	}
	{
		QuestionBlock* Actor = CreateActor<QuestionBlock>(2);
		Actor->CreateQuestionBlock(float4{ 1880, 760 });
		BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
		CoinActor->CreateBoxCoin(float4{ 1880, 760 });

	}
		{
			Block* Actor = CreateActor<Block>(2);
			Actor->CreateBlock(float4{ 1960, 760 });
		}
		{
			QuestionBlock* Actor = CreateActor<QuestionBlock>(2);
			Actor->CreateQuestionBlock(float4{ 1800, 440 });
			BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
			CoinActor->CreateBoxCoin(float4{ 1800, 440 });

		}
	

	{
		QuestionBlock* Actor = CreateActor<QuestionBlock>(2);
		Actor->CreateQuestionBlock(float4{ 1320, 760 });
		BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
		CoinActor->CreateBoxCoin(float4{ 1320, 760 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 6200, 760 });
	}
	{
		QuestionBlock* Actor = CreateActor<QuestionBlock>(2);
		Actor->CreateQuestionBlock(float4{ 6280, 760 });
		BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
		CoinActor->CreateBoxCoin(float4{ 6280, 760 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 6360, 760 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 6440, 440 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 6520, 440 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 6600, 440 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 6680, 440 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 6760, 440 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 6840, 440 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 6920, 440 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 7000, 440 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 7320, 440 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 7400, 440 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 7480, 440 });
	}
	{
		QuestionBlock* Actor = CreateActor<QuestionBlock>(2);
		Actor->CreateQuestionBlock(float4{ 7560, 440 });
		BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
		CoinActor->CreateBoxCoin(float4{ 7560, 440 });
	}
	{
	
		Secret10CoinBlock* Actor = CreateActor<Secret10CoinBlock>(2);
		Actor->CreateSecret10CoinBlock(float4{ 7560, 760 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 8040, 760 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 8120, 760 });
	}
	{
		QuestionBlock* Actor = CreateActor<QuestionBlock>(2);
		Actor->CreateQuestionBlock(float4{ 8520, 760 });
		BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
		CoinActor->CreateBoxCoin(float4{ 8520, 760 });
	}
	{
		QuestionBlock* Actor = CreateActor<QuestionBlock>(2);
		Actor->CreateQuestionBlock(float4{ 8760, 760 });
		BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
		CoinActor->CreateBoxCoin(float4{ 8760, 760 });
	}
	{
		QuestionBlock* Actor = CreateActor<QuestionBlock>(2);
		Actor->CreateQuestionBlock(float4{ 9000, 760 });
		BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
		CoinActor->CreateBoxCoin(float4{ 9000, 760 });
	}
	{
		QuestionBlock* Actor = CreateActor<QuestionBlock>(2);
		Actor->CreateQuestionBlock(float4{ 8760, 440 });
		BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
		CoinActor->CreateBoxCoin(float4{ 8760, 440 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 9480, 760 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 9720, 440 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 9800, 440 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 9880, 440 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 10280, 440 });
	}
	{
		QuestionBlock* Actor = CreateActor<QuestionBlock>(2);
		Actor->CreateQuestionBlock(float4{ 10360, 440 });
		BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
		CoinActor->CreateBoxCoin(float4{ 10360, 440 });
	}
	{
		QuestionBlock* Actor = CreateActor<QuestionBlock>(2);
		Actor->CreateQuestionBlock(float4{ 10440, 440 });
		BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
		CoinActor->CreateBoxCoin(float4{ 10440, 440 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 10520, 440 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 10360, 760 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 10440, 760 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 13480, 760 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 13560, 760 });
	}
	{
		QuestionBlock* Actor = CreateActor<QuestionBlock>(2);
		Actor->CreateQuestionBlock(float4{ 13640, 760 });
		BoxCoin* CoinActor = CreateActor<BoxCoin>(1);
		CoinActor->CreateBoxCoin(float4{ 13640, 760 });
	}
	{
		Block* Actor = CreateActor<Block>(2);
		Actor->CreateBlock(float4{ 13720, 760 });
	}
	//몬스터
	{
		Goomba* Actor = CreateActor<Goomba>(1);
		Actor->CreateGoomba(float4{ 1800,1000 });
	}
	{
		Goomba* Actor = CreateActor<Goomba>(1);
		Actor->CreateGoomba(float4{ 3240,1000 });
	}
	{
		Goomba* Actor = CreateActor<Goomba>(1);
		Actor->CreateGoomba(float4{ 4120,1000 });
	}
	{
		Goomba* Actor = CreateActor<Goomba>(1);
		Actor->CreateGoomba(float4{ 4240,1000 });
	}
	{
		Castle* Actor = CreateActor<Castle>(1);
		Actor->CreateCastle(float4{ 16360,800 });
	}
	{
		flag* Actor = CreateActor<flag>(1);
		Actor->Createflag(float4{ 15840,280 });
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
	//200, 1000
	//체크 14000, 1000
	Mario->SetPosition(float4{ 200, 1000 });
		UI->TimerReset();
		BgmPlayer.Stop();
	    BgmPlayer = GameEngineSound::SoundPlayControl("overworld.wav");

}