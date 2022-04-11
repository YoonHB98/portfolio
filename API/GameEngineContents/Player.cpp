#include "Player.h"




#include <GameEngine/GameEngineLevel.h> // ������ ���ؼ�
// #include "�̰� " ���鶧 
Player::Player()
	: Speed_(50.0f)
	, Gravity_(50.0f)
	, AccSpeed_(50.0f)
	, MoveDir(float4::ZERO)
	, AccGravity_(0)
{
}

Player::~Player()
{
}



void Player::Start()
{
	PlayerCollision = CreateCollision("PlayerHitBox", { 80, 20 }, { 0, -40 });
	PlayerCollision = CreateCollision("PlayerBot", { 80, 20 }, { 0, 40 });
	PlayerCollision = CreateCollision("PlayerItem", { 5,80 }, { 40, 0 });
	PlayerCollision = CreateCollision("PlayerItem", { 5, 80 }, { -40, 0 });
	Right = 0;
	Left = 0;

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



	{
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
	//�ƹ��͵� �� ������
	if (true == GameEngineInput::GetInst()->IsPress("MoveLeft"))
	{

		RenderRun->ChangeAnimation("RunLeft");

		MoveDir += float4::LEFT * GameEngineTime::GetDeltaTime() * AccSpeed_;

	}

	if (true == GameEngineInput::GetInst()->IsPress("Down"))
	{
		MoveDir += float4::DOWN * GameEngineTime::GetDeltaTime() * AccSpeed_;
	}
	if (true == GameEngineInput::GetInst()->IsFree("Jump"))
	{
		MoveDir += float4::DOWN * GameEngineTime::GetDeltaTime() * AccSpeed_;
	}

	if (true == GameEngineInput::GetInst()->IsPress("MoveRight"))
	{
		RenderRun->ChangeAnimation("RunRight");


		MoveDir += float4::RIGHT * GameEngineTime::GetDeltaTime() * AccSpeed_;

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
		MoveDir += float4::UP * GameEngineTime::GetDeltaTime() * Speed_;

	}


	// ���� Ű�� �����ٸ� ��������.
	//if (0 != GetAsyncKeyState('A'))
	//{
	//	int a = 0;
	//}




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
	if (MapSizeY <= (GetLevel()->GetCameraPos().y + 640))
	{
		float4 CurCameraPos = GetLevel()->GetCameraPos();
		CurCameraPos.y = GetLevel()->GetCameraPos().y - (GetLevel()->GetCameraPos().y);
		GetLevel()->SetCameraPos(CurCameraPos);
	}
	{



		if (500.0f <= MoveDir.ix())
		{
			if (50 >= MoveDir.ix())
			{
				MoveDir = float4::ZERO;
			}
			else
			{
				MoveDir.x = 50.0f;
			}

		}
		if (-500.0f >= MoveDir.ix())
		{

			if (-50 <= MoveDir.ix())
			{
				MoveDir = float4::ZERO;
			}
			else
			{
				MoveDir.x = -50.0f;
			}
		}
		if (500.0f <= MoveDir.iy()
			&& 0.0f >= MoveDir.iy())
		{
			if (50 >= MoveDir.iy())
			{
				MoveDir = float4::ZERO;
			}
			else
			{
				MoveDir.y = 800.0f;
			}

		}
		if (-500.0f >= MoveDir.iy()
			&& 0.0f <= MoveDir.iy())
		{
			if (-50 <= MoveDir.iy())
			{
				MoveDir = float4::ZERO;
			}
			else
			{
				MoveDir.y = -1000.0f;
			}
			if (500.3f <= MoveDir.Len2D())
			{
				MoveDir.Range2D(500.0f);
			}
		}
		
		if (false == GameEngineInput::GetInst()->IsPress("MoveLeft") &&
			false == GameEngineInput::GetInst()->IsPress("MoveRight") &&
			false == GameEngineInput::GetInst()->IsPress("Down")
			)
		{
			MoveDir.x += -(MoveDir.x * GameEngineTime::GetDeltaTime() * 4);


			if (RenderRun->CurrentAnimation("RunRight"))
			{
				RenderRun->ChangeAnimation("MarioRight");
			}
			if (RenderRun->CurrentAnimation("RunLeft"))
			{
				RenderRun->ChangeAnimation("MarioLeft");
			}



		}
		float4 NextPos = GetPosition() + (MoveDir * GameEngineTime::GetDeltaTime());
		float4 CheckPos = NextPos;
		float4 PlayerLeft = float4{ -40, 0 };
		float4 PlayerRight = float4{ 40, 0 };
		float4 PlayerDown = float4{ 0, 40 };

			int Color = WhiteMap_->GetImagePixel(GetPosition() + float4(0.0f, 38.0f));
			int Down1 = WhiteMap_->GetImagePixel(GetPosition() + float4(38.0f, 38.0f));
			int Down2 = WhiteMap_->GetImagePixel(GetPosition() + float4(-38.0f, 38.0f));
			int ColorUp = WhiteMap_->GetImagePixel(GetPosition() + float4(0.0f, -38.0f));
			AccGravity_ += GameEngineTime::GetDeltaTime() * Gravity_;

			if ((RGB(255, 255, 255) != Color)
				)

			{
				if (RenderRun->CurrentAnimation("JumpLeft"))
				{
					RenderRun->ChangeAnimation("MarioLeft");
				}
				else
					if (RenderRun->CurrentAnimation("JumpRight"))
					{
						RenderRun->ChangeAnimation("MarioRight");
					}
				MoveDir.y =0;
				AccGravity_ = 0;
			}
			float4 LeftRight = {0, 0};
			float4 UpUp = { 0, 0 };
			float4 DownDown = { 0, 0 };
			int Left = WhiteMap_->GetImagePixel(NextPos + float4(-38.0f, 0.0f));
			int Right = WhiteMap_->GetImagePixel(NextPos + float4(38.0f, 0.0f));
			int Down = WhiteMap_->GetImagePixel(NextPos + float4(0.0f, 38.0f));
			int Up = WhiteMap_->GetImagePixel(NextPos + float4(0.0f, -38.0f));

			LeftRight.x = MoveDir.x;
			UpUp.y = MoveDir.y;
			DownDown.y = MoveDir.y;
			bool DownCheck = false;
			bool UpCheck = false;
			bool RightCheck = false;
			bool LeftCheck = false;

			MoveDir += float4::DOWN * GameEngineTime::GetDeltaTime() * AccGravity_;
			if (0 < MoveDir.y)
			{
				DownCheck = true;
			}
			if (0 > MoveDir.y)
			{
				UpCheck = true;
			}
			if (0 < MoveDir.x)
			{
				RightCheck = true;
			}
			if (0 > MoveDir.x)
			{
				LeftCheck = true;
			}
		if ((RGB(0, 0, 0) != (Left))
			&& LeftCheck
			)

		{
			SetMove(LeftRight* GameEngineTime::GetDeltaTime()* Speed_);
		}
		if ((RGB(0, 0, 0) != (Right))
			&& RightCheck
			)

		{
			SetMove(LeftRight * GameEngineTime::GetDeltaTime() * Speed_);
		}
		if ((RGB(0, 0, 0) == (Up))
			&& UpCheck
			)

		{
			SetMove(UpUp * GameEngineTime::GetDeltaTime()* Speed_);
		}

		//PlayerCollision = CreateCollision("PlayerHitBox", { 80,80 }, CheckPos + float4(-160.0f, -1000.0f));
		if ((RGB(0, 0, 0) != (Down)))
		{
			int a = 0;
		}
		if ((RGB(0, 0, 0) != (Down1)))
		{
			int a = 0;
		}
		if ((RGB(0, 0, 0) != (Down2)))
		{
			int a = 0;
		}
		if ((RGB(0, 0, 0) != (Down))
			&& DownCheck
			)

		{
			SetMove(DownDown * GameEngineTime::GetDeltaTime()* Speed_);
		}
		

	}
}

float Player::GetCurrentPosition()
{
	float x = GetPosition().x;
	return  x;
}

void Player::HitBlock()
{


}
// �������� �� ���ư��� ������
void Player::Render()
{

}
