#include "Player.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineImage.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineRenderer.h>
#include <Windows.h>



#include <GameEngine/GameEngineLevel.h> // 레벨을 통해서
// #include "이걸 " 만들때 
Player::Player()
	: Speed_(650.0f)
	, Gravity_(500.0f)
{
}

Player::~Player()
{
}



void Player::Start()
{
	Right = 0;
	Left = 0;
	//SetPosition(float4{ 0, 1078 });

	RenderRun = CreateRenderer("Mario.bmp");
	RenderRun->SetTransColor(RGB(146, 144, 255));
	RenderRun->SetIndex(0);
	RenderRun->CreateAnimation("Mario.bmp", "MarioRight", 0, 0, 0.1f, false);
	RenderRun->CreateAnimation("Mario.bmp", "MarioLeft", 1, 1, 0.1f, false);
	RenderRun->CreateAnimation("Mario.bmp", "RunRight", 2, 4, 0.1f, true);
	RenderRun->CreateAnimation("Mario.bmp", "RunLeft", 5, 7, 0.1f, true);
	RenderRun->CreateAnimation("Mario.bmp", "TurnRight", 8, 8, 100.0f, false);
	RenderRun->CreateAnimation("Mario.bmp", "TurnLeft", 9, 9, 20.0f, false);
	RenderRun->CreateAnimation("Mario.bmp", "JumpRight", 10, 10, 0.1f, false);
	RenderRun->CreateAnimation("Mario.bmp", "JumpLeft", 11, 11, 0.1f, false);

	

	if (false == GameEngineInput::GetInst()->IsKey("MoveLeft"))
	{
		// 이때 대문자여야 합니다.
		GameEngineInput::GetInst()->CreateKey("MoveLeft", 'A');
		GameEngineInput::GetInst()->CreateKey("MoveRight", 'D');
		GameEngineInput::GetInst()->CreateKey("Jump", VK_LSHIFT);
		// VK_LBUTTON; 마우스
	}
}

void Player::Update()
{
	GameEngineImage* WhiteMap_ = GameEngineImageManager::GetInst()->Find("11mapWhite.bmp");

	if (nullptr == WhiteMap_)
	{
		MsgBoxAssert("맵 충돌용 이미지를 찾지 못했습니다.")
	}
	//bool Down_; // 최초 키를 눌렀을때
	//bool Press_; // 그 이후로 지속적으로 누르고 있을때.
	//bool Up_; // 누르다가 땠을때 
	//bool Free_; // 안누르고 있을때.
	//RenderRun->ChangeAnimation("MarioRight");
	float4 CheckPos;
	float4 MoveDir = float4::ZERO;

	GetLevel()->SetCameraPos(GetPosition() - GameEngineWindow::GetInst().GetScale().Half());


	while (Right != 0)
	{
		RenderRun->ChangeAnimation("TurnRight");
		Right = Right - 1;
		MoveDir = float4::LEFT;
		SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		return;
	}
	while (Left != 0)
	{
		RenderRun->ChangeAnimation("TurnLeft");
		Left  = Left - 1;
		MoveDir = float4::RIGHT;
		SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		return;
	}

		if (RenderRun->CurrentAnimation("RunRight"))
		{
			if (true == (GameEngineInput::GetInst()->IsDown("MoveLeft") || GameEngineInput::GetInst()->IsPress("MoveLeft")))
			{

				RenderRun->ChangeAnimation("TurnLeft");
				MoveDir = float4::RIGHT ;
				Left = 120;
				return;
			}
		}
	
		if (RenderRun->CurrentAnimation("RunLeft"))
		{
			if (true == (GameEngineInput::GetInst()->IsDown("MoveRight") || GameEngineInput::GetInst()->IsPress("MoveRight")))
			{

				RenderRun->ChangeAnimation("TurnRight");
				MoveDir = float4::LEFT;
				Right = 120;
				return;
			}
		}

	
	
	if (true == GameEngineInput::GetInst()->IsPress("MoveLeft"))
	{

		RenderRun->ChangeAnimation("RunLeft");

		MoveDir = float4::LEFT;
		
	}
	
	if (true == GameEngineInput::GetInst()->IsUp("MoveLeft"))
	{
		RenderRun->ChangeAnimation("MarioLeft");
		

	}
	
	if (true == GameEngineInput::GetInst()->IsPress("MoveRight"))
	{
		RenderRun->ChangeAnimation("RunRight");
	

		MoveDir = float4::RIGHT;
		
	}
	
	if (true == GameEngineInput::GetInst()->IsUp("MoveRight"))
	{
		RenderRun->ChangeAnimation("MarioRight");
		
	}

	if (true == GameEngineInput::GetInst()->IsPress("Jump"))
	{
		if (RenderRun->CurrentAnimation("RunRight") || RenderRun->CurrentAnimation("MarioRight"))
		{
			RenderRun->ChangeAnimation("JumpRight");
		}
		else
		{
			RenderRun->ChangeAnimation("JumpLeft");
		}
		MoveDir = float4::UP;
		
	}

	// 내가 키를 눌렀다면 움직여라.
	//if (0 != GetAsyncKeyState('A'))
	//{
	//	int a = 0;
	//}


	{
		float4 NextPos = GetPosition() + (MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		float4 CheckPos = NextPos- float4(0.0f, 130.0f);
		int Color = WhiteMap_->GetImagePixel(CheckPos );
		
		if (RGB(255, 255, 255) == Color)
		{
			SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		}
	}
	{
		int Color = WhiteMap_->GetImagePixel(GetPosition() - float4(0.0f, 120.0f));
		AccGravity_ += GameEngineTime::GetDeltaTime() * Gravity_;
		if (RGB(0, 0, 255) == Color)
		{
			AccGravity_ = 0.0f;
		}
		SetMove(float4::DOWN * GameEngineTime::GetDeltaTime() * AccGravity_);
	}

}

// 랜더러가 다 돌아가고 랜더링
void Player::Render()
{

}
