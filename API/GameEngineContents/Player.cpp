#include "Player.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineRenderer.h>
#include "PlayerAnimation.h"

#include <GameEngine/GameEngineLevel.h> // 레벨을 통해서
// #include "이걸 " 만들때 
Player::Player()
	: Speed_(100.0f)
{
}

Player::~Player()
{
}



void Player::Start()
{
	SetPosition(float4{ 0, 1078 });

	GameEngineRenderer* Render = CreateRenderer("Mario.bmp");
	Render->SetTransColor(RGB(146, 144, 255));




	


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
	GameEngineRenderer* RenderRun = CreateRenderer("RunRight.bmp");
	RenderRun->SetTransColor(RGB(146, 144, 255));
	RenderRun->SetIndex(0);
	RenderRun->CreateAnimation("RunRight.bmp", "RunRight", 0, 2, 0.1f, true);

	if (true == GameEngineInput::GetInst()->IsPress("MoveLeft"))
	{

		SetMove(float4::LEFT /** GameEngineTime::GetDeltaTime()*/);
	}

	if (true == GameEngineInput::GetInst()->IsPress("MoveRight"))
	{
		RenderRun->ChangeAnimation("RunRight");
		SetMove(float4::RIGHT);
	}
	if (true == GameEngineInput::GetInst()->IsPress("Jump"))
	{
		SetMove(float4::UP);
	}

	// 내가 키를 눌렀다면 움직여라.
	//if (0 != GetAsyncKeyState('A'))
	//{
	//	int a = 0;
	//}

}

// 랜더러가 다 돌아가고 랜더링
void Player::Render()
{

}
