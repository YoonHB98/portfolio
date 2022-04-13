#include "TitleLevel.h"
#include "GameEngine/GameEngine.h"
#include "TitleBackGround.h"
#include "TitleCharacter.h"
#include <GameEngine/GameEngineImageManager.h>
#include "Coin.h"

TitleLevel::TitleLevel()
{
}

TitleLevel::~TitleLevel()
{
}

void TitleLevel::Loading()
{



	CreateActor<TitleBackGround>(0);
	CreateActor<TitleCharacter>(1);
	CreateActor<Coin>(2);

}

void TitleLevel::Update()
{

}