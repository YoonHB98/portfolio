#include "CastleFlag.h"
#include "Pause.h"
#include "WorldCount.h"
#include "GameEngineBase/GameEngineSound.h"
#include <GameEngine/GameEngine.h>



CastleFlag::CastleFlag() 
{
}

CastleFlag::~CastleFlag() 
{
}

void CastleFlag::CreateCastleFlag(const float4& _Pivot)
{
	{
		float4 Pivot = _Pivot;
		float4 CoPivot = Pivot;
		CoPivot.y = Pivot.y + 18;
		
		SetPosition(Pivot);
	}
}

void CastleFlag::Start()
{
	CreateRenderer("CastleFlag.bmp");
}

void CastleFlag::Update()
{
	if (Pause::end)
	{
		Time_ = Time_ + GameEngineTime::GetDeltaTime();
		if (Time_ > 4.0f)
		{
			WorldCount::WorldCountUI = WorldCount::WorldCountUI + 1;
			GameEngine::GetInst().ChangeLevel("StageIntro");
			return;
		}
		if (Time_ > 1.35f)
		{
			return;
		}
		SetMove(float4::UP * GameEngineTime::GetDeltaTime() * 50);
	}

}


