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
	One->SetTransColor(RGB(146, 144, 255));
	One->SetIndex(0);
	One->SetPivot(float4(780, 145));
	Two->CameraEffectOff();
	Two->SetTransColor(RGB(146, 144, 255));
	Two->SetPivot(float4(860, 145));
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
	if (1 == WorldCountUI)
	{
		Two->ChangeAnimation("3");
	}
	if (1 == WorldCountUI)
	{
		Two->ChangeAnimation("4");
	}
}

int WorldCount::WorldCountUI = 1;