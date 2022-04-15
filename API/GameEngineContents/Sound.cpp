#include "Sound.h"
#include "GameEngineBase/GameEngineSound.h"

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
	if (SoundPlay == "bgmplay")
	{
		BgmPlayer = GameEngineSound::SoundPlayControl("overworld.wav");
		SoundPlay = "";
	}
	if (SoundPlay =="end")
	{
		GameEngineSound::SoundPlayOneShot("castleend.wav", 0);
		SoundPlay = "";
	}
	if (SoundPlay == "stop")
	{
		BgmPlayer.Stop();
		SoundPlay = "";
	}
	
}

std::string Sound::SoundPlay = "";
