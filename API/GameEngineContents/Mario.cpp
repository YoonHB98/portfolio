#include "Mario.h"
#include "Stage1.h"
#include "EndingLevel.h"
#include "TitleLevel.h"
#include "StageIntro.h"
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
	//���� 256 220
	GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 0, 0}, { 620, 600 });

	
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
		GameEngineDirectory ResourcesMapDir;
		//API���� �ö󰡰�
		ResourcesMapDir.MoveParent("API");
		ResourcesMapDir.Move("Resources");
		ResourcesMapDir.Move("Sound");


		// �����ȿ� ��� �̹��� ������ ã�´�.
		std::vector<GameEngineFile> AllImageFileList = ResourcesMapDir.GetAllFile();

		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineSound::LoadRes(AllImageFileList[i].GetFullPath());
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
		//GameEngineImageManager::GetInst()->/*Load("���", "�̸�");*/
			// ���� ���丮
		GameEngineDirectory ResourcesUIDir;
		//API���� �ö󰡰�
		ResourcesUIDir.MoveParent("API");
		ResourcesUIDir.Move("Resources");
		ResourcesUIDir.Move("Item");


		// �����ȿ� ��� �̹��� ������ ã�´�.
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
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("BlockBreak.bmp");
		Image->Cut({ 20,20 });
	}
	CreateLevel<TitleLevel>("Title");
	CreateLevel<Stage1>("Stage1");
	CreateLevel<EndingLevel>("Ending");
	CreateLevel<StageIntro>("StageIntro");
	ChangeLevel("Title");
}

void Mario::GameLoop()
{

}
void Mario::GameEnd()
{

}