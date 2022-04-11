#include "Sound.h"

Sound::Sound() 
{
}

Sound::~Sound() 
{
}

void Sound::Start()
{
	One = CreateRenderer("0.bmp");
	One->CameraEffectOff();
	One->SetTransColor(RGB(146, 144, 255));
	One->SetIndex(0);
	One->SetPivot(float4(300, 145));
	Time = 400.0f;
}

void Sound::Update()
{
	Time -= GameEngineTime::GetDeltaTime();
	if (SoundPlay == "Coin")
	{
		Coin = GameEngineSound::SoundPlayControl("Coin.WAV");
		SoundPlay = "";
		Time = 0.8f;
		Coin.Stop();
	}
	if (Time <= 0.0f)
	{
		Coin.Stop();
		Time = 400.0f;
	}
}

std::string Sound::SoundPlay = "";
