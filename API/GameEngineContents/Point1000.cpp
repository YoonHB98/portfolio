#include "Point1000.h"

Point1000::Point1000() 
{
}

Point1000::~Point1000() 
{
}

void Point1000::Start()
{
	CreateRenderer("1000.bmp");

	Death(1.0f);
}

void Point1000::Update()
{
	SetMove(float4::UP * GameEngineTime::GetDeltaTime() * 100.0f);
}

