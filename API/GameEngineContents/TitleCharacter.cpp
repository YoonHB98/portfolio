#include "TitleCharacter.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineInput.h>
#include<GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>
#pragma comment(lib, "msimg32.lib")

TitleCharacter::TitleCharacter()
{
}

TitleCharacter::~TitleCharacter()
{
}

void TitleCharacter::Start()
{
	SetPosition(float4{0, 1078});



	CreateRenderer("Mario.bmp");
	
}


void TitleCharacter::Update()
{

	SetMove(float4::RIGHT * GameEngineTime::GetDeltaTime() * 500.0f);
	float4 A = GetPosition();
	if (A.x >= 1360)
	{
		SetPosition(float4{ 0, 1078 });

	}

}
