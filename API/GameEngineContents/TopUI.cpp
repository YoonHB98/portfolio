#include "TopUI.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>





TopUI::TopUI()
{
}

TopUI::~TopUI()
{
}


void TopUI::Start()
{

	SetPosition({ 680, 50 });
	//SetPosition({ 680, 100 });
	SetScale({ 100, 200 });

	CreateRenderer("TOP.bmp");



	
	
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