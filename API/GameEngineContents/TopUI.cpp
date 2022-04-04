#include "TopUI.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineTime.h>



#include <GameEngine/GameEngineImage.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineCollision.h>
#include <Windows.h>
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

	
Three_ = CreateRenderer("number.bmp");
Two_ = CreateRenderer("number.bmp");;
One_ = CreateRenderer("number.bmp");;
	GameEngineRenderer * Top = CreateRenderer("TOP.bmp");
	float4 TopUIPivot = GameEngineWindow::GetScale().Half();
	Top->SetPivot(float4(640, 81));
	Top->SetTransColor(RGB(92, 148, 252));
	Top->CameraEffectOff();
	Three_->CameraEffectOff();
	Three_->SetTransColor(RGB(146, 144, 255));
	Three_->SetIndex(0);
	Three_->SetPivot(float4(1065, 145));
	Two_->CameraEffectOff();
	Two_->SetTransColor(RGB(146, 144, 255));
	Two_->SetPivot(float4(1105, 145));
	One_->CameraEffectOff();
	One_->SetTransColor(RGB(146, 144, 255));
	One_->SetPivot(float4(1145, 145));

	Three_->CreateAnimation("numberreverse.bmp", "100", 6,9, 100.0f, true);
	Three_->CreateAnimation("numberreverse.bmp", "Start", 5, 5, 100.0f, false);
	Three_->CreateAnimation("blank.bmp", "End", 0, 0, 100.0f, false);
	Two_->CreateAnimation("numberreverse.bmp", "10", 0, 9, 10.0f, true);
	Two_->CreateAnimation("numberreverse.bmp", "Start", 9, 9, 10.0f, false);
	Two_->CreateAnimation("blank.bmp", "End", 0, 0, 100.0f, false);
	One_->CreateAnimation("numberreverse.bmp", "1", 0, 9, 1.0f, true);
	One_->CreateAnimation("numberreverse.bmp", "Start", 9, 9, 1.0f, false);
	One_->CreateAnimation("blank.bmp", "End", 0, 0, 100.0f, false);

	One_->ChangeAnimation("Start");
	Two_->ChangeAnimation("Start");
	Three_->ChangeAnimation("Start");


	

	
	
	//CreateRenderer("mollu.bmp");

}

void TopUI::Update()
{
	
	Time_ = Time_ - GameEngineTime::GetDeltaTime();
	if (Start_ = true)
	{
		
		One_->ChangeAnimation("1");
		Two_->ChangeAnimation("10");
		Three_->ChangeAnimation("100");
		Start_ = false;
	}

	if (Time_ < 100)
	{
		Three_->ChangeAnimation("End");

	}
	if (Time_ < 10)
	{
		Two_->ChangeAnimation("End");
	}
	if (Time_ < 1)
	{
		One_->ChangeAnimation("End");
	}


	
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