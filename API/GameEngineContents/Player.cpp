#include "Player.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineRenderer.h>
#include "PlayerAnimation.h"

#include <GameEngine/GameEngineLevel.h> // ������ ���ؼ�
// #include "�̰� " ���鶧 
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
		// �̶� �빮�ڿ��� �մϴ�.
		GameEngineInput::GetInst()->CreateKey("MoveLeft", 'A');
		GameEngineInput::GetInst()->CreateKey("MoveRight", 'D');
		GameEngineInput::GetInst()->CreateKey("Jump", VK_LSHIFT);
		// VK_LBUTTON; ���콺
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
