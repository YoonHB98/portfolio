#include "TopUI.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineTime.h>
#include "Pause.h"



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

	Three_->CreateAnimation("number.bmp", "1", 0, 0, 1.0f, false);
	Three_->CreateAnimation("number.bmp", "2", 1, 1, 1.0f, false);
	Three_->CreateAnimation("number.bmp", "3", 2, 2, 1.0f, false);
	Three_->CreateAnimation("number.bmp", "4", 3, 3, 1.0f, false);
	Three_->CreateAnimation("number.bmp", "5", 4, 4, 1.0f, false);
	Three_->CreateAnimation("number.bmp", "6", 5, 5, 1.0f, false);
	Three_->CreateAnimation("number.bmp", "7", 6, 6, 1.0f, false);
	Three_->CreateAnimation("number.bmp", "8", 7, 7, 1.0f, false);
	Three_->CreateAnimation("number.bmp", "9", 8, 8, 1.0f, false);
	Three_->CreateAnimation("number.bmp", "0", 9, 9, 1.0f, false);
	Two_->CreateAnimation("number.bmp", "1", 0, 0, 1.0f, false);
	Two_->CreateAnimation("number.bmp", "2", 1, 1, 1.0f, false);
	Two_->CreateAnimation("number.bmp", "3", 2, 2, 1.0f, false);
	Two_->CreateAnimation("number.bmp", "4", 3, 3, 1.0f, false);
	Two_->CreateAnimation("number.bmp", "5", 4, 4, 1.0f, false);
	Two_->CreateAnimation("number.bmp", "6", 5, 5, 1.0f, false);
	Two_->CreateAnimation("number.bmp", "7", 6, 6, 1.0f, false);
	Two_->CreateAnimation("number.bmp", "8", 7, 7, 1.0f, false);
	Two_->CreateAnimation("number.bmp", "9", 8, 8, 1.0f, false);
	Two_->CreateAnimation("number.bmp", "0", 9, 9, 1.0f, false);
	One_->CreateAnimation("number.bmp", "1", 0, 0, 1.0f, false);
	One_->CreateAnimation("number.bmp", "2", 1, 1, 1.0f, false);
	One_->CreateAnimation("number.bmp", "3", 2, 2, 1.0f, false);
	One_->CreateAnimation("number.bmp", "4", 3, 3, 1.0f, false);
	One_->CreateAnimation("number.bmp", "5", 4, 4, 1.0f, false);
	One_->CreateAnimation("number.bmp", "6", 5, 5, 1.0f, false);
	One_->CreateAnimation("number.bmp", "7", 6, 6, 1.0f, false);
	One_->CreateAnimation("number.bmp", "8", 7, 7, 1.0f, false);
	One_->CreateAnimation("number.bmp", "9", 8, 8, 1.0f, false);
	One_->CreateAnimation("number.bmp", "0", 9, 9, 1.0f, false);
	Three_->ChangeAnimation("0");
	Two_->ChangeAnimation("0");
	One_->ChangeAnimation("0");
	Start_ = true;
	Time_ = 400;
	

	
	
	//CreateRenderer("mollu.bmp");

}

void TopUI::Update()
{
	
	if (Pause::pause || Pause::end ||Pause::death)
	{
		return;
	}
	Time_ = Time_ - GameEngineTime::GetDeltaTime() * 2;
	int TimeTwo = static_cast<int>(Time_) /(10);
	int TimeThree = static_cast<int>(Time_) / (100);

	if ((0 == static_cast<int>(Time_) % 10))
	{
		One_->ChangeAnimation("0");
	}
	if (1 == static_cast<int>(Time_) % 10)
	{
		One_->ChangeAnimation("1");
	}
	if (2 == static_cast<int>(Time_) % 10)
	{
		One_->ChangeAnimation("2");
	}
	if (3 == static_cast<int>(Time_) % 10)
	{
		One_->ChangeAnimation("3");
	}
	if (4 == static_cast<int>(Time_) % 10)
	{
		One_->ChangeAnimation("4");
	}
	if (5 == static_cast<int>(Time_) % 10)
	{
		One_->ChangeAnimation("5");
	}
	if (6 == static_cast<int>(Time_) % 10)
	{
		One_->ChangeAnimation("6");
	}
	if (7 == static_cast<int>(Time_) % 10)
	{
		One_->ChangeAnimation("7");
	}
	if (8 == static_cast<int>(Time_) % 10)
	{
		One_->ChangeAnimation("8");
	}
	if (9 == static_cast<int>(Time_) % 10)
	{
		One_->ChangeAnimation("9");
	}
	if ((0 == static_cast<int>(TimeTwo) % 10))
	{
		Two_->ChangeAnimation("0");
	}
	if (1 == static_cast<int>(TimeTwo) % 10)
	{
		Two_->ChangeAnimation("1");
	}
	if (2 == static_cast<int>(TimeTwo) % 10)
	{
		Two_->ChangeAnimation("2");
	}
	if (3 == static_cast<int>(TimeTwo) % 10)
	{
		Two_->ChangeAnimation("3");
	}
	if (4 == static_cast<int>(TimeTwo) % 10)
	{
		Two_->ChangeAnimation("4");
	}
	if (5 == static_cast<int>(TimeTwo) % 10)
	{
		Two_->ChangeAnimation("5");
	}
	if (6 == static_cast<int>(TimeTwo) % 10)
	{
		Two_->ChangeAnimation("6");
	}
	if (7 == static_cast<int>(TimeTwo) % 10)
	{
		Two_->ChangeAnimation("7");
	}
	if (8 == static_cast<int>(TimeTwo) % 10)
	{
		Two_->ChangeAnimation("8");
	}
	if (9 == static_cast<int>(TimeTwo) % 10)
	{
		Two_->ChangeAnimation("9");
	}
	if ((0 == static_cast<int>(TimeThree) % 10))
	{
		Three_->ChangeAnimation("0");
	}
	if (1 == static_cast<int>(TimeThree) % 10)
	{
		Three_->ChangeAnimation("1");
	}
	if (2 == static_cast<int>(TimeThree) % 10)
	{
		Three_->ChangeAnimation("2");
	}
	if (3 == static_cast<int>(TimeThree) % 10)
	{
		Three_->ChangeAnimation("3");
	}
	if (4 == static_cast<int>(TimeThree) % 10)
	{
		Three_->ChangeAnimation("4");
	}
	if (5 == static_cast<int>(TimeThree) % 10)
	{
		Three_->ChangeAnimation("5");
	}
	if (6== static_cast<int>(TimeThree) % 10)
	{
		Three_->ChangeAnimation("6");
	}
	if (7 == static_cast<int>(TimeThree) % 10)
	{
		Three_->ChangeAnimation("7");
	}
	if (8 == static_cast<int>(TimeThree) % 10)
	{
		Three_->ChangeAnimation("8");
	}
	if (9 == static_cast<int>(TimeThree) % 10)
	{
		Three_->ChangeAnimation("9");
	}
}
void TopUI::TimerReset()
{
	Time_ = 400;
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