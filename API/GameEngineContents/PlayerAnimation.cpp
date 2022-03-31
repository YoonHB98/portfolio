//#include "PlayerAnimation.h"
//#include <GameEngine/GameEngine.h>
//#include <GameEngineBase/GameEngineWindow.h>
//#include <GameEngine/GameEngineImageManager.h>
//#include <GameEngineBase/GameEngineInput.h>
//#include <GameEngineBase/GameEngineTime.h>
//#include <GameEngine/GameEngineRenderer.h>
//
//#include <GameEngine/GameEngineLevel.h> // 레벨을 통해서
//// #include "이걸 " 만들때 
//PlayerAnimation::PlayerAnimation()
//	: Speed_(100.0f)
//{
//}
//
//PlayerAnimation::~PlayerAnimation()
//{
//}
//
//
//
//void PlayerAnimation::CreateAnimation()
//{
//
//	
//
//	RenderRun = CreateRenderer("Mario.bmp");
//	RenderRun->SetTransColor(RGB(146, 144, 255));
//	RenderRun->SetIndex(0);
//	RenderRun->CreateAnimation("Mario.bmp", "MarioRight", 0, 0, 0.1f, false);
//	RenderRun->CreateAnimation("Mario.bmp", "MarioLeft", 1, 1, 0.1f, false);
//	RenderRun->CreateAnimation("Mario.bmp", "RunRight", 2, 4, 0.1f, true);
//	RenderRun->CreateAnimation("Mario.bmp", "RunLeft", 5, 7, 0.1f, true);
//	RenderRun->CreateAnimation("Mario.bmp", "TurnRight", 8, 8, 0.1f, false);
//	RenderRun->CreateAnimation("Mario.bmp", "TurnLeft", 9, 9, 0.1f, false);
//	RenderRun->CreateAnimation("Mario.bmp", "JumpRight", 10, 10, 0.1f, false);
//	RenderRun->CreateAnimation("Mario.bmp", "JumpLeft", 11, 11, 0.1f, false);
//
//
//
//}
//void  PlayerAnimation::ChangeAnimation(const std::string& _name)
//{
//	RenderRun->ChangeAnimation(_name);
//
//}