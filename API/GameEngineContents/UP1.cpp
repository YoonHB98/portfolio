#include "UP1.h"

UP1::UP1() 
{
}

UP1::~UP1() 
{
}

void UP1::Start()
{
	CreateRenderer("1UP.bmp");

	Death(1.0f);
}

void UP1::Update()
{
	SetMove(float4::UP * GameEngineTime::GetDeltaTime() * 150.0f);
}

