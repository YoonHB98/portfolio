#include "TitleBackGround.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineInput.h>
#include<GameEngine/GameEngine.h>
#include <GameEngine/GameEngineLevel.h>
#include <GameEngine/GameEngineRenderer.h>

TitleBackGround::TitleBackGround() 
{
}

TitleBackGround::~TitleBackGround() 
{
}

void TitleBackGround::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());



	GameEngineRenderer* Name = CreateRenderer("Name.bmp");
	Name->SetPivot(float4(220, 100));
	Name->SetTransColor(RGB(148, 148, 255));
	Name->CameraEffectOff();


	CreateRenderer("TITLE.BMP");
	
		GameEngineInput::GetInst()->CreateKey("Play", VK_RETURN);
	

}

void TitleBackGround::Update()
{
	if (true == GameEngineInput::GetInst()->IsPress("Play"))
	{
		GameEngine::GetInst().ChangeLevel("StageIntro");
	}
}

void TitleBackGround::Render()
{

}