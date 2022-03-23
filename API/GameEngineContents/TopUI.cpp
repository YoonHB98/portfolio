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

	SetPosition({ 680, 50 });
	//SetPosition({ 680, 100 });
	SetScale({ 100, 200 });
	CreateRendererToScale("TOP.bmp", float4(1360.0f, 140.0f), RenderPivot::CENTER, float4(0.0f, 0.0f));

	
	
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