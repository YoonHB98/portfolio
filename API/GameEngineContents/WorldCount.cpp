#include "WorldCount.h"

WorldCount::WorldCount() 
{
}

WorldCount::~WorldCount() 
{
}


void WorldCount::Start()
{

	One = CreateRenderer("number.bmp");
	Two = CreateRenderer("number.bmp");
	One->CameraEffectOff();
	One->SetIndex(0);
	One->SetPivot(float4(380, 72));
	Two->CameraEffectOff();
	Two->SetPivot(float4(420, 72));
	Two->SetIndex(0);
	Two->CreateAnimation("number.bmp", "1", 0, 0, 1.0f, false);
	Two->CreateAnimation("number.bmp", "2", 1, 1, 1.0f, false);
	Two->CreateAnimation("number.bmp", "3", 2, 2, 1.0f, false);
	Two->CreateAnimation("number.bmp", "4", 3, 3, 1.0f, false);
	Two->CreateAnimation("number.bmp", "5", 4, 4, 1.0f, false);
	Two->CreateAnimation("number.bmp", "6", 5, 5, 1.0f, false);
	Two->CreateAnimation("number.bmp", "7", 6, 6, 1.0f, false);
	Two->CreateAnimation("number.bmp", "8", 7, 7, 1.0f, false);
	Two->CreateAnimation("number.bmp", "9", 8, 8, 1.0f, false);
	Two->CreateAnimation("number.bmp", "0", 9, 9, 1.0f, false);
	
}

void WorldCount::Update()
{
	if ( 1==WorldCountUI)
	{
		Two->ChangeAnimation("1");
	}
	if (2 == WorldCountUI)
	{
		Two->ChangeAnimation("2");
	}
	if (3 == WorldCountUI)
	{
		Two->ChangeAnimation("3");
	}
	if (4 == WorldCountUI)
	{
		Two->ChangeAnimation("4");
	}
}

int WorldCount::WorldCountUI = 1;
bool WorldCount::Under = false;