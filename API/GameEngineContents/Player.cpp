#include "Player.h"
#include "Pause.h"
#include <GameEngineBase/GameEngineSound.h>
#include "LevelIntro.h"




#include <GameEngine/GameEngineLevel.h> // 레벨을 통해서
// #include "이걸 " 만들때 
Player::Player()
	: Speed_(100.0f)
	, Gravity_(300.0f)
	, AccSpeed_(30.0f)
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
	PlayerRight_ = CreateCollision("PlayerItem", { 5,80 }, { 40, 0 });
	PlayerLeft_ = CreateCollision("PlayerItem", { 5, 80 }, { -40, 0 });
	Right = 0;
	Left = 0;

	RenderRun = CreateRenderer("Mario.bmp");
	RenderRun->SetTransColor(RGB(146, 144, 255));
	RenderRun->SetIndex(0);
	RenderRun->CreateAnimation("Mario.bmp", "MarioRight", 0, 0, 0.1f, false);
	RenderRun->CreateAnimation("Mario.bmp", "MarioLeft", 1, 1, 0.1f, false);
	RenderRun->CreateAnimation("Mario.bmp", "RunRight", 2, 4, 0.07f, true);
	RenderRun->CreateAnimation("Mario.bmp", "RunLeft", 5, 7, 0.07f, true);
	RenderRun->CreateAnimation("Mario.bmp", "TurnRight", 8, 8, 100.0f, false);
	RenderRun->CreateAnimation("Mario.bmp", "TurnLeft", 9, 9, 20.0f, false);
	RenderRun->CreateAnimation("Mario.bmp", "JumpRight", 10, 10, 0.1f, false);
	RenderRun->CreateAnimation("Mario.bmp", "JumpLeft", 11, 11, 0.1f, false);
	RenderRun->CreateAnimation("Mario.bmp", "Death", 15, 15, 0.1f, false);
	RenderRun->CreateAnimation("Mario.bmp", "Flag", 16, 17, 0.07f, true);
	RenderRun->ChangeAnimation("MarioRight");



	{
		GameEngineInput::GetInst()->CreateKey("MoveLeft", 'A');
		GameEngineInput::GetInst()->CreateKey("MoveRight", 'D');
		GameEngineInput::GetInst()->CreateKey("Jump", VK_LSHIFT);
		GameEngineInput::GetInst()->CreateKey("Down", 'S');
		// VK_LBUTTON; 마우스
	}
}

void Player::Update()
{
	if (Pause::pause)
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
			SetMove(float4::UP * 2);
			return;
		}
		if (1.2f >= Time_)
		{
			SetMove(float4::DOWN * 2);
			return;
		}
	return;
	}
	WhiteMap_ = GameEngineImageManager::GetInst()->Find("11mapWhite.bmp");
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

	float MapSizeX = 16881;
	float MapSizeY = 1200;
	float CameraRectX = 1280;
	float CameraRectY = 1200;
	float Camera = GetLevel()->GetCameraPos().x;
	GetLevel()->SetCameraPos(GetPosition() - GameEngineWindow::GetInst().GetScale().Half());

	if ((GetPosition().x  - 200)> GetLevel()->GetCameraPos().x)
	{
		float4 CurCameraPos = GetLevel()->GetCameraPos();
		CurCameraPos.x = (GetPosition().x - 200);
		GetLevel()->SetCameraPos(CurCameraPos);
	}
	if (Camera > (GetPosition().x -200))
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
	//아무것도 안 누를때
	if (true == GameEngineInput::GetInst()->IsDown("Jump"))
	{
		MoveDir = float4::UP;
		GameEngineSound::SoundPlayOneShot("jumpsmall.wav", 0);
	}

	if (true == GameEngineInput::GetInst()->IsPress("MoveLeft"))
	{

		RenderRun->ChangeAnimation("RunLeft");

		MoveDir += float4::LEFT;

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


		MoveDir += float4::RIGHT;

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
		MoveDir = MoveDir + float4::UP;

	}




	// 내가 키를 눌렀다면 움직여라.
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
	MoveDir += float4::DOWN * GameEngineTime::GetDeltaTime() * AccGravity_;
	{
		float y = MoveDir.y;
		if (0.0f <= MoveDir.y
			&& -0.2f >= MoveDir.y)
		{
			MoveDir.y = -0.5f;
		}
	}
	{
		if (-6.0f >= MoveDir.y)
		{
			MoveDir.y = -6.0f;
		}
		if (-8.0f >= MoveDir.x)
		{
			MoveDir.x = -8.0f;
		}
		if (8.0f <= MoveDir.x)
		{
			MoveDir.x = 8.0f;
		}
	}
	{
	/*	if (8.0f <= MoveDir.Len2D())
		{
			MoveDir.Range2D(8.0f);
		}*/
	}
	if (true == PlayerCollision->CollisionCheck("Goomba", CollisionType::Rect, CollisionType::Rect))
	{
		MoveDir = float4::UP *40;
		AccGravity_ = 0;
		SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_ );
	}
	if (true == PlayerLeft_->CollisionCheck("Monster", CollisionType::Rect, CollisionType::Rect)
		|| true == PlayerRight_->CollisionCheck("Monster", CollisionType::Rect, CollisionType::Rect))
	{

		Pause::pause = true;
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
		float4 NextPos = GetPosition() + (MoveDir * GameEngineTime::GetDeltaTime());
		float4 CheckPos = NextPos;
		float4 PlayerLeft = float4{ -40, 0 };
		float4 PlayerRight = float4{ 40, 0 };
		float4 PlayerDown = float4{ 0, 40 };

		int Color = WhiteMap_->GetImagePixel(NextPos + float4(0.0f, 38.0f));
		int Down1 = WhiteMap_->GetImagePixel(GetPosition() + float4(38.0f, 38.0f));
		int Down2 = WhiteMap_->GetImagePixel(GetPosition() + float4(-38.0f, 38.0f));
		int ColorUp = WhiteMap_->GetImagePixel(GetPosition() + float4(0.0f, -38.0f));


		if ((RGB(255, 255, 255) != Color)
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
			/*MoveDir.y =0;*/
			AccGravity_ = 0;
		}
		float4 LeftRight = { 0, 0 };
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

		if ((GetPosition().x - 35 < GetLevel()->GetCameraPos().x))
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
		MoveDir += float4::DOWN * GameEngineTime::GetDeltaTime() * AccGravity_;
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

		//PlayerCollision = CreateCollision("PlayerHitBox", { 80,80 }, CheckPos + float4(-160.0f, -1000.0f));
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
		if ((RGB(0, 0, 0) != (Down))
			&& DownCheck
			)

		{
			SetMove(DownDown * GameEngineTime::GetDeltaTime() * Speed_);
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
// 랜더러가 다 돌아가고 랜더링
void Player::Render()
{

}
