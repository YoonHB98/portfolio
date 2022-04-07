#include "Mario.h"
#include "PlayLevel.h"
#include "Stage1.h"
#include "EndingLevel.h"
#include "TitleLevel.h"
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
	//원본 256 240
	GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 0, 0}, { 1280, 1200 });

	
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
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("MARIO.bmp");
		Image->Cut({ 80, 80 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("number.bmp");
		Image->Cut({ 40,40 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("numberreverse.bmp");
		Image->Cut({ 40,40 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("blank.bmp");
		Image->Cut({ 40,40 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Block.bmp");
		Image->Cut({ 80,80 });
	}
	{
		GameEngineImage * Image = GameEngineImageManager::GetInst()->Find("QuestionBlock.bmp");
		Image->Cut({ 80,80 });
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Goomba.bmp");
		Image->Cut({ 80,80 });
	}
	CreateLevel<TitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");
	CreateLevel<Stage1>("Stage1");
	CreateLevel<EndingLevel>("Ending");
	ChangeLevel("Title");
}

void Mario::GameLoop()
{

}
void Mario::GameEnd()
{

}