#include "Mario.h"
#include "Stage1.h"
#include "EndingLevel.h"
#include "TitleLevel.h"
#include "StageIntro.h"
#include "Stage1Under.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineBase/GameEngineFile.h>
#include <GameEngine/GameEngineImageManager.h>



Mario::Mario() 
{
}

Mario::~Mario() 
{
}

void Mario::GameInit()
{
	//원본 256 220
	GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 0, 0}, { 620, 600 });

	
	{
		//GameEngineImageManager::GetInst()->/*Load("경로", "이름");*/
			// 현재 디렉토리
		GameEngineDirectory ResourcesCharacterDir;
		//API까지 올라가고
		ResourcesCharacterDir.MoveParent("API");
		ResourcesCharacterDir.Move("Resources");
		ResourcesCharacterDir.Move("Character");


		// 폴더안에 모든 이미지 파일을 찾는다.
		std::vector<GameEngineFile> AllImageFileList = ResourcesCharacterDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}
	{
		//GameEngineImageManager::GetInst()->/*Load("경로", "이름");*/
			// 현재 디렉토리
		GameEngineDirectory ResourcesMapDir;
		//API까지 올라가고
		ResourcesMapDir.MoveParent("API");
		ResourcesMapDir.Move("Resources");
		ResourcesMapDir.Move("Map");


		// 폴더안에 모든 이미지 파일을 찾는다.
		std::vector<GameEngineFile> AllImageFileList = ResourcesMapDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}
	{
		//GameEngineImageManager::GetInst()->/*Load("경로", "이름");*/
			// 현재 디렉토리
		GameEngineDirectory ResourcesMapDir;
		//API까지 올라가고
		ResourcesMapDir.MoveParent("API");
		ResourcesMapDir.Move("Resources");
		ResourcesMapDir.Move("Sound");


		// 폴더안에 모든 이미지 파일을 찾는다.
		std::vector<GameEngineFile> AllImageFileList = ResourcesMapDir.GetAllFile();

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineSound::LoadRes(AllImageFileList[i].GetFullPath());
		}
	}
	{
		//GameEngineImageManager::GetInst()->/*Load("경로", "이름");*/
			// 현재 디렉토리
		GameEngineDirectory ResourcesBlockDir;
		//API까지 올라가고
		ResourcesBlockDir.MoveParent("API");
		ResourcesBlockDir.Move("Resources");
		ResourcesBlockDir.Move("Block");


		// 폴더안에 모든 이미지 파일을 찾는다.
		std::vector<GameEngineFile> AllImageFileList = ResourcesBlockDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}
	{
		//GameEngineImageManager::GetInst()->/*Load("경로", "이름");*/
			// 현재 디렉토리
		GameEngineDirectory ResourcesUIDir;
		//API까지 올라가고
		ResourcesUIDir.MoveParent("API");
		ResourcesUIDir.Move("Resources");
		ResourcesUIDir.Move("TiTle&UI");


		// 폴더안에 모든 이미지 파일을 찾는다.
		std::vector<GameEngineFile> AllImageFileList = ResourcesUIDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}
	{
		//GameEngineImageManager::GetInst()->/*Load("경로", "이름");*/
			// 현재 디렉토리
		GameEngineDirectory ResourcesUIDir;
		//API까지 올라가고
		ResourcesUIDir.MoveParent("API");
		ResourcesUIDir.Move("Resources");
		ResourcesUIDir.Move("Item");


		// 폴더안에 모든 이미지 파일을 찾는다.
		std::vector<GameEngineFile> AllImageFileList = ResourcesUIDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}

	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("MARIO.bmp");
		Image->Cut({ 40, 40 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("number.bmp");
		Image->Cut({ 20,20 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("numberreverse.bmp");
		Image->Cut({ 20,20 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("blank.bmp");
		Image->Cut({ 20,20 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Block.bmp");
		Image->Cut({ 40,40 });
	}
	{
		GameEngineImage * Image = GameEngineImageManager::GetInst()->Find("QuestionBlock.bmp");
		Image->Cut({ 40,40 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Goomba.bmp");
		Image->Cut({ 40,40 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Coin.bmp");
		Image->Cut({ 20,20 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("BoxCoin.bmp");
		Image->Cut({ 20,20 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("UICOIN.bmp");
		Image->Cut({ 15,20 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("0.bmp");
		Image->Cut({ 20,20 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("SecretCoinBlock.bmp");
		Image->Cut({ 40,40 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("BigMario.bmp");
		Image->Cut({ 40,80 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("BigMarioFlower.bmp");
		Image->Cut({ 40,80 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("BigStarAnimation.bmp");
		Image->Cut({ 40,80 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("StarAnimation.bmp");
		Image->Cut({ 40,40 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Flower.bmp");
		Image->Cut({ 40,40 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("BlockBreak.bmp");
		Image->Cut({ 20,20 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("MarioChange.bmp");
		Image->Cut({ 40,80 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Turtle.bmp");
		Image->Cut({ 40,60 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Bullet.bmp");
		Image->Cut({ 20,20 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Boom.bmp");
		Image->Cut({ 40,40 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("MarioFire.bmp");
		Image->Cut({ 40,80 });
	}
	CreateLevel<TitleLevel>("Title");
	CreateLevel<Stage1>("Stage1");
	CreateLevel<Stage1Under>("Stage1Under");
	CreateLevel<EndingLevel>("Ending");
	CreateLevel<StageIntro>("StageIntro");
	ChangeLevel("Stage1");
}

void Mario::GameLoop()
{

}
void Mario::GameEnd()
{

}