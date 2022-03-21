#include "Mario.h"
#include "PlayLevel.h"
#include "EndingLevel.h"
#include "TitleLevel.h"
#include <GameEngineBase/GameEngineWindow.h>
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

	// 리소스를 다 로드하지 못하는 상황이 올수가 없다.

	//GameEngineImageManager::GetInst()->/*Load("경로", "이름");*/



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