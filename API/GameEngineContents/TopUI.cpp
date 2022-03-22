#include "TopUI.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>

TopUI::TopUI()
{
}

TopUI::~TopUI()
{
}


void TopUI::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());
	//SetPosition({ 680, 100 });
	SetScale({ 1360, 200 });
	//CreateRenderer("mollu.bmp");

}

//랜더러가 다 돌아가고 랜더링
void TopUI::Render()
{
	//GameEngineImage* FindImage = GameEngineImageManager::GetInst()->Find("mollu.bmp");
	//if (nullptr == FindImage)
	//{
	//	MsgBoxAssert("error!");
	//}
	//GameEngine::BackBufferImage()->BitCopyBot(FindImage, GetPosition());
}