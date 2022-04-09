#include "Coin.h"

Coin::Coin() 
{
}

Coin::~Coin() 
{
}




void Coin::Start()
{
	
	Actor = CreateRenderer("blank.bmp");

	Actor->CreateAnimation("UICOIN.bmp", "100", 0, 2, 0.2f, true);
	Actor->ChangeAnimation("100");
	Actor->SetPivot(float4{ 460, 145 });
	Actor->CameraEffectOff();
	Actor->SetIndex(0);

	One = CreateRenderer("number.bmp");
	Two = CreateRenderer("number.bmp");;
	One->CameraEffectOff();
	One->SetTransColor(RGB(146, 144, 255));
	One->SetIndex(0);
	One->SetPivot(float4(580, 145));
	Two->CameraEffectOff();
	Two->SetTransColor(RGB(146, 144, 255));
	Two->SetPivot(float4(540, 145));
	Two->SetIndex(0);
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
}

void Coin::Update()
{
	if (0 == CoinUI % 100)
	{
		Two->ChangeAnimation("0");
	}
	if ((10 <= CoinUI % 100)
		&& 19>= CoinUI % 100)
	{
		Two->ChangeAnimation("1");
	}
	if ((20 <= CoinUI % 100)
		&& 29 >= CoinUI % 100)
	{
		Two->ChangeAnimation("2");
	}
	if ((30 <= CoinUI % 100)
		&& 39 >= CoinUI % 100)
	{
		Two->ChangeAnimation("3");
	}
	if ((40 <= CoinUI % 100)
		&& 49 >= CoinUI % 100)
	{
		Two->ChangeAnimation("4");
	}
	if ((50 <= CoinUI % 100)
		&& 59 >= CoinUI % 100)
	{
		Two->ChangeAnimation("5");
	}
	if ((60 <= CoinUI % 100)
		&& 69 >= CoinUI % 100)
	{
		Two->ChangeAnimation("6");
	}
	if ((70 <= CoinUI % 100)
		&& 79 >= CoinUI % 100)
	{
		Two->ChangeAnimation("7");
	}
	if ((80 <= CoinUI % 100)
		&& 89 >= CoinUI % 100)
	{
		Two->ChangeAnimation("8");
	}
	if ((90 <= CoinUI % 100)
		&& 99 >= CoinUI % 100)
	{
		Two->ChangeAnimation("9");
	}
	if (0 == CoinUI % 10)
	{
		One->ChangeAnimation("0");
	}
	if (1 == CoinUI % 10)
	{
		One->ChangeAnimation("1");
	}
	if (2 == CoinUI % 10)
	{
		One->ChangeAnimation("2");
	}
	if (3 == CoinUI % 10)
	{
		One->ChangeAnimation("3");
	}
	if (4 == CoinUI % 10)
	{
		One->ChangeAnimation("4");
	}
	if (5 == CoinUI % 10)
	{
		One->ChangeAnimation("5");
	}
	if (6 == CoinUI % 10)
	{
		One->ChangeAnimation("6");
	}
	if (7 == CoinUI % 10)
	{
		One->ChangeAnimation("7");
	}
	if (8 == CoinUI % 10)
	{
		One->ChangeAnimation("8");
	}
	if (9 == CoinUI % 10)
	{
		One->ChangeAnimation("9");
	}

}

void Coin::Render()
{
}
int Coin::CoinUI = 0;