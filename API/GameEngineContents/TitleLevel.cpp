#include "TitleLevel.h"
#include "GameEngine/GameEngine.h"
#include "TitleBackGround.h"
#include "TitleCharacter.h"
#include <GameEngine/GameEngineImageManager.h>
#include "Coin.h"
#include "Point.h"
#include "WorldCount.h"

TitleLevel::TitleLevel()
{
}

TitleLevel::~TitleLevel()
{
}

void TitleLevel::Loading()
{


	CreateActor<Coin>(1);
	{
		Point* Actor = CreateActor<Point>(1);
	}
	{
		Point* Actor = CreateActor<Point>(1);
		Actor->SetPosition(float4{562, 800});
	}
	CreateActor<TitleBackGround>(0);
	CreateActor<TitleCharacter>(1);
	CreateActor<Coin>(2);
	WorldCount* UI = CreateActor<WorldCount>(2);
}

void TitleLevel::Update()
{

}