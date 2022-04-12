#include "TitleCharacter.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineInput.h>
#include<GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngine/GameEngineActor.h>
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


	TitleChar = CreateRenderer("Mario.bmp");
	TitleChar->SetPivot({ 100, 100 });
	TitleChar->SetTransColor(RGB(146, 144, 255));
	TitleChar->SetIndex(0);

	
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
