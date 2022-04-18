#include "Point200.h"

Point200::Point200() 
{
}

Point200::~Point200() 
{
}

void Point200::Start()
{
	CreateRenderer("200.bmp");

	Death(1.0f);
}

void Point200::Update()
{
	SetMove(float4::UP * GameEngineTime::GetDeltaTime() * 200.0f);
}

