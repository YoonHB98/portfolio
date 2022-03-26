#include "Mario.h"
#include "PlayLevel.h"
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
	GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 0, 0}, { 1360, 1280 });

	

	//GameEngineImageManager::GetInst()->/*Load("경로", "이름");*/
		// 현재 디렉토리
	GameEngineDirectory ResourcesDir;
	//API까지 올라가고
	ResourcesDir.MoveParent("API");
	ResourcesDir.Move("Resources");
	ResourcesDir.Move("Image");

	// 폴더안에 모든 이미지 파일을 찾는다.
	std::vector<GameEngineFile> AllImageFileList = ResourcesDir.GetAllFile("Bmp");

	for (size_t i = 0; i < AllImageFileList.size(); i++)
	{
		GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
	}



	CreateLevel<TitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");
	CreateLevel<EndingLevel>("Ending");
	ChangeLevel("Play");
}

void Mario::GameLoop()
{

}
void Mario::GameEnd()
{

}