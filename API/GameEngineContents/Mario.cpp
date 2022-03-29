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
	GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 0, 0}, { 1224, 1148 });

	

	//GameEngineImageManager::GetInst()->/*Load("���", "�̸�");*/
		// ���� ���丮
	GameEngineDirectory ResourcesDir;
	//API���� �ö󰡰�
	ResourcesDir.MoveParent("API");
	ResourcesDir.Move("Resources");
	ResourcesDir.Move("Image");

	// �����ȿ� ��� �̹��� ������ ã�´�.
	std::vector<GameEngineFile> AllImageFileList = ResourcesDir.GetAllFile("Bmp");

	for (size_t i = 0; i < AllImageFileList.size(); i++)
	{
		GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
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