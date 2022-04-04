#include "TitleLevel.h"
#include "GameEngine/GameEngine.h"
#include "TitleBackGround.h"
#include "TitleCharacter.h"
#include <GameEngine/GameEngineImageManager.h>

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


}

void TitleLevel::Update()
{

}