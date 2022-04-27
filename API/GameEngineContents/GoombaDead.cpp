#include "GoombaDead.h"

GoombaDead::GoombaDead() 
{
}

GoombaDead::~GoombaDead() 
{
}

void GoombaDead::Start()
{
	Actor = CreateRenderer("GoombaDead.bmp");
	Dir = (float4{ 50 , -500 });
}

void GoombaDead::Update()
{
	Dir += float4::DOWN * GameEngineTime::GetDeltaTime() * 1000.0f;

	SetMove(Dir * GameEngineTime::GetDeltaTime());
	Death(5.0f);
}

