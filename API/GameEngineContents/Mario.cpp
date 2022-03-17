#include "Mario.h"
#include "PlayLevel.h"
#include "TitleLevel.h"
#include  "EndingLevel.h"
#include <GameEngineBase/GameEngineWindow.h>

Mario::Mario() 
{
}

Mario::~Mario() 
{
}

void Mario::GameInit()
{
	GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 100, 100 }, { 1280, 720 });

	CreateLevel<TitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");
	CreateLevel<EndingLevel>("Ending");
	ChangeLevel("Title");
}
void Mario::GameLoop()
{

}
void Mario::GameEnd()
{

}

