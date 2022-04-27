#include "TurtleDeath.h"

TurtleDeath::TurtleDeath() 
{
}

TurtleDeath::~TurtleDeath() 
{
}

void TurtleDeath::Start()
{
	Actor = CreateRenderer("TurtleDeath.bmp");
	Dir = (float4{ 50 , -500 });
}

void TurtleDeath::Update()
{
	Dir += float4::DOWN * GameEngineTime::GetDeltaTime() * 1000.0f;

	SetMove(Dir * GameEngineTime::GetDeltaTime());
	Death(5.0f);
}

