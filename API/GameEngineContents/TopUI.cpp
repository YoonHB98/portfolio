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

	

	GameEngineRenderer * Top = CreateRenderer("TOP.bmp");
	Three_ = CreateRenderer("number.bmp");
	Two_ = CreateRenderer("number.bmp");;
	One_ = CreateRenderer("number.bmp");;
	float4 TopUIPivot = GameEngineWindow::GetScale().Half();
	GameEngineRenderer* Name= CreateRenderer("Name.bmp");
	Name->SetPivot(float4(100, 50));
	Name->CameraEffectOff();
	Top->SetPivot(float4(310, 41));
	Top->CameraEffectOff();
	Three_->CameraEffectOff();
	Three_->SetIndex(0);
	Three_->SetPivot(float4(520, 70));
	Two_->CameraEffectOff();
	Two_->SetPivot(float4(540, 70));
	One_->CameraEffectOff();
	One_->SetPivot(float4(560, 70));

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

	Start_ = true;
	Time_ = 400;
	

	
	
	//CreateRenderer("mollu.bmp");

}

void TopUI::Update()
{
	
	Time_ = Time_ - GameEngineTime::GetDeltaTime();
	if (Start_ == true)
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
void TopUI::TimerReset()
{
	Time_ = 400;
	One_->ChangeAnimation("Start");
	Two_->ChangeAnimation("Start");
	Three_->ChangeAnimation("Start");
	Start_ = true;
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