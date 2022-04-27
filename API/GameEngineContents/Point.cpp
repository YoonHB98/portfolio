#include "Point.h"

Point::Point() 
{
}

Point::~Point() 
{
}


void Point::Start()
{
	GameEngineRenderer* PP = CreateRenderer("number.bmp");
	PP->CameraEffectOff();
	PP->SetPivot(float4(60, 73));
	PP->SetIndex(9);
	GameEngineRenderer* PPP = CreateRenderer("number.bmp");
	PPP->CameraEffectOff();
	PPP->SetPivot(float4(40, 73));
	PPP->SetIndex(9);
	One = CreateRenderer("0.bmp");
	One->CameraEffectOff();
	One->SetIndex(0);
	One->SetPivot(float4(140,73));
	Two= CreateRenderer("0.bmp");
	Two->CameraEffectOff();
	Two->SetIndex(0);
	Two->SetPivot(float4(160, 73));
	Three = CreateRenderer("number.bmp");
	Four = CreateRenderer("number.bmp");
	Five = CreateRenderer("number.bmp");
	Three->CameraEffectOff();
	Three->SetIndex(0);
	Three->SetPivot(float4(120, 73));
	Four->CameraEffectOff();
	Four->SetPivot(float4(100, 73));
	Four->SetIndex(0);
	Five->CameraEffectOff();
	Five->SetPivot(float4(80, 73));
	Five->SetIndex(0);
	One->CreateAnimation("number.bmp", "1", 0, 0, 1.0f, false);
	One->CreateAnimation("number.bmp", "2", 1, 1, 1.0f, false);
	One->CreateAnimation("number.bmp", "3", 2, 2, 1.0f, false);
	One->CreateAnimation("number.bmp", "4", 3, 3, 1.0f, false);
	One->CreateAnimation("number.bmp", "5", 4, 4, 1.0f, false);
	One->CreateAnimation("number.bmp", "6", 5, 5, 1.0f, false);
	One->CreateAnimation("number.bmp", "7", 6, 6, 1.0f, false);
	One->CreateAnimation("number.bmp", "8", 7, 7, 1.0f, false);
	One->CreateAnimation("number.bmp", "9", 8, 8, 1.0f, false);
	One->CreateAnimation("number.bmp", "0", 9, 9, 1.0f, false);
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
	Three->CreateAnimation("number.bmp", "1", 0, 0, 1.0f, false);
	Three->CreateAnimation("number.bmp", "2", 1, 1, 1.0f, false);
	Three->CreateAnimation("number.bmp", "3", 2, 2, 1.0f, false);
	Three->CreateAnimation("number.bmp", "4", 3, 3, 1.0f, false);
	Three->CreateAnimation("number.bmp", "5", 4, 4, 1.0f, false);
	Three->CreateAnimation("number.bmp", "6", 5, 5, 1.0f, false);
	Three->CreateAnimation("number.bmp", "7", 6, 6, 1.0f, false);
	Three->CreateAnimation("number.bmp", "8", 7, 7, 1.0f, false);
	Three->CreateAnimation("number.bmp", "9", 8, 8, 1.0f, false);
	Three->CreateAnimation("number.bmp", "0", 9, 9, 1.0f, false);
	Four->CreateAnimation("number.bmp", "1", 0, 0, 1.0f, false);
	Four->CreateAnimation("number.bmp", "2", 1, 1, 1.0f, false);
	Four->CreateAnimation("number.bmp", "3", 2, 2, 1.0f, false);
	Four->CreateAnimation("number.bmp", "4", 3, 3, 1.0f, false);
	Four->CreateAnimation("number.bmp", "5", 4, 4, 1.0f, false);
	Four->CreateAnimation("number.bmp", "6", 5, 5, 1.0f, false);
	Four->CreateAnimation("number.bmp", "7", 6, 6, 1.0f, false);
	Four->CreateAnimation("number.bmp", "8", 7, 7, 1.0f, false);
	Four->CreateAnimation("number.bmp", "9", 8, 8, 1.0f, false);
	Four->CreateAnimation("number.bmp", "0", 9, 9, 1.0f, false);
	Five->CreateAnimation("number.bmp", "1", 0, 0, 1.0f, false);
	Five->CreateAnimation("number.bmp", "2", 1, 1, 1.0f, false);
	Five->CreateAnimation("number.bmp", "3", 2, 2, 1.0f, false);
	Five->CreateAnimation("number.bmp", "4", 3, 3, 1.0f, false);
	Five->CreateAnimation("number.bmp", "5", 4, 4, 1.0f, false);
	Five->CreateAnimation("number.bmp", "6", 5, 5, 1.0f, false);
	Five->CreateAnimation("number.bmp", "7", 6, 6, 1.0f, false);
	Five->CreateAnimation("number.bmp", "8", 7, 7, 1.0f, false);
	Five->CreateAnimation("number.bmp", "9", 8, 8, 1.0f, false);
	Five->CreateAnimation("number.bmp", "0", 9, 9, 1.0f, false);
	One->ChangeAnimation("0");
	Two->ChangeAnimation("0");
	Three->ChangeAnimation("0");
	Four->ChangeAnimation("0");
	Five->ChangeAnimation("0");
	
}

void Point::Update()
{
	int PointTwo = static_cast<int>(PointUI) / (10);
	int PointThree = static_cast<int>(PointUI) / (100);
	int PointFour = static_cast<int>(PointUI) / (1000);
	int PointFive = static_cast<int>(PointUI) / (10000);
	if ((0 == static_cast<int>(PointUI) % 10))
	{
		One->ChangeAnimation("0");
	}
	if (1 == static_cast<int>(PointUI) % 10)
	{
		One->ChangeAnimation("1");
	}
	if (2 == static_cast<int>(PointUI) % 10)
	{
		One->ChangeAnimation("2");
	}
	if (3 == static_cast<int>(PointUI) % 10)
	{
		One->ChangeAnimation("3");
	}
	if (4 == static_cast<int>(PointUI) % 10)
	{
		One->ChangeAnimation("4");
	}
	if (5 == static_cast<int>(PointUI) % 10)
	{
		One->ChangeAnimation("5");
	}
	if (6 == static_cast<int>(PointUI) % 10)
	{
		One->ChangeAnimation("6");
	}
	if (7 == static_cast<int>(PointUI) % 10)
	{
		One->ChangeAnimation("7");
	}
	if (8 == static_cast<int>(PointUI) % 10)
	{
		One->ChangeAnimation("8");
	}
	if (9 == static_cast<int>(PointUI) % 10)
	{
		One->ChangeAnimation("9");
	}
	if ((0 == PointTwo % 10))
	{
		Two->ChangeAnimation("0");
	}
	if (1 == PointTwo % 10)
	{
		Two->ChangeAnimation("1");
	}
	if (2 == PointTwo  % 10)
	{
		Two->ChangeAnimation("2");
	}
	if (3 == PointTwo  % 10)
	{
		Two->ChangeAnimation("3");
	}
	if (4 == PointTwo  % 10)
	{
		Two->ChangeAnimation("4");
	}
	if (5 == PointTwo  % 10)
	{
		Two->ChangeAnimation("5");
	}
	if (6 == PointTwo  % 10)
	{
		Two->ChangeAnimation("6");
	}
	if (7 == PointTwo  % 10)
	{
		Two->ChangeAnimation("7");
	}
	if (8 == PointTwo  % 10)
	{
		Two->ChangeAnimation("8");
	}
	if (9 == PointTwo  % 10)
	{
		Two->ChangeAnimation("9");
	}
	if ((0 == PointThree % 10))
	{
		Three->ChangeAnimation("0");
	}
	if (1 == PointThree % 10)
	{
		Three->ChangeAnimation("1");
	}
	if (2 == PointThree % 10)
	{
		Three->ChangeAnimation("2");
	}
	if (3 == PointThree % 10)
	{
		Three->ChangeAnimation("3");
	}
	if (4 == PointThree % 10)
	{
		Three->ChangeAnimation("4");
	}
	if (5 == PointThree % 10)
	{
		Three->ChangeAnimation("5");
	}
	if (6 == PointThree % 10)
	{
		Three->ChangeAnimation("6");
	}
	if (7 == PointThree % 10)
	{
		Three->ChangeAnimation("7");
	}
	if (8 == PointThree % 10)
	{
		Three->ChangeAnimation("8");
	}
	if (9 == PointThree % 10)
	{
		Three->ChangeAnimation("9");
	}
	if ((0 == PointThree % 10))
	{
		Four->ChangeAnimation("0");
	}
	if (1 == PointFour % 10)
	{
		Four->ChangeAnimation("1");
	}
	if (2 == PointFour % 10)
	{
		Four->ChangeAnimation("2");
	}
	if (3 == PointFour % 10)
	{
		Four->ChangeAnimation("3");
	}
	if (4 == PointFour % 10)
	{
		Four->ChangeAnimation("4");
	}
	if (5 == PointFour % 10)
	{
		Four->ChangeAnimation("5");
	}
	if (6 == PointFour % 10)
	{
		Four->ChangeAnimation("6");
	}
	if (7 == PointFour % 10)
	{
		Four->ChangeAnimation("7");
	}
	if (8 == PointFour % 10)
	{
		Four->ChangeAnimation("8");
	}
	if (9 == PointFour % 10)
	{
		Four->ChangeAnimation("9");
	}
	if ((0 == PointFive % 10))
	{
		Five->ChangeAnimation("0");
	}
	if (1 == PointFive % 10)
	{
		Five->ChangeAnimation("1");
	}
	if (2 == PointFive % 10)
	{
		Five->ChangeAnimation("2");
	}
	if (3 == PointFive % 10)
	{
		Five->ChangeAnimation("3");
	}
	if (4 == PointFive % 10)
	{
		Five->ChangeAnimation("4");
	}
	if (5 == PointFive % 10)
	{
		Five->ChangeAnimation("5");
	}
	if (6 == PointFive % 10)
	{
		Five->ChangeAnimation("6");
	}
	if (7 == PointFive % 10)
	{
		Five->ChangeAnimation("7");
	}
	if (8 == PointFive % 10)
	{
		Five->ChangeAnimation("8");
	}
	if (9 == PointFive % 10)
	{
		Five->ChangeAnimation("9");
	}
		
			
	
}

float Point::PointUI = 0;
float Point::TimePoint = 0;