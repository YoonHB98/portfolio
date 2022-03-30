#include "PlayerAnimation.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineRenderer.h>

#include <GameEngine/GameEngineLevel.h> // 레벨을 통해서
// #include "이걸 " 만들때 
PlayerAnimation::PlayerAnimation()
	: Speed_(100.0f)
{
}

PlayerAnimation::~PlayerAnimation()
{
}



void PlayerAnimation::RunRight()
{
	SetPosition(float4{ 0, 1078 });

	//GameEngineRenderer* Render = CreateRenderer("Mario.bmp");
	//Render->SetTransColor(RGB(146, 144, 255));


	GameEngineRenderer* RenderRun = CreateRenderer("RunRight.bmp");
	RenderRun->SetTransColor(RGB(146, 144, 255));
	RenderRun->SetIndex(0);
	RenderRun->CreateAnimation("RunRight.bmp", "RunRight", 0, 2, 1.0f, true);


}