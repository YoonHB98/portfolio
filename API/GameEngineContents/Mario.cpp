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
	//���� 256 240
	GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 0, 0}, { 1280, 1200 });

	
	{
		//GameEngineImageManager::GetInst()->/*Load("���", "�̸�");*/
			// ���� ���丮
		GameEngineDirectory ResourcesCharacterDir;
		//API���� �ö󰡰�
		ResourcesCharacterDir.MoveParent("API");
		ResourcesCharacterDir.Move("Resources");
		ResourcesCharacterDir.Move("Character");


		// �����ȿ� ��� �̹��� ������ ã�´�.
		std::vector<GameEngineFile> AllImageFileList = ResourcesCharacterDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}
	{
		//GameEngineImageManager::GetInst()->/*Load("���", "�̸�");*/
			// ���� ���丮
		GameEngineDirectory ResourcesMapDir;
		//API���� �ö󰡰�
		ResourcesMapDir.MoveParent("API");
		ResourcesMapDir.Move("Resources");
		ResourcesMapDir.Move("Map");


		// �����ȿ� ��� �̹��� ������ ã�´�.
		std::vector<GameEngineFile> AllImageFileList = ResourcesMapDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}
	{
		//GameEngineImageManager::GetInst()->/*Load("���", "�̸�");*/
			// ���� ���丮
		GameEngineDirectory ResourcesBlockDir;
		//API���� �ö󰡰�
		ResourcesBlockDir.MoveParent("API");
		ResourcesBlockDir.Move("Resources");
		ResourcesBlockDir.Move("Block");


		// �����ȿ� ��� �̹��� ������ ã�´�.
		std::vector<GameEngineFile> AllImageFileList = ResourcesBlockDir.GetAllFile("Bmp");

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
	}
	{
		//GameEngineImageManager::GetInst()->/*Load("���", "�̸�");*/
			// ���� ���丮
		GameEngineDirectory ResourcesUIDir;
		//API���� �ö󰡰�
		ResourcesUIDir.MoveParent("API");
		ResourcesUIDir.Move("Resources");
		ResourcesUIDir.Move("TiTle&UI");


		// �����ȿ� ��� �̹��� ������ ã�´�.
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