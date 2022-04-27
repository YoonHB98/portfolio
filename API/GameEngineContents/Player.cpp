#include "Player.h"
#include "Pause.h"
#include <GameEngineBase/GameEngineSound.h>
#include "LevelIntro.h"
#include "Point100.h"
#include "BlockBreak.h"
#include "WorldCount.h"




#include <GameEngine/GameEngineLevel.h> // 레벨을 통해서
// #include "이걸 " 만들때 
Player::Player()
	: Speed_(100.0f)
	, Gravity_(150.0f)
	, AccSpeed_(15.0f)
	, MoveDir(float4::ZERO)
	, AccGravity_(0)
{
}

Player::~Player()
{
}



void Player::Start()
{
	PlayerCollision = CreateCollision("PlayerHitBox", { 10, 10 }, { 0, -20 });
	PlayerCollision = CreateCollision("PlayerBot", { 40, 10 }, { 0, 20 });
	PlayerRight_ = CreateCollision("PlayerItem", { 2,40 }, { 20, 0 });
	PlayerLeft_ = CreateCollision("PlayerItem", { 2, 40 }, { -20, 0 });

	Move_ = CreateCollision("NNN", { 2, 2 }, { 0, 0 });
	Up_ = CreateCollision("NNN", { 30, 5 }, { 0, -19 });
	Down_ = CreateCollision("NNN", { 2, 2 }, { 0, 19 });

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


	if (Pause::CreateKeyFirst)
	{
		GameEngineInput::GetInst()->CreateKey("MoveLeft", 'A');
		GameEngineInput::GetInst()->CreateKey("MoveRight", 'D');
		GameEngineInput::GetInst()->CreateKey("Jump", VK_LSHIFT);
		GameEngineInput::GetInst()->CreateKey("Down", 'S');
		GameEngineInput::GetInst()->CreateKey("in", 'E');
	}
}

void Player::Update()
{
	if (Pause::PlayerStatus != "small")
	{
		return;
	}
	RenderRun->SetAlpha(255);

	if (true == GameEngineInput::GetInst()->IsDown("in"))
	{
		if (true == Pause::smallfirst)
		{
			Pause::smallfirst = !Pause::smallfirst;
			nodiecount = 0;
			return;
		}
		if (false == Pause::smallfirst)
		{
			Pause::smallfirst = !Pause::smallfirst;
			nodiecount = 20;
			return;
		}


	}


	if (true == GameEngineInput::GetInst()->IsDown("Down"))
	{
		GameEngineLevel* A = 0;
		A->IsDebugModeSwitch();

	}
	if (Pause::pipedown )
	{
		if (PipeDownFirst == true)
		{
			GameEngineSound::SoundPlayOneShot("shrink.wav");
			PipeDownFirst = false;
		}
		Time_ = Time_ + GameEngineTime::GetDeltaTime();
	   SetMove(float4::DOWN * GameEngineTime::GetDeltaTime() * 70.0f);
	   Pause::PlayerPosition = GetPosition();
	   if (Time_ > 0.5f)
	   {
		   WorldCount::Under = true;
		   PipeDownFirst = true;
		   Pause::pipedown = false;
	   }
	   return;
	}
	if (Pause::smallfirst)
	{
		nodie = nodie + GameEngineTime::GetDeltaTime();
		if (nodie < 0.1f)
		{
			RenderRun->SetAlpha(150);
		}
		if (nodie > 0.1f)
		{
			RenderRun->SetAlpha(255);
			if (nodie > 0.2f)
			{
				nodie = 0.0f;
				nodiecount += 1;
			}
		}
		if (nodiecount == 10)
		{
			Pause::smallfirst = false;
			nodiecount = 0;
		}
	}
	ColMap();
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
		int Down = ColMap_->GetImagePixel(NextPos + float4(19.0f, 19.0f));
		int Right = ColMap_->GetImagePixel(NextPos + float4(20.0f, 0.0f));
		if ((RGB(0, 0, 0) != (Down)))
		{
			SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
			Pause::PlayerPosition = GetPosition();
		}
		if (1.2f <= Time_
			&& 1.3f > Time_)
		{
			SetPosition(float4{ 7955, 480 });
			RenderRun->ChangeAnimation("End");
			Pause::PlayerPosition = GetPosition();
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
				Pause::endtime = true;
			}
			MoveDir += float4::RIGHT * GameEngineTime::GetDeltaTime() * 300;
			SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
			Pause::PlayerPosition = GetPosition();
		}
		return;
	}
	if (Pause::death)
	{
		float4 MoveDir2;
		MoveDir2 += float4::DOWN * GameEngineTime::GetDeltaTime() * 3600;

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
		if (0.4f >= Time_)
		{
			MoveDir2 += float4::UP * 7000 * GameEngineTime::GetDeltaTime();
			SetMove(MoveDir2 * GameEngineTime::GetDeltaTime() * Speed_);
			Pause::PlayerPosition = GetPosition();
			return;
		}
		if (0.5f > Time_)
		{
			MoveDir2 = float4::ZERO;
			return;
		}
		if (1.2f >= Time_)
		{
			SetMove(MoveDir2 * GameEngineTime::GetDeltaTime() * Speed_);
			Pause::PlayerPosition = GetPosition();
			return;
		}
		return;
	}
	//bool Down_; // 최초 키를 눌렀을때
	//bool Press_; // 그 이후로 지속적으로 누르고 있을때.
	//bool Up_; // 누르다가 땠을때 
	//bool Free_; // 안누르고 있을때.
	//RenderRun->ChangeAnimation("MarioRight");
	float4 CheckPos;


	
	MapSize();
	CameraPos();
	

	//아무것도 안 누를때
	MoveDir += float4::DOWN * GameEngineTime::GetDeltaTime() * 100;
	if (true == GameEngineInput::GetInst()->IsDown("Jump"))
	{
		MoveDir += float4::UP * 12;
		GameEngineSound::SoundPlayOneShot("jumpsmall.wav", 0);
	}
	if (true == GameEngineInput::GetInst()->IsPress("Jump"))
	{

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

	if (-30.0f >= MoveDir.y)
	{
		MoveDir.y = -30.0f;
	}
	if (30.0f <= MoveDir.y)
	{
		MoveDir.y = 30.0f;
	}
	if (-2.0f >= MoveDir.x)
	{
		MoveDir.x = -2.0f;
	}
	if (2.0f <= MoveDir.x)
	{
		MoveDir.x = 2.0f;
	}
	{
		if (8.0f <= MoveDir.Len2D())
		{
			MoveDir.Range2D(8.0f);
		}
		if (-8.0f >= MoveDir.Len2D())
		{
			MoveDir.Range2D(-8.0f);
		}
	}

	if (true == PlayerCollision->CollisionCheck("MonsterTop", CollisionType::Rect, CollisionType::Rect))
	{
		MoveDir = float4::UP * 10;
		AccGravity_ = 0;
		SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
	}
	float4 NextPos = GetPosition() + float4{ 0, 20 };
	if (Pause::smallfirst == false)
	{
		if (true == PlayerLeft_->CollisionCheck("MonsterRight", CollisionType::Rect, CollisionType::Rect)
			|| true == PlayerRight_->CollisionCheck("MonsterLeft", CollisionType::Rect, CollisionType::Rect)
			|| (RGB(0, 0, 255) == ColMap_->GetImagePixel(NextPos))
			)
		{
			Pause::death = true;
			RenderRun->ChangeAnimation("Death");
			SetMove(float4::UP);
			GameEngineSound::SoundPlayOneShot("Death.wav", 0);
			LevelIntro::DeathCount = LevelIntro::DeathCount - 1;

			return;
		}
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
	float x = MoveDir.x;
	if (false == GameEngineInput::GetInst()->IsPress("MoveLeft") &&
		false == GameEngineInput::GetInst()->IsPress("MoveRight") &&
		false == GameEngineInput::GetInst()->IsPress("Down")
		)
	{
		MoveDir += -float4{ x, 0 }*GameEngineTime::GetDeltaTime() * 4;

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
		float4 PlayerLeft = float4{ -20, 0 };
		float4 PlayerRight = float4{ 20, 0 };
		float4 PlayerDown = float4{ 0, 20 };

		int Color = ColMap_->GetImagePixel(NextPos + float4(0.0f, 19.0f));
		int Down1 = ColMap_->GetImagePixel(GetPosition() + float4(8.0f, 19.0f));
		int Down2 = ColMap_->GetImagePixel(GetPosition() + float4(-8.0f, 19.0f));
		int ColorUp = ColMap_->GetImagePixel(GetPosition() + float4(0.0f, -19.0f));


		if (((RGB(255, 255, 255) != Color) || true == Down_->NextPosCollisionCheck("Move", NextPos + float4(0.0f, 19.0f), CollisionType::Rect, CollisionType::Rect))
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
			MoveDir.y = 0;
			AccGravity_ = 0;
		}
		float4 LeftRight = { 0, 0 };
		float4 UpUp = { 0, 0 };
		float4 DownDown = { 0, 0 };
		int Left = ColMap_->GetImagePixel(NextPos + float4(-19.0f, 0.0f));
		int Right = ColMap_->GetImagePixel(NextPos + float4(19.0f, 0.0f));
		int Down = ColMap_->GetImagePixel(NextPos + float4(0.0f, 19.0f));
		int Up = ColMap_->GetImagePixel(NextPos + float4(0.0f, -19.0f));

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
			Pause::PlayerPosition = GetPosition();
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
		if (true != Move_->NextPosCollisionCheck("Move", NextPos, CollisionType::Rect, CollisionType::Rect))
		{
			if ((RGB(0, 0, 0) != (Left)
				&& LeftCheck))
			{
				SetMove(LeftRight * GameEngineTime::GetDeltaTime() * Speed_);
				Pause::PlayerPosition = GetPosition();
			}
		}
		if (true != Move_->NextPosCollisionCheck("Move", NextPos, CollisionType::Rect, CollisionType::Rect))
		{
			if ((RGB(0, 0, 0) != (Right)
				&& RightCheck))
			{
				SetMove(LeftRight * GameEngineTime::GetDeltaTime() * Speed_);
				Pause::PlayerPosition = GetPosition();
			}
		}
		if (true != Up_->NextPosCollisionCheck("Move", NextPos, CollisionType::Rect, CollisionType::Rect))
		{
			if ((RGB(0, 0, 0) != (Up))
				&& UpCheck)
			{
				SetMove(UpUp * GameEngineTime::GetDeltaTime() * Speed_);
				Pause::PlayerPosition = GetPosition();
				if (RenderRun->IsAnimationName("RunRight") || RenderRun->IsAnimationName("MarioRight") || RenderRun->IsAnimationName("JumpRight"))
				{
					RenderRun->ChangeAnimation("JumpRight");
				}
				else if (RenderRun->IsAnimationName("RunLeft") || RenderRun->IsAnimationName("MarioLeft") || RenderRun->IsAnimationName("JumpLeft"))
				{
					RenderRun->ChangeAnimation("JumpLeft");
				}
			}
		}
		if (true != Down_->NextPosCollisionCheck("Move", NextPos + float4(0.0f, 19.0f), CollisionType::Rect, CollisionType::Rect)
			&& true != Down_->NextPosCollisionCheck("Move", GetPosition() + float4(8.0f, 19.0f), CollisionType::Rect, CollisionType::Rect)
			&& true != Down_->NextPosCollisionCheck("Move", GetPosition() + float4(-8.0f, 19.0f), CollisionType::Rect, CollisionType::Rect))
		{
			if ((RGB(0, 0, 0) != (Down)
				&& (RGB(0, 0, 0) != (Down1))
				&& (RGB(0, 0, 0) != (Down2))
				&& DownCheck))
			{
				SetMove(DownDown * GameEngineTime::GetDeltaTime() * Speed_);
				Pause::PlayerPosition = GetPosition();
				if (RenderRun->IsAnimationName("RunRight") || RenderRun->IsAnimationName("MarioRight") || RenderRun->IsAnimationName("JumpRight"))
				{
					RenderRun->ChangeAnimation("JumpRight");
				}
				else if (RenderRun->IsAnimationName("RunLeft") || RenderRun->IsAnimationName("MarioLeft") || RenderRun->IsAnimationName("JumpLeft"))
				{
					RenderRun->ChangeAnimation("JumpLeft");
				}

			}
		}

	}
}

float Player::GetCurrentPosition()
{
	float x = GetPosition().x;
	return  x;
}
void Player::MapSize()
{
	std::string MapName = GameEngine::CurrentLevel_->GetNameConstRef();
	if (WorldCount::WorldCountUI == 1
		&&WorldCount::Under)
	{
		MapSizeX = 640;
		MapSizeY = 550;
		return;
	}else
	if (WorldCount::WorldCountUI == 1)
	{
		MapSizeX = 8441;
		MapSizeY = 550;
		return;
	}

}
void Player::HitBlock()
{


}
void Player::ColMap()
{
	if (WorldCount::WorldCountUI == 1)
	{
		ColMap_ = GameEngineImageManager::GetInst()->Find("11mapWhite.bmp");
	}
	if (WorldCount::WorldCountUI == 2)
	{
		ColMap_ = GameEngineImageManager::GetInst()->Find("11mapWhite.bmp");
	}
	if (WorldCount::WorldCountUI == 3)
	{
		ColMap_ = GameEngineImageManager::GetInst()->Find("11mapWhite.bmp");
	}
	if (WorldCount::WorldCountUI == 4)
	{
		ColMap_ = GameEngineImageManager::GetInst()->Find("11mapWhite.bmp");
	}


}
void Player::CameraPos()
{
	float CameraRectX = 620;
	float CameraRectY = 550;
	float Camera = GetLevel()->GetCameraPos().x;
	GetLevel()->SetCameraPos(GetPosition() - GameEngineWindow::GetInst().GetScale().Half());
	if (WorldCount::Under)
	{
		float4 CurCameraPos = GetLevel()->GetCameraPos();
		CurCameraPos.x = Camera;
			GetLevel()->SetCameraPos(float4{639,600});
			return;
	}

	if ((GetPosition().x - 300) > GetLevel()->GetCameraPos().x)
	{
		float4 CurCameraPos = GetLevel()->GetCameraPos();
		CurCameraPos.x = (GetPosition().x - 300);
		GetLevel()->SetCameraPos(CurCameraPos);
	}
	if (Camera > (GetPosition().x - 300))
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
	if (MapSizeY <= (GetLevel()->GetCameraPos().y + CameraRectY))
	{
		float4 CurCameraPos = GetLevel()->GetCameraPos();
		CurCameraPos.y = GetLevel()->GetCameraPos().y - (GetLevel()->GetCameraPos().y);
		GetLevel()->SetCameraPos(CurCameraPos);
	}
	if (MapSizeX <= GetLevel()->GetCameraPos().x + 625)
	{
		float4 CurCameraPos = GetLevel()->GetCameraPos();
		CurCameraPos.x = GetLevel()->GetCameraPos().x - (GetLevel()->GetCameraPos().x + CameraRectX - MapSizeX);
		GetLevel()->SetCameraPos(CurCameraPos);
	}



}
// 랜더러가 다 돌아가고 랜더링
void Player::Render()
{

}

float Player::Time_ = 0;