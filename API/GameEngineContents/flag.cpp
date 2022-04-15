#include "flag.h"
#include "Pause.h"
#include "WorldCount.h"
#include "GameEngineBase/GameEngineSound.h"



flag::flag() 
{
}

flag::~flag() 
{
}

void flag::Createflag(const float4& _Pivot)
{
	{
		float4 Pivot = _Pivot;
		float4 CoPivot = Pivot;
		CoPivot.y = Pivot.y + 18;
		
		SetPosition(Pivot);
	}
}

void flag::Start()
{


	CreateRenderer("flag.bmp");

}

void flag::Update()
{
	if (Pause::end)
	{
		Time_ = Time_ + GameEngineTime::GetDeltaTime();
		if (Time_ >= 1.2f)
		{
			return;
		}
		SetMove(float4::DOWN * GameEngineTime::GetDeltaTime() * 250);
	}

}


