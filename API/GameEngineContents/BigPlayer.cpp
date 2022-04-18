#include "BigPlayer.h"
#include "Pause.h"
#include <GameEngineBase/GameEngineSound.h>
#include "LevelIntro.h"
#include "Point100.h"




#include <GameEngine/GameEngineLevel.h> // ������ ���ؼ�
// #include "�̰� " ���鶧 
BigPlayer::BigPlayer()
	: Speed_(100.0f)
	, Gravity_(150.0f)
	, AccSpeed_(15.0f)
	, MoveDir(float4::ZERO)
	, AccGravity_(0)
{
}

BigPlayer::~BigPlayer()
{
}



void BigPlayer::Start()
{
	BigPlayerCollision = CreateCollision("BigPlayerHitBox", { 80, 10 }, { 0, -40 });
	BigPlayerCollision = CreateCollision("PlayerBot", { 80, 10 }, { 0, 40 });
	BigPlayerRight_ = CreateCollision("PlayerItem", { 2,80 }, { 40, 0 });
	BigPlayerLeft_ = CreateCollision("PlayerItem", { 2, 80 }, { -40, 0 });
	Right = 0;
	Left = 0;

	RenderRun = CreateRenderer("Mario.bmp");
	RenderRun->SetIndex(0);
	RenderRun->CreateAnimation("Mario.bmp", "MarioRight", 0, 0, 0.1f, false);
	RenderRun->CreateAnimation("Mario.bmp", "MarioLeft", 1, 1, 0.1f, false);
	RenderRun->CreateAnimation("Mario.bmp", "RunRight", 2, 4, 0.07f, true);
	RenderRun->CreateAnimation("Mario.bmp", "RunLeft", 5, 7, 0.07f, true);
	RenderRun->CreateAnimation("Mario.bmp", "TurnRight", 8, 8, 100.0f, false);
	RenderRun->CreateAnimation("Mario.bmp", "TurnLeft", 9, 9, 10.0f, false);
	RenderRun->CreateAnimation("Mario.bmp", "JumpRight", 10, 10, 0.1f, false);
	RenderRun->CreateAnimation("Mario.bmp", "JumpLeft", 11, 11, 0.1f, false);
	RenderRun->CreateAnimation("Mario.bmp", "Death", 15, 15, 0.1f, false);
	RenderRun->CreateAnimation("Mario.bmp", "Flag", 16, 17, 0.15f, true);
	RenderRun->CreateAnimation("Mario.bmp", "End", 18, 18, 0.15f, false);
	RenderRun->CreateAnimation("Blank.bmp", "Blank", 0, 0, 0.15f, false);
	RenderRun->ChangeAnimation("MarioRight");



	{
		GameEngineInput::GetInst()->CreateKey("MoveLeft", 'A');
		GameEngineInput::GetInst()->CreateKey("MoveRight", 'D');
		GameEngineInput::GetInst()->CreateKey("Jump", VK_LSHIFT);
		GameEngineInput::GetInst()->CreateKey("Down", 'S');
		// VK_LBUTTON; ���콺
	}
}

void BigPlayer::Update()
{

	WhiteMap_ = GameEngineImageManager::GetInst()->Find("11mapWhite.bmp");
	if (nullptr == WhiteMap_)
	{
		MsgBoxAssert("�� �浹�� �̹����� ã�� ���߽��ϴ�.")
	}
	if (Pause::end)
	{
		if (FirstEnd_)
		{
			RenderRun->ChangeAnimation("Flag");
			FirstEnd_ = false;
		}
		Time_ = Time_ + GameEngineTime::GetDeltaTime();
		MoveDir = float4::DOWN;
		float4 NextPos = GetPosition() + (MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		int Down = WhiteMap_->GetImagePixel(NextPos + float4(19.0f, 19.0f));
		int Right = WhiteMap_->GetImagePixel(NextPos + float4(20.0f, 0.0f));
		if ((RGB(0, 0, 0) != (Down)))
		{
			SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		}
		if (1.2f  <= Time_
			&& 1.3f > Time_)
		{
			SetPosition(float4{7955, 480});
			RenderRun->ChangeAnimation("End");
			return;
		}
		if (1.3f <= Time_)
		{
			RenderRun->ChangeAnimation("RunRight");
			if ((RGB(0, 0, 0) != (Down)))
			{
				MoveDir += float4::DOWN * GameEngineTime::GetDeltaTime() * 50;
			}
			else
			{
				MoveDir = float4::ZERO;
			}
			if ((RGB(255, 0, 0) == (Right)))
			{
				blank = true;
			}
			if (blank)
			{
				RenderRun->ChangeAnimation("Blank");
			}
			  MoveDir += float4::RIGHT * GameEngineTime::GetDeltaTime() * 300;
			SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		}
		return;
	}
	if (Pause::death)
	{
		Time_ = Time_ + GameEngineTime::GetDeltaTime();
		if (3.0f <= Time_)
		{
			Time_ = 0;
			GameEngine::GetInst().ChangeLevel("StageIntro");
			float4 CurCameraPos = GetLevel()->GetCameraPos();
			CurCameraPos.x = 0;
			GetLevel()->SetCameraPos(CurCameraPos);
			RenderRun->ChangeAnimation("MarioRight");
		}
		if (0.8f >= Time_)
		{
			SetMove(float4::UP );
			return;
		}
		if (1.2f >= Time_)
		{
			SetMove(float4::DOWN );
			return;
		}
		return;
	}
	//bool Down_; // ���� Ű�� ��������
	//bool Press_; // �� ���ķ� ���������� ������ ������.
	//bool Up_; // �����ٰ� ������ 
	//bool Free_; // �ȴ����� ������.
	//RenderRun->ChangeAnimation("MarioRight");
	float4 CheckPos;

	float MapSizeX = 8441;
	float MapSizeY = 550;
	float CameraRectX = 620;
	float CameraRectY = 550;
	float Camera = GetLevel()->GetCameraPos().x;
	GetLevel()->SetCameraPos(GetPosition() - GameEngineWindow::GetInst().GetScale().Half());

	if ((GetPosition().x  - 50)> GetLevel()->GetCameraPos().x)
	{
		float4 CurCameraPos = GetLevel()->GetCameraPos();
		CurCameraPos.x = (GetPosition().x - 50);
		GetLevel()->SetCameraPos(CurCameraPos);
	}
	if (Camera > (GetPosition().x -50))
	{
		float4 CurCameraPos = GetLevel()->GetCameraPos();
		CurCameraPos.x = Camera;
		GetLevel()->SetCameraPos(CurCameraPos);
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
		CurCameraPos.y = GetLevel()->GetCameraPos().y - (GetLevel()->GetCameraPos().y);
		GetLevel()->SetCameraPos(CurCameraPos);
	}
	if (MapSizeX <= GetLevel()->GetCameraPos().x +625)
	{
		float4 CurCameraPos = GetLevel()->GetCameraPos();
		CurCameraPos.x  = GetLevel()->GetCameraPos().x - (GetLevel()->GetCameraPos().x + CameraRectX - MapSizeX   );
		GetLevel()->SetCameraPos(CurCameraPos);
	}
	if (MapSizeY <= (GetLevel()->GetCameraPos().y + CameraRectY))
	{
		float4 CurCameraPos = GetLevel()->GetCameraPos();
		CurCameraPos.y = GetLevel()->GetCameraPos().y - (GetLevel()->GetCameraPos().y);
		GetLevel()->SetCameraPos(CurCameraPos);
	}

	//�ƹ��͵� �� ������
	MoveDir += float4::DOWN * GameEngineTime::GetDeltaTime() * 100;
	if (true == GameEngineInput::GetInst()->IsDown("Jump"))
	{
		MoveDir += float4::UP *10;
		GameEngineSound::SoundPlayOneShot("jumpsmall.wav", 0);
	}
	if (true == GameEngineInput::GetInst()->IsPress("Jump"))
	{
		if (RenderRun->IsAnimationName("RunRight") || RenderRun->IsAnimationName("MarioRight"))
		{
			RenderRun->ChangeAnimation("JumpRight");
		}
		else if (RenderRun->IsAnimationName("RunLeft") || RenderRun->IsAnimationName("MarioLeft"))
		{
			RenderRun->ChangeAnimation("JumpLeft");
		}
		MoveDir = MoveDir + float4::UP * GameEngineTime::GetDeltaTime() * 80;

	}

	if (true == GameEngineInput::GetInst()->IsPress("MoveLeft"))
	{

		RenderRun->ChangeAnimation("RunLeft");

		MoveDir += float4::LEFT * GameEngineTime::GetDeltaTime() * 10;

	}

	if (true == GameEngineInput::GetInst()->IsPress("Down"))
	{
		MoveDir += float4::DOWN;
	}
	if (true == GameEngineInput::GetInst()->IsFree("Jump"))
	{
		/*MoveDir += float4::DOWN * GameEngineTime::GetDeltaTime() * AccSpeed_;*/
	}

	if (true == GameEngineInput::GetInst()->IsPress("MoveRight"))
	{
		RenderRun->ChangeAnimation("RunRight");


		MoveDir += float4::RIGHT * GameEngineTime::GetDeltaTime() * 10;

	}


	//{
	//	float y = MoveDir.y;
	//	if (0.0f <= MoveDir.y
	//		&& -0.2f >= MoveDir.y)
	//	{
	//		MoveDir.y = -0.5f;
	//	}
	//}
	//{
	//	if (-3.0f >= MoveDir.y)
	//	{
	//		MoveDir.y = -3.0f;
	//	}
		if (-2.0f >= MoveDir.x)
		{
			MoveDir.x = -2.0f;
		}
		if (2.0f <= MoveDir.x)
		{
			MoveDir.x = 2.0f;
		}
	//}
	{
	/*	if (8.0f <= MoveDir.Len2D())
		{
			MoveDir.Range2D(8.0f);
		}*/
	}

	if (true == BigPlayerCollision->CollisionCheck("Goomba", CollisionType::Rect, CollisionType::Rect))
	{
		MoveDir = float4::UP *10;
		AccGravity_ = 0;
		SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_ );
	}
	float4 NextPos = GetPosition() +float4 {0, 20};
	if (true == BigPlayerLeft_->CollisionCheck("MonsterRight", CollisionType::Rect, CollisionType::Rect)
		|| true == BigPlayerRight_->CollisionCheck("MonsterLeft", CollisionType::Rect, CollisionType::Rect)
		|| (RGB(0, 0, 255)== WhiteMap_->GetImagePixel(NextPos)))
	{
		//Point100* Ptr = GetLevel()->CreateActor<Point100>(2);
		//Ptr->SetPosition(GetPosition());
		//Death();
		Pause::death = true;
		RenderRun->ChangeAnimation("Death");
		SetMove(float4::UP);
		GameEngineSound::SoundPlayOneShot("Death.wav", 0);
		LevelIntro::DeathCount = LevelIntro::DeathCount - 1;

		return;
	}


	{
		float y = MoveDir.y;
		if (0.0f <= MoveDir.y
			&& -0.2f >= MoveDir.y)
		{
			MoveDir.y = -0.5f;
		}
	}
	if (0 < MoveDir.x)
	{
		if (true == GameEngineInput::GetInst()->IsPress("MoveLeft"))
		{
			RenderRun->ChangeAnimation("TurnLeft");
		}
	}
	if (0 > MoveDir.x)
	{
		if (true == GameEngineInput::GetInst()->IsPress("MoveRight"))
		{
			RenderRun->ChangeAnimation("TurnRight");
		}
	}

	if (false == GameEngineInput::GetInst()->IsPress("MoveLeft") &&
		false == GameEngineInput::GetInst()->IsPress("MoveRight") &&
		false == GameEngineInput::GetInst()->IsPress("Down")
		)
	{
		MoveDir += -MoveDir * GameEngineTime::GetDeltaTime() * 4;

		if (0.05f >= MoveDir.Len2D())
		{
			MoveDir = float4::ZERO;
			return;
		}


		if (RenderRun->IsAnimationName("RunRight"))
		{
			RenderRun->ChangeAnimation("MarioRight");
		}
		if (RenderRun->IsAnimationName("RunLeft"))
		{
			RenderRun->ChangeAnimation("MarioLeft");
		}



	}

	{
		float4 NextPos = GetPosition() + (MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		float4 CheckPos = NextPos;
		float4 BigPlayerLeft = float4{ -20, 0 };
		float4 BigPlayerRight = float4{ 20, 0 };
		float4 BigPlayerDown = float4{ 0, 20 };

		int Color = WhiteMap_->GetImagePixel(NextPos + float4(0.0f, 19.0f));
		int Down1 = WhiteMap_->GetImagePixel(GetPosition() + float4(10.0f, 19.0f));
		int Down2 = WhiteMap_->GetImagePixel(GetPosition() + float4(-10.0f, 19.0f));
		int ColorUp = WhiteMap_->GetImagePixel(GetPosition() + float4(0.0f, -19.0f));


		if ((RGB(255, 255, 255) != Color)
			&& GameEngineInput::GetInst()->IsFree("Jump")
			)

		{
			if (RenderRun->IsAnimationName("JumpLeft"))
			{
				RenderRun->ChangeAnimation("MarioLeft");
			}
			else
				if (RenderRun->IsAnimationName("JumpRight"))
				{
					RenderRun->ChangeAnimation("MarioRight");
				}
			MoveDir.y =0;
			AccGravity_ = 0;
		}
		float4 LeftRight = { 0, 0 };
		float4 UpUp = { 0, 0 };
		float4 DownDown = { 0, 0 };
		int Left = WhiteMap_->GetImagePixel(NextPos + float4(-19.0f, 0.0f));
		int Right = WhiteMap_->GetImagePixel(NextPos + float4(19.0f, 0.0f));
		int Down = WhiteMap_->GetImagePixel(NextPos + float4(0.0f, 19.0f));
		int Up = WhiteMap_->GetImagePixel(NextPos + float4(0.0f, -19.0f));

		LeftRight.x = MoveDir.x;
		UpUp.y = MoveDir.y;
		DownDown.y = MoveDir.y;
		bool DownCheck = false;
		bool UpCheck = false;
		bool RightCheck = false;
		bool LeftCheck = false;

		if ((GetPosition().x - 17 < GetLevel()->GetCameraPos().x))
		{
			SetMove(float4::RIGHT * 0.1f);
			return;
		}

		if (0 <= MoveDir.y)
		{
			AccGravity_ += GameEngineTime::GetDeltaTime() * Gravity_;
			DownCheck = true;
		}
		if (0 > MoveDir.y)
		{
			AccGravity_ += GameEngineTime::GetDeltaTime() * Gravity_;
			UpCheck = true;
		}
		//if (0 == (int)MoveDir.y)
		//{
		//	AccGravity_ = 0;
		//}
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
			SetMove(LeftRight * GameEngineTime::GetDeltaTime() * Speed_);
		}
		if ((RGB(0, 0, 0) != (Right))
			&& RightCheck
			)

		{
			SetMove(LeftRight * GameEngineTime::GetDeltaTime() * Speed_);
		}
		if ((RGB(0, 0, 0) != (Up)))
		{

		}
		if ((RGB(0, 0, 0) != (Up))
			&& UpCheck
			)

		{
			SetMove(UpUp * GameEngineTime::GetDeltaTime() * Speed_);
		}

		//BigPlayerCollision = CreateCollision("BigPlayerHitBox", { 40,40 }, CheckPos + float4(-160.0f, -1000.0f));
		//if ((RGB(0, 0, 0) == (Down)))
		//{
		//	AccGravity_ = 0;
		//}
		if ((RGB(0, 0, 0) != (Down1)))
		{
			int a = 0;
		}
		if ((RGB(0, 0, 0) != (Down2)))
		{
			int a = 0;
		}
		if ((RGB(0, 0, 0) != (Down)
			&& (RGB(0, 0, 0) != (Down1))
			&&	(RGB(0, 0, 0) != (Down2))
			&& DownCheck)
			)

		{
			SetMove(DownDown * GameEngineTime::GetDeltaTime() * Speed_);
		}


	}
}

float BigPlayer::GetCurrentPosition()
{
	float x = GetPosition().x;
	return  x;
}

void BigPlayer::HitBlock()
{


}
// �������� �� ���ư��� ������
void BigPlayer::Render()
{

}