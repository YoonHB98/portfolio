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
	Three->ChangeAnimation("0");
	Four->ChangeAnimation("0");
	Five->ChangeAnimation("0");
	
}

void Point::Update()
{
		if ((0<= PointUI % 1000)
			&& (99 >= PointUI % 1000))
		{
		Three->ChangeAnimation("0");
		}
		if ((100 <= PointUI % 1000)
			&& (199 >= PointUI % 1000))
		{
			Three->ChangeAnimation("1");
		} 
		if ((200 <= PointUI % 1000)
			&& (299 >= PointUI % 1000))
		{
			Three->ChangeAnimation("2");
		}
		if ((300 <= PointUI % 1000)
			&& (399 >= PointUI % 1000))
		{
			Three->ChangeAnimation("3");
		}
		if ((400 <= PointUI % 1000)
			&& (499 >= PointUI % 1000))
		{
			Three->ChangeAnimation("4");
		}
		if ((500 <= PointUI % 1000)
			&& (599 >= PointUI % 1000))
		{
			Three->ChangeAnimation("5");
		}
		if ((600 <= PointUI % 1000)
			&& (699 >= PointUI % 1000))
		{
			Three->ChangeAnimation("6");
		}
		if ((700 <= PointUI % 1000)
			&& (799 >= PointUI % 1000))
		{
			Three->ChangeAnimation("7");
		}
		if ((800 <= PointUI % 1000)
			&& (899 >= PointUI % 1000))
		{
			Three->ChangeAnimation("8");
		}
		if ((900 <= PointUI % 1000)
			&& (999 >= PointUI % 1000))
		{
			Three->ChangeAnimation("9");
		}
		if (0 == PointUI % 1000)
		{
			Three->ChangeAnimation("0");
		}
		if ((1000 <= PointUI % 10000)
			&& (1999 >= PointUI % 10000))
		{
			Four->ChangeAnimation("1");
		}
		if ((2000 <= PointUI % 10000)
			&& (2999 >= PointUI % 10000))
		{
			Four->ChangeAnimation("2");
		}
		if ((3000 <= PointUI % 10000)
			&& (3999 >= PointUI % 10000))
		{
			Four->ChangeAnimation("3");
		}
		if ((4000 <= PointUI % 10000)
			&& (4999 >= PointUI % 10000))
		{
			Four->ChangeAnimation("4");
		}
		if ((5000 <= PointUI % 10000)
			&& (5999 >= PointUI % 10000))
		{
			Four->ChangeAnimation("5");
		}
		if ((6000 <= PointUI % 10000)
			&& (6999 >= PointUI % 10000))
		{
			Four->ChangeAnimation("6");
		}
		if ((7000 <= PointUI % 10000)
			&& (7999 >= PointUI % 10000))
		{
			Four->ChangeAnimation("7");
		}
		if ((8000 <= PointUI % 10000)
			&& (8999 >= PointUI % 10000))
		{
			Four->ChangeAnimation("8");
		}
		if ((9000 <= PointUI % 10000)
			&& (9999 >= PointUI % 10000))
		{
			Four->ChangeAnimation("9");
		}
			
	
}

int Point::PointUI = 0;