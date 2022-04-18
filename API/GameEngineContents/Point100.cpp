#include "Point100.h"

Point100::Point100() 
{
}

Point100::~Point100() 
{
}

void Point100::Start()
{
	CreateRenderer("100.bmp");

	Death(1.0f);
}

void Point100::Update()
{
	SetMove(float4::UP * GameEngineTime::GetDeltaTime() * 100.0f);
}

