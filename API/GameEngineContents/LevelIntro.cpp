#include "LevelIntro.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineInput.h>
#include<GameEngine/GameEngine.h>
#include <GameEngine/GameEngineLevel.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineTime.h>
#include "Coin.h"
#include "WorldCount.h"

int LevelIntro::DeathCount = 3;
LevelIntro::LevelIntro() 
{
}

LevelIntro::~LevelIntro() 
{
}

void LevelIntro::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());
	CreateRenderer("StageIntro.BMP");

	GameEngineRenderer* Name = CreateRenderer("Name.bmp");
	Name->SetPivot(float4(-210, -250));
	Name->CameraEffectOff();

	Count = CreateRenderer("number.bmp");
	Count->SetIndex(0);
	Count->SetPivot(float4(50,-10 ));
	Count->CreateAnimation("number.bmp", "1",0, 0, 1.0f, false);
	Count->CreateAnimation("number.bmp", "2", 1, 1, 1.0f, false);
	Count->CreateAnimation("number.bmp", "3", 2, 2, 1.0f, false);
	Count->CreateAnimation("number.bmp", "4", 3, 3, 1.0f, false);
	Count->CreateAnimation("number.bmp", "5", 4, 4, 1.0f, false);
	Count->CreateAnimation("number.bmp", "6", 5, 5, 1.0f, false);
	Count->CreateAnimation("number.bmp", "7", 6, 6, 1.0f, false);
	Count->CreateAnimation("number.bmp", "8", 7, 7, 1.0f, false);
	Count->CreateAnimation("number.bmp", "9", 8, 8, 1.0f, false);
	Count->CreateAnimation("number.bmp", "0", 9, 9, 1.0f, false);
	Count->ChangeAnimation("0");

	GameEngineRenderer* Stage = CreateRenderer("number.BMP");
	Stage->SetPivot(float4(30, -90));
	Stage->CameraEffectOff();
	Stage->SetIndex(0);
	StageCount = CreateRenderer("number.bmp");
	StageCount->SetIndex(0);
	StageCount->SetPivot(float4(70, -90));
	StageCount->CreateAnimation("number.bmp", "1", 0, 0, 1.0f, false);
	StageCount->CreateAnimation("number.bmp", "2", 1, 1, 1.0f, false);
	StageCount->CreateAnimation("number.bmp", "3", 2, 2, 1.0f, false);
	StageCount->CreateAnimation("number.bmp", "4", 3, 3, 1.0f, false);
	StageCount->CreateAnimation("number.bmp", "5", 4, 4, 1.0f, false);
	StageCount->CreateAnimation("number.bmp", "6", 5, 5, 1.0f, false);
	StageCount->CreateAnimation("number.bmp", "7", 6, 6, 1.0f, false);
	StageCount->CreateAnimation("number.bmp", "8", 7, 7, 1.0f, false);
	StageCount->CreateAnimation("number.bmp", "9", 8, 8, 1.0f, false);
	StageCount->CreateAnimation("number.bmp", "0", 9, 9, 1.0f, false);
	StageCount->ChangeAnimation("0");



		Time_ = 3.0f;

}

void LevelIntro::Update()
{
	if (9 == DeathCount)
	{
		Count->ChangeAnimation("9");
	}
	if (8 == DeathCount)
	{
		Count->ChangeAnimation("8");
	}
	if (7 == DeathCount)
	{
		Count->ChangeAnimation("7");
	}
	if (6 == DeathCount)
	{
		Count->ChangeAnimation("6");
	}
	if (5 == DeathCount)
	{
		Count->ChangeAnimation("5");
	}
	if (4 == DeathCount)
	{
		Count->ChangeAnimation("4");
	}
	if (3 == DeathCount)
	{
		Count->ChangeAnimation("3");
	}
	if (2 == DeathCount)
	{
		Count->ChangeAnimation("2");
	}
	if (1 == DeathCount)
	{
		Count->ChangeAnimation("1");
	}
	if (0 == DeathCount)
	{
		Count->ChangeAnimation("0");
	}
	if (9 == WorldCount::WorldCountUI)
	{
		StageCount->ChangeAnimation("9");
	}
	if (8 == WorldCount::WorldCountUI)
	{
		StageCount->ChangeAnimation("8");
	}
	if (7 == WorldCount::WorldCountUI)
	{
		Count->ChangeAnimation("7");
	}
	if (6 == WorldCount::WorldCountUI)
	{
		StageCount->ChangeAnimation("6");
	}
	if (5 == WorldCount::WorldCountUI)
	{
		StageCount->ChangeAnimation("5");
	}
	if (4 == WorldCount::WorldCountUI)
	{
		StageCount->ChangeAnimation("4");
	}
	if (3 == WorldCount::WorldCountUI)
	{
		StageCount->ChangeAnimation("3");
	}
	if (2 == WorldCount::WorldCountUI)
	{
		StageCount->ChangeAnimation("2");
	}
	if (1 == WorldCount::WorldCountUI)
	{
		StageCount->ChangeAnimation("1");
	}
	if (0 == WorldCount::WorldCountUI)
	{
		StageCount->ChangeAnimation("0");
	}
	Time_ = Time_ - GameEngineTime::GetDeltaTime();
	if (Time_ <= 0.0f
		&& 1 == WorldCount::WorldCountUI)
	{
		Time_ = 3.0f;
		GameEngine::GetInst().ChangeLevel("Stage1");
	}
}

void LevelIntro::Render()
{

}