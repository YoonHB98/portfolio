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

	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("MARIO.bmp");
		Image->Cut({ 80, 80 });
	}

	CreateActor<TitleBackGround>(0);
	CreateActor<TitleCharacter>(1);


}

void TitleLevel::Update()
{

}