#include "Player.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineImage.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineCollision.h>
#include <Windows.h>



#include <GameEngine/GameEngineLevel.h> // ������ ���ؼ�
// #include "�̰� " ���鶧 
Player::Player()
	: Speed_(2500.0f)
	, Gravity_(500.0f)
{
}

Player::~Player()
{
}



void Player::Start()
{
	//PlayerCollision = CreateCollision("PlayerHitBox", { 100, 100 });
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
		GameEngineInput::GetInst()->CreateKey("Down", 'S');
		// VK_LBUTTON; ���콺
	}
}

void Player::Update()
{
	WhiteMap_ = GameEngineImageManager::GetInst()->Find("11mapWhite.bmp");

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
	float MapSizeX = 16881;
	float MapSizeY = 1200;
	float CameraRectX = 1280;
	float CameraRectY = 1200;

	GetLevel()->SetCameraPos(GetPosition() - GameEngineWindow::GetInst().GetScale().Half());
	if (0 > GetLevel()->GetCameraPos().x)
	{
		float4 CurCameraPos = GetLevel()->GetCameraPos();
		CurCameraPos.x = 0;
		GetLevel()->SetCameraPos(CurCameraPos);
	}
	if (0 > GetLevel()->GetCameraPos().y)
	{
		float4 CurCameraPos = GetLevel()->GetCameraPos();
		CurCameraPos.y = GetLevel()->GetCameraPos().y - (GetLevel()->GetCameraPos().y);
		GetLevel()->SetCameraPos(CurCameraPos);
	}
	if (MapSizeX <= GetLevel()->GetCameraPos().x)
	{
		float4 CurCameraPos = GetLevel()->GetCameraPos();
		CurCameraPos.x = GetLevel()->GetCameraPos().x - (GetLevel()->GetCameraPos().x + CameraRectX - MapSizeX);
		GetLevel()->SetCameraPos(CurCameraPos);
	}
	if (MapSizeY <= (GetLevel()->GetCameraPos().y + CameraRectY))
	{
		float4 CurCameraPos = GetLevel()->GetCameraPos();
		CurCameraPos.y = GetLevel()->GetCameraPos().y - (GetLevel()->GetCameraPos().y);
		GetLevel()->SetCameraPos(CurCameraPos);
	}
	
	while (Right != 0)
	{
		RenderRun->ChangeAnimation("TurnRight");
		Right = Right - 1;
		MoveDir = float4::LEFT;
		{
			float4 NextPos = GetPosition() + (MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
			float4 CheckPos = NextPos - float4(0.0f, 40.0f);
			CheckPos = CheckPos + MoveDir * float4(40.0f, 1.0f, 1.0f, 1.0f);
			int Color = WhiteMap_->GetImagePixel(CheckPos);

			if (RGB(255, 255, 255) == Color)
			{
				SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
			}
		}
		{
			int Color = WhiteMap_->GetImagePixel(GetPosition() + float4(0.0f, 40.0f));
			AccGravity_ += GameEngineTime::GetDeltaTime() * Gravity_;
			if (RGB(0, 0, 0) == Color)
			{

				AccGravity_ = 0.0f;
			}
			SetMove(float4::DOWN * GameEngineTime::GetDeltaTime() * AccGravity_);
		}

		return;
	}
	while (Left != 0)
	{
		RenderRun->ChangeAnimation("TurnLeft");
		Left  = Left - 1;
		MoveDir = float4::RIGHT;
		{
			float4 NextPos = GetPosition() + (MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
			float4 CheckPos = NextPos - float4(0.0f, 40.0f);
			CheckPos = CheckPos + MoveDir * float4(40.0f, 1.0f, 1.0f, 1.0f);
			int Color = WhiteMap_->GetImagePixel(CheckPos);

			if (RGB(255, 255, 255) == Color)
			{
				SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
			}
		}
		{
			int Color = WhiteMap_->GetImagePixel(GetPosition() + float4(0.0f, 40.0f));
			AccGravity_ += GameEngineTime::GetDeltaTime() * Gravity_;
			if (RGB(0, 0, 0) == Color)
			{
				AccGravity_ = 0.0f;
			}
			SetMove(float4::DOWN * GameEngineTime::GetDeltaTime() * AccGravity_);
		}

		return;
	}

		if (RenderRun->CurrentAnimation("RunRight"))
		{
			if (false == GameEngineInput::GetInst()->IsPress("MoveRight"))
			{
				if (true == (GameEngineInput::GetInst()->IsDown("MoveLeft") || GameEngineInput::GetInst()->IsPress("MoveLeft")))
				{

					RenderRun->ChangeAnimation("TurnLeft");
					MoveDir = float4::RIGHT;
					Left = 120;
					return;
				}
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
	
	if (true == GameEngineInput::GetInst()->IsPress("Down"))
	{

	

		MoveDir = float4::DOWN;

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
		else if (RenderRun->CurrentAnimation("RunLeft") || RenderRun->CurrentAnimation("MarioLeft"))
		{
			RenderRun->ChangeAnimation("JumpLeft");
		}
		MoveDir = float4::UP;
		
	}

	if (true == (GameEngineInput::GetInst()->IsPress("Jump") && GameEngineInput::GetInst()->IsPress("MoveLeft")))
	{
		MoveDir = float4(-1.0f, -1.0f, 0.0f, 1.0f);
	}
	if (true == (GameEngineInput::GetInst()->IsPress("Jump") && GameEngineInput::GetInst()->IsPress("MoveRight")))
	{
		MoveDir = float4(1.0f, -1.0f, 0.0f, 1.0f);
	}

	// ���� Ű�� �����ٸ� ��������.
	//if (0 != GetAsyncKeyState('A'))
	//{
	//	int a = 0;
	//}


	{
		float4 NextPos = GetPosition() + (MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		float4 CheckPos = NextPos;
		int Color_UpLeft = WhiteMap_->GetImagePixel(CheckPos + float4(-40.0f, -40.0f));
		int Color_UpRight = WhiteMap_->GetImagePixel(CheckPos+ float4(40.0f, -40.0f));
		int Color_DownRight = WhiteMap_->GetImagePixel(CheckPos + float4(-40.0f, 40.0f));
		int Color_DownLeft = WhiteMap_->GetImagePixel(CheckPos + float4(+40.0f, 40.0f));
		

		
		if (RGB(0, 0, 0)!= (Color_UpLeft))
		{
			if (RGB(0, 0, 0) != (Color_UpRight))
			{
				if (RGB(0, 0, 0) != (Color_DownRight))
				{
					if (RGB(0, 0, 0) != (Color_DownLeft))
					{
						SetMove(MoveDir* GameEngineTime::GetDeltaTime()* Speed_);
					}
				}
			}
		}
		
	}
	{

		//int Color = WhiteMap_->GetImagePixel(GetPosition() + float4(0.0f, 40.0f));
		//AccGravity_ += GameEngineTime::GetDeltaTime() * Gravity_;
		//if (RGB(0, 0, 0) == Color)
		//{
		//	if (RenderRun->CurrentAnimation("JumpLeft"))
		//	{
		//		RenderRun->ChangeAnimation("MarioLeft");
		//	}
		//	else
		//		if (RenderRun->CurrentAnimation("JumpRight"))
		//		{
		//			RenderRun->ChangeAnimation("MarioRight");
		//		}
		//	AccGravity_ = 0.0f;
		//}
		//SetMove(float4::DOWN * GameEngineTime::GetDeltaTime() * AccGravity_);
	}

	if (0 > GetLevel()->GetCameraPos().x)
	{
		float4 CurCameraPos = GetLevel()->GetCameraPos();
		CurCameraPos.x = 0;
		GetLevel()->SetCameraPos(CurCameraPos);
	}
	if (0 > GetLevel()->GetCameraPos().y)
	{
		float4 CurCameraPos = GetLevel()->GetCameraPos();
		CurCameraPos.y = 0;
		GetLevel()->SetCameraPos(CurCameraPos);
	}
	if (MapSizeX <= GetLevel()->GetCameraPos().x)
	{
		float4 CurCameraPos = GetLevel()->GetCameraPos();
		CurCameraPos.x = GetLevel()->GetCameraPos().x - (GetLevel()->GetCameraPos().x + CameraRectX - MapSizeX);
		GetLevel()->SetCameraPos(CurCameraPos);
	}
	if (MapSizeY <=( GetLevel()->GetCameraPos().y  + 640))
	{
		float4 CurCameraPos = GetLevel()->GetCameraPos();
		CurCameraPos.y = GetLevel()->GetCameraPos().y - (GetLevel()->GetCameraPos().y );
		GetLevel()->SetCameraPos(CurCameraPos);
	}
	//PlayerCollision->DebugRender();
	//
	//if (true == PlayerCollision->CollisionCheck("Door", CollisionType::Rect, CollisionType::Rect))
	//{
	//	int a = 0;
	//}

}

// �������� �� ���ư��� ������
void Player::Render()
{
	//float MapSizeX = 14602;
	//float MapSizeY = 1038;
	//float CameraRectX = 1280;
	//float CameraRectY = 1200;

	//GetLevel()->SetCameraPos(GetPosition() - GameEngineWindow::GetInst().GetScale().Half());
	//if (0 > GetLevel()->GetCameraPos().x)
	//{
	//	float4 CurCameraPos = GetLevel()->GetCameraPos();
	//	CurCameraPos.x = 0;
	//	GetLevel()->SetCameraPos(CurCameraPos);
	//}
	//if (0 > GetLevel()->GetCameraPos().y)
	//{
	//	float4 CurCameraPos = GetLevel()->GetCameraPos();
	//	CurCameraPos.y = 0;
	//	GetLevel()->SetCameraPos(CurCameraPos);
	//}
	//if (MapSizeX <= GetLevel()->GetCameraPos().x)
	//{
	//	float4 CurCameraPos = GetLevel()->GetCameraPos();
	//	CurCameraPos.x = GetLevel()->GetCameraPos().x - (GetLevel()->GetCameraPos().x + CameraRectX - MapSizeX);
	//	GetLevel()->SetCameraPos(CurCameraPos);
	//}
	//if (MapSizeY <= (GetLevel()->GetCameraPos().y + 640))
	//{
	//	float4 CurCameraPos = GetLevel()->GetCameraPos();
	//	CurCameraPos.y = GetLevel()->GetCameraPos().y - (GetLevel()->GetCameraPos().y);
	//	GetLevel()->SetCameraPos(CurCameraPos);
	//}
}
