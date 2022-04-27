#include "BigPlayer.h"
#include "Pause.h"
#include <GameEngineBase/GameEngineSound.h>
#include "LevelIntro.h"
#include "Point100.h"
#include <GameEngine/GameEngineCollision.h>
#include "WorldCount.h"
#include "Bullet.h"



#include <GameEngine/GameEngineLevel.h> // 레벨을 통해서
// #include "이걸 " 만들때 
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



void BigPlayer::AnimationChange(const std::string& Name_)
{
	std::string  Ani = Name_ + animation;
	RenderRun->ChangeAnimation(Ani);
}

void BigPlayer::Start()
{
	BigPlayerCollision = CreateCollision("PlayerHitBox", { 10, 10 }, { 0, -40 });
	BigPlayerCollision = CreateCollision("BigPlayerHitBox", { 10, 10 }, { 0, -40 });
	BigPlayerCollision = CreateCollision("PlayerBot", { 40, 10 }, { 0, 40 });
	BigPlayerRight_ = CreateCollision("PlayerItem", { 2,80 }, { 20, 0 });
	BigPlayerLeft_ = CreateCollision("PlayerItem", { 2, 80 }, { -20, 0 });
	Move_ = CreateCollision("NNN", { 2, 2 }, { 0, 0 });
	Up_ = CreateCollision("NNN", { 30, 5 }, { 0, -38 });
	Down_ = CreateCollision("NNN", { 2, 2 }, { 0, 38 });
	Right = 0;
	Left = 0;

	RenderRun = CreateRenderer("BigMario.bmp");
	RenderRun->SetIndex(0);
	RenderRun->CreateAnimation("BigMario.bmp", "BMRight", 0, 0, 0.1f, false);
	RenderRun->CreateAnimation("BigMario.bmp", "BMLeft", 1, 1, 0.1f, false);
	RenderRun->CreateAnimation("BigMario.bmp", "RunRight", 2, 4, 0.07f, true);
	RenderRun->CreateAnimation("BigMario.bmp", "RunLeft", 5, 7, 0.07f, true);
	RenderRun->CreateAnimation("BigMario.bmp", "TurnRight", 8, 8, 100.0f, false);
	RenderRun->CreateAnimation("BigMario.bmp", "TurnLeft", 9, 9, 10.0f, false);
	RenderRun->CreateAnimation("BigMario.bmp", "BMJR", 10, 10, 0.1f, false);
	RenderRun->CreateAnimation("BigMario.bmp", "BMJL", 11, 11, 0.1f, false);
	RenderRun->CreateAnimation("BigMario.bmp", "Death", 15, 15, 0.1f, false);
	RenderRun->CreateAnimation("BigMario.bmp", "Flag", 16, 17, 0.15f, true);
	RenderRun->CreateAnimation("BigMario.bmp", "End", 18, 18, 0.15f, false);
	RenderRun->CreateAnimation("Blank.bmp", "Blank", 0, 0, 0.15f, false);
	RenderRun->CreateAnimation("MarioChange.bmp", "Change", 0, 8, 0.1f, false);
	RenderRun->ChangeAnimation("BMRight");
	RenderRun->CreateAnimation("BigStarAnimation.bmp", "BMRightStar", 0, 2, 0.03f, false);
	RenderRun->CreateAnimation("BigStarAnimation.bmp", "BMLeftStar", 3, 5, 0.03f, false);
	RenderRun->CreateAnimation("BigStarAnimation.bmp", "RunRightStar", 6, 14, 0.02f, true);
	RenderRun->CreateAnimation("BigStarAnimation.bmp", "RunLeftStar", 15, 23, 0.02f, true);
	RenderRun->CreateAnimation("BigStarAnimation.bmp", "TurnRightStar", 24, 26, 0.03f, true);
	RenderRun->CreateAnimation("BigStarAnimation.bmp", "TurnLeftStar", 27, 29, 0.03f, true);
	RenderRun->CreateAnimation("BigStarAnimation.bmp", "BMJRStar", 30, 32, 0.03f, true);
	RenderRun->CreateAnimation("BigStarAnimation.bmp", "BMJLStar", 33, 35, 0.03f,true);
	RenderRun->CreateAnimation("BigMarioFlower.bmp", "BMRightFlower", 0, 0, 0.1f, false);
	RenderRun->CreateAnimation("BigMarioFlower.bmp", "BMLeftFlower", 1, 1, 0.1f, false);
	RenderRun->CreateAnimation("BigMarioFlower.bmp", "RunRightFlower", 2, 4, 0.07f, true);
	RenderRun->CreateAnimation("BigMarioFlower.bmp", "RunLeftFlower", 5, 7, 0.07f, true);
	RenderRun->CreateAnimation("BigMarioFlower.bmp", "TurnRightFlower", 8, 8, 100.0f, false);
	RenderRun->CreateAnimation("BigMarioFlower.bmp", "TurnLeftFlower", 9, 9, 10.0f, false);
	RenderRun->CreateAnimation("BigMarioFlower.bmp", "BMJRFlower", 10, 10, 0.1f, false);
	RenderRun->CreateAnimation("BigMarioFlower.bmp", "BMJLFlower", 11, 11, 0.1f, false);
	RenderRun->CreateAnimation("BigMarioFlower.bmp", "FlagFlower", 16, 17, 0.15f, true);
	RenderRun->CreateAnimation("BigMarioFlower.bmp", "EndFlower", 18, 18, 0.15f, false);
	RenderRun->CreateAnimation("MarioFire.bmp", "Fire", 0, 0, 0.15f, false);


	{
		GameEngineInput::GetInst()->CreateKey("BMMoveLeft", 'A');
		GameEngineInput::GetInst()->CreateKey("BMMoveRight", 'D');
		GameEngineInput::GetInst()->CreateKey("Fire", 'O');
		GameEngineInput::GetInst()->CreateKey("BMJump", VK_LSHIFT);
		// VK_LBUTTON; 마우스
	}
}

void BigPlayer::Update()
{

	if (Pause::PlayerStatus != "big")
	{
		return;
	}
	ColMap();
	if (Pause::star)
	{
		animation = "Star";
	}else
		if (Pause::flower)
		{
			animation = "Flower";
		}
		else
		{
			animation = "";
		}
	if (Change)
	{
		if (Changefirst)
		{
			Pause::PlayerPosition = Pause::PlayerPosition + float4{ 0, -20 };
			Changefirst = false;
		}
		ChangeTime = ChangeTime + GameEngineTime::GetDeltaTime();
		if (ChangeTime < 1.0f)
		{
			RenderRun->ChangeAnimation("Change");
		}
		else
		{
			ChangeTime = 0;
			Change = false;
			Changefirst = true;
			AnimationChange("BMRight");
		}
		return;
	}
	float4 CheckPos;
	if (Pause::end)
	{

		if (FirstEnd_)
		{
			AnimationChange("Flag");
			FirstEnd_ = false;
		}
		Time_ = Time_ + GameEngineTime::GetDeltaTime();
		MoveDir = float4::DOWN;
		float4 NextPos = GetPosition() + (MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		int Down = ColMap_->GetImagePixel(NextPos + float4(15.0f, 40.0f));
		int Right = ColMap_->GetImagePixel(NextPos + float4(20.0f, 0.0f));
		if ((RGB(0, 0, 0) != (Down)))
		{
			SetMove(MoveDir * GameEngineTime::GetDeltaTime() * 150);
			Pause::PlayerPosition == GetPosition();
		}
		if (1.2f  <= Time_
			&& 1.5f > Time_)
		{

			float MapSizeX = 8441;
			float MapSizeY = 550;
			SetPosition(float4{ MapSizeX - 470, 440});
			AnimationChange("End");
			Pause::PlayerPosition == GetPosition();
			return;
		}
		if (1.5f <= Time_)
		{
			AnimationChange("RunRight");
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
			  MoveDir += float4::RIGHT * GameEngineTime::GetDeltaTime() * 600;
			SetMove(MoveDir * GameEngineTime::GetDeltaTime() * 150);
	
			Pause::PlayerPosition == GetPosition();

		}
		return;
	}

	if (Pause::flower
		&&Pause::flowerfirst)
	{
		std::string A = RenderRun->CurrentAnimationName();
		if (flowerAnimation)
		{
			RenderRun->ChangeAnimation(RenderRun->CurrentAnimationName() + "Star");
			flowerAnimation = false;
		}
		AnimationTime_ = AnimationTime_ + GameEngineTime::GetDeltaTime();
		if (AnimationTime_ > 1.0f)
		{
			Pause::flowerfirst = false;
			flowerAnimation = true;
		}
		return;
	}

	//아무것도 안 누를때
	MoveDir += float4::DOWN * GameEngineTime::GetDeltaTime() * 100;
	if (true == GameEngineInput::GetInst()->IsDown("BMJump"))
	{
		MoveDir += float4::UP *10;
		GameEngineSound::SoundPlayOneShot("jumpbig.wav", 0);
	}
	if (true == GameEngineInput::GetInst()->IsPress("BMJump"))
	{

		MoveDir = MoveDir + float4::UP * GameEngineTime::GetDeltaTime() * 70;

	}

	if (true == GameEngineInput::GetInst()->IsPress("BMMoveLeft"))
	{
		AnimationChange("RunLeft");
		MoveDir += float4::LEFT * GameEngineTime::GetDeltaTime() * 10;

	}

	if (true == GameEngineInput::GetInst()->IsPress("Down"))
	{
		MoveDir += float4::DOWN;
	}
	if (true == GameEngineInput::GetInst()->IsDown("Fire"))
	{
		Bullet* Ptr = GetLevel()->CreateActor<Bullet>(2);
		Ptr->SetPosition(GetPosition());
		RenderRun->ChangeAnimation("Fire");
		GameEngineSound::SoundPlayOneShot("fireball.wav");
	}
	if (true == GameEngineInput::GetInst()->IsFree("BMJump"))
	{
		/*MoveDir += float4::DOWN * GameEngineTime::GetDeltaTime() * AccSpeed_;*/
	}

	if (true == GameEngineInput::GetInst()->IsPress("BMMoveRight"))
	{
		AnimationChange("RunRight");
		MoveDir += float4::RIGHT * GameEngineTime::GetDeltaTime() * 10;

	}



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

	if (true == BigPlayerCollision->CollisionCheck("MonsterTop", CollisionType::Rect, CollisionType::Rect))
	{
		MoveDir = float4::UP *10;
		AccGravity_ = 0;
		SetMove(MoveDir * GameEngineTime::GetDeltaTime() * Speed_ );
	}
	float4 NextPos = GetPosition() +float4 {0, 20};
	if (true == BigPlayerLeft_->CollisionCheck("MonsterRight", CollisionType::Rect, CollisionType::Rect)
		|| true == BigPlayerRight_->CollisionCheck("MonsterLeft", CollisionType::Rect, CollisionType::Rect)
		|| (RGB(0, 0, 255)== ColMap_->GetImagePixel(NextPos)))
	{
		Pause::PlayerStatus = "small";
		Pause::smallfirst = true;
		Pause::flower = false;
		Pause::flowerfirst = false;
		GameEngineSound::SoundPlayOneShot("shrink.wav", 0);
		return;
	}


	{
		float y = MoveDir.y;
		if (0.0f <= MoveDir.y
			&& -0.2f >= MoveDir.y)
		{
			MoveDir.y = -0.2f;
		}
	}
	if (0 < MoveDir.x)
	{
		if (true == GameEngineInput::GetInst()->IsPress("MoveLeft"))
		{
			AnimationChange("TurnLeft");
		}
	}
	if (0 > MoveDir.x)
	{
		if (true == GameEngineInput::GetInst()->IsPress("MoveRight"))
		{
			AnimationChange("TurnRight");
		}
	}
	
	float x = MoveDir.x;
	if (false == GameEngineInput::GetInst()->IsPress("BMMoveLeft") &&
		false == GameEngineInput::GetInst()->IsPress("BMMoveRight") &&
		false == GameEngineInput::GetInst()->IsPress("Down")
		)
	{
		MoveDir += -float4{x, 0}*GameEngineTime::GetDeltaTime() * 4;

		if (0.05f >= MoveDir.Len2D())
		{
			MoveDir = float4::ZERO;
			if (RenderRun->IsAnimationName(("RunRight") + animation)
				|| RenderRun->IsAnimationName(("TurnRight" + animation)))
			{
				AnimationChange("BMRight");
			}
			if (RenderRun->IsAnimationName(("RunLeft") + animation)
				|| RenderRun->IsAnimationName(("TurnLeft" + animation)))
			{
				AnimationChange("BMLeft");
			}
			return;
		}


		if (RenderRun->IsAnimationName(("RunRight") + animation)
			|| RenderRun->IsAnimationName(("TurnRight" + animation)))
		{
			AnimationChange("BMRight");
		}
		if (RenderRun->IsAnimationName(("RunLeft") + animation)
			|| RenderRun->IsAnimationName(("TurnLeft" + animation)))
		{
			AnimationChange("BMLeft");
		}



	}

	{
		float4 NextPos = GetPosition() + (MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
		float4 CheckPos = NextPos;
		float4 BigPlayerLeft = float4{ -20, 0 };
		float4 BigPlayerRight = float4{ 20, 0 };
		float4 BigPlayerDown = float4{ 0, 20 };

		int Color = ColMap_->GetImagePixel(NextPos + float4(0.0f, 39.0f));
		int Down1 = ColMap_->GetImagePixel(GetPosition() + float4(10.0f, 39.0f));
		int Down2 = ColMap_->GetImagePixel(GetPosition() + float4(-10.0f, 39.0f));
		int ColorUp = ColMap_->GetImagePixel(GetPosition() + float4(0.0f, -39.0f));


		if (((RGB(255, 255, 255) != Color) || true == Down_->NextPosCollisionCheck("Move", NextPos + float4(0.0f, 38.0f), CollisionType::Rect, CollisionType::Rect))
			&& GameEngineInput::GetInst()->IsFree("BMJump")
			)

		{
			if (RenderRun->IsAnimationName(("BMJL")+ animation))
			{
				AnimationChange("BMLeft");
			}
			else
				if (RenderRun->IsAnimationName(("BMJR") + animation))
				{
					AnimationChange("BMRight");
				}
			MoveDir.y =0;
			AccGravity_ = 0;
		}
		float4 LeftRight = { 0, 0 };
		float4 UpUp = { 0, 0 };
		float4 DownDown = { 0, 0 };
		int Left = ColMap_->GetImagePixel(NextPos + float4(-19.0f, 0.0f));
		int Right = ColMap_->GetImagePixel(NextPos + float4(19.0f, 0.0f));
		int Down = ColMap_->GetImagePixel(NextPos + float4(0.0f, 39.0f));
		int Up = ColMap_->GetImagePixel(NextPos + float4(0.0f, -39.0f));

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
		if (true != Move_->NextPosCollisionCheck("Move", NextPos, CollisionType::Rect, CollisionType::Rect))
		{
			if ((RGB(0, 0, 0) != (Left))
				&& LeftCheck
				)
			{
				SetMove(LeftRight * GameEngineTime::GetDeltaTime() * Speed_);
				CameraPos();
				Pause::PlayerPosition = GetPosition();
			}
		}
		if (true != Move_->NextPosCollisionCheck("Move", NextPos, CollisionType::Rect, CollisionType::Rect))
		{
			if ((RGB(0, 0, 0) != (Right))
				&& RightCheck
				)
			{
				SetMove(LeftRight * GameEngineTime::GetDeltaTime() * Speed_);
				CameraPos();
				Pause::PlayerPosition = GetPosition();
			}
		}
		if ((RGB(0, 0, 0) != (Up)))
		{

		}
		if (true != Up_->NextPosCollisionCheck("Move", NextPos, CollisionType::Rect, CollisionType::Rect))
		{
			if ((RGB(0, 0, 0) != (Up))
				&& UpCheck
				)

			{
				if (RenderRun->IsAnimationName(("RunRight") + animation)
					|| RenderRun->IsAnimationName(("BMRight") + animation)
					|| RenderRun->IsAnimationName(("BMJR") + animation))
				{
					AnimationChange("BMJR");
				}
				else if (RenderRun->IsAnimationName(("RunLeft") + animation)
					|| RenderRun->IsAnimationName(("BMLeft") + animation)
					|| RenderRun->IsAnimationName(("BMJL") + animation))
				{
					AnimationChange("BMJL");
				}
				SetMove(UpUp * GameEngineTime::GetDeltaTime() * Speed_);
				CameraPos();
			}
		}

		if (true != Down_->NextPosCollisionCheck("Move", NextPos + float4(0.0f, 38.0f), CollisionType::Rect, CollisionType::Rect)
			&& true != Down_->NextPosCollisionCheck("Move", GetPosition() + float4(8.0f, 38.0f), CollisionType::Rect, CollisionType::Rect)
			&& true != Down_->NextPosCollisionCheck("Move", GetPosition() + float4(-8.0f, 38.0f), CollisionType::Rect, CollisionType::Rect))
		{
			if ((RGB(0, 0, 0) != (Down)
				&& (RGB(0, 0, 0) != (Down1))
				&& (RGB(0, 0, 0) != (Down2))
				&& DownCheck)
				)

			{
				if (RenderRun->IsAnimationName("RunRight") || RenderRun->IsAnimationName("BMRight") || RenderRun->IsAnimationName("BMJR"))
				{
					AnimationChange("BMJR");
				}
				else if (RenderRun->IsAnimationName("RunLeft") || RenderRun->IsAnimationName("BMLeft") || RenderRun->IsAnimationName("BMJL"))
				{
					AnimationChange("BMJL");
				}
				SetMove(DownDown * GameEngineTime::GetDeltaTime() * Speed_);
				CameraPos();
			}

			Pause::PlayerPosition = GetPosition();
		}
	}
}

float BigPlayer::GetCurrentPosition()
{
	float x = GetPosition().x;
	return  x;
}

void BigPlayer::CameraPos()
{
	float MapSizeX = 0; 
	float MapSizeY = 0;
	float CameraRectX= 0;
	float CameraRectY = 0;
	if (WorldCount::WorldCountUI == 1)
	{
		MapSizeX = 8441;
		MapSizeY = 550;
		CameraRectX = 620;
		CameraRectY = 550;
	}
	if (Pause::end)
	{
		float4 CurCameraPos = {7830, 0};
		GetLevel()->SetCameraPos(CurCameraPos);
		return;
	}
	float Camera = GetLevel()->GetCameraPos().x;
	{
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


		if (MapSizeX <= GetLevel()->GetCameraPos().x + 625)
		{
			float4 CurCameraPos = GetLevel()->GetCameraPos();
			CurCameraPos.x = GetLevel()->GetCameraPos().x - (GetLevel()->GetCameraPos().x + CameraRectX - MapSizeX);
			GetLevel()->SetCameraPos(CurCameraPos);
		}
		float4 CurCameraPos = GetLevel()->GetCameraPos();
		CurCameraPos.y = 0;
		GetLevel()->SetCameraPos(CurCameraPos);
	}
}

void BigPlayer::HitBlock()
{


}
bool BigPlayer::RightBotCheck()
{
	float4 NextPos = GetPosition() + (MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
	float4 CheckPos = NextPos+ float4 {18, 40};
	int Color = ColMap_->GetImagePixel(CheckPos);
	if (RGB(0, 0, 0) == (Color))
	{
		return true;
	}
	else 
	{
		return false;
	}

}
bool BigPlayer::LeftBotCheck()
{
	float4 NextPos = GetPosition() + (MoveDir * GameEngineTime::GetDeltaTime() * Speed_);
	float4 CheckPos = NextPos + float4{ -18, 40 };
	int Color = ColMap_->GetImagePixel(CheckPos);
	if (RGB(0, 0, 0)== (Color))
	{
		return true;
	}

		return false;

}
// 랜더러가 다 돌아가고 랜더링
void BigPlayer::Render()
{

}
void BigPlayer::ColMap()
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


bool BigPlayer::Change = true;