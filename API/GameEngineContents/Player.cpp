#include "Player.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineImage.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineRenderer.h>
#include <Windows.h>



#include <GameEngine/GameEngineLevel.h> // ������ ���ؼ�
// #include "�̰� " ���鶧 
Player::Player()
	: Speed_(100.0f)
	, Gravity_(1.0f)
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
		// �̶� �빮�ڿ��� �մϴ�.
		GameEngineInput::GetInst()->CreateKey("MoveLeft", 'A');
		GameEngineInput::GetInst()->CreateKey("MoveRight", 'D');
		GameEngineInput::GetInst()->CreateKey("Jump", VK_LSHIFT);
		// VK_LBUTTON; ���콺
	}
}

void Player::Update()
{
	GameEngineImage* WhiteMap_ = GameEngineImageManager::GetInst()->Find("11mapWhite.bmp");
	if (nullptr == WhiteMap_)
	{
		MsgBoxAssert("�� �浹�� �̹����� ã�� ���߽��ϴ�.")
	}
	//bool Down_; // ���� Ű�� ��������
	//bool Press_; // �� ���ķ� ���������� ������ ������.
	//bool Up_; // �����ٰ� ������ 
	//bool Free_; // �ȴ����� ������.
	//RenderRun->ChangeAnimation("MarioRight");
	float4 CheckPos;
	float4 MoveDir = float4::ZERO;
	int Color = WhiteMap_->GetImagePixel(GetPosition() - float4(0.0f,120.0f));
	AccGravity_ += GameEngineTime::GetDeltaTime() * Gravity_;
	if (RGB(0, 0, 255) == Color)
	{
		AccGravity_ = 0.0f;

	}
	GetLevel()->SetCameraPos(GetPosition() - GameEngineWindow::GetInst().GetScale().Half());

	SetMove(float4::DOWN * AccGravity_);
	while (Right != 0)
	{
		RenderRun->ChangeAnimation("TurnRight");
		Right = Right - 1;
		SetMove(float4::LEFT * GameEngineTime::GetDeltaTime() * 200);
		Sleep(GameEngineTime::GetDeltaTime() * 20);
		return;
	}
	while (Left != 0)
	{
		RenderRun->ChangeAnimation("TurnLeft");
		Left  = Left - 1;
		SetMove(float4::RIGHT * GameEngineTime::GetDeltaTime() * 200);
		Sleep(GameEngineTime::GetDeltaTime() * 20);
		return;
	}

		if (RenderRun->CurrentAnimation("RunRight"))
		{
			if (true == (GameEngineInput::GetInst()->IsDown("MoveLeft") || GameEngineInput::GetInst()->IsPress("MoveLeft")))
			{

				RenderRun->ChangeAnimation("TurnLeft");
				SetMove(float4::RIGHT * GameEngineTime::GetDeltaTime() * 200);
				Sleep(GameEngineTime::GetDeltaTime() * 20);
				Left = 80;
				return;
			}
		}
	
		if (RenderRun->CurrentAnimation("RunLeft"))
		{
			if (true == (GameEngineInput::GetInst()->IsDown("MoveRight") || GameEngineInput::GetInst()->IsPress("MoveRight")))
			{

				RenderRun->ChangeAnimation("TurnRight");
				SetMove(float4::RIGHT * GameEngineTime::GetDeltaTime() * 200);
				Sleep(GameEngineTime::GetDeltaTime() * 20);
				Right = 80;
				return;
			}
		}
	//if (true == GameEngineInput::GetInst()->IsUp("MoveLeft"))
	//{
	//	if (true == (GameEngineInput::GetInst()->IsDown("MoveRight") || GameEngineInput::GetInst()->IsPress("MoveRight")))
	//	{
	//		RenderRun->ChangeAnimation("TurnRight");
	//	
	//		SetMove(float4::LEFT * GameEngineTime::GetDeltaTime() * 200);
	//		Sleep(GameEngineTime::GetDeltaTime() * 20);
	//		Right = 100;
	//	}
	//}
	
	if (true == GameEngineInput::GetInst()->IsPress("MoveLeft"))
	{

		RenderRun->ChangeAnimation("RunLeft");

		SetMove(float4::LEFT * GameEngineTime::GetDeltaTime() * 500);
		
	}
	
	if (true == GameEngineInput::GetInst()->IsUp("MoveLeft"))
	{
		RenderRun->ChangeAnimation("MarioLeft");
		return;

	}
	
	if (true == GameEngineInput::GetInst()->IsPress("MoveRight"))
	{
		RenderRun->ChangeAnimation("RunRight");
	

		SetMove(float4::RIGHT * GameEngineTime::GetDeltaTime() * 500);
		
	}
	
	if (true == GameEngineInput::GetInst()->IsUp("MoveRight"))
	{
		RenderRun->ChangeAnimation("MarioRight");
		return;
	}

	if (true == GameEngineInput::GetInst()->IsPress("Jump"))
	{
		RenderRun->ChangeAnimation("JumpRight");
		SetMove(float4::UP * GameEngineTime::GetDeltaTime() * 1000);
		return;
	}

	// ���� Ű�� �����ٸ� ��������.
	//if (0 != GetAsyncKeyState('A'))
	//{
	//	int a = 0;
	//}

}

// �������� �� ���ư��� ������
void Player::Render()
{

}
