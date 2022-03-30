#include "TopUI.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>

#pragma comment(lib, "msimg32.lib")



TopUI::TopUI()
{
}

TopUI::~TopUI()
{
}


void TopUI::Start()
{


	//SetPosition({ 680, 100 });



	GameEngineRenderer * Top = CreateRenderer("TOP.bmp");
	float4 TopUIPivot = GameEngineWindow::GetScale().Half();
	Top->SetPivot(float4(640, 81));
	Top->SetTransColor(RGB(146, 144, 255));


	
	
	//CreateRenderer("mollu.bmp");

}

//�������� �� ���ư��� ������
void TopUI::Render()
{
	//GameEngineImage* FindImage = GameEngineImageManager::GetInst()->Find("mollu.bmp");
	//if (nullptr == FindImage)
	//{
	//	MsgBoxAssert("error!");
	//}
	//GameEngine::BackBufferImage()->BitCopyBot(FindImage, GetPosition());
}