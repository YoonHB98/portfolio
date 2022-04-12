#include "TitleBackGround.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineInput.h>
#include<GameEngine/GameEngine.h>
#include <GameEngine/GameEngineLevel.h>

TitleBackGround::TitleBackGround() 
{
}

TitleBackGround::~TitleBackGround() 
{
}

void TitleBackGround::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());






	CreateRenderer("TITLE.BMP");
	
		GameEngineInput::GetInst()->CreateKey("Play", VK_RETURN);
	

}

void TitleBackGround::Update()
{
	if (true == GameEngineInput::GetInst()->IsPress("Play"))
	{
		GameEngine::GetInst().ChangeLevel("Stage1");
	}
}

void TitleBackGround::Render()
{

}