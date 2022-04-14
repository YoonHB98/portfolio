#include "Castle.h"
#include "Pause.h"
#include "WorldCount.h"
#include "GameEngineBase/GameEngineSound.h"


Castle::Castle() 
{
}

Castle::~Castle() 
{
}

void Castle::CreateCastle(const float4& _Pivot)
{
	{
		float4 Pivot = _Pivot;
		float4 CoPivot = Pivot;
		CoPivot.y = Pivot.y + 36;
		
		SetPosition(Pivot);
	}
}

void Castle::Start()
{
	//Actor->SetPosition(Pivot);
	//Actor->CreateCollision("Castle", { 80, 10 }, CoPivot);
	EndCollision = CreateCollision("Castle", {20, 1200 }, { -520, 0 });

	CreateRenderer("Castle.bmp");

}

void Castle::Update()
{
	if (true == EndCollision->CollisionCheck("PlayerItem", CollisionType::Rect, CollisionType::Rect)
		&& Pause::first)
	{
		Pause::first = false;
		Pause::end = true;
		WorldCount::WorldCountUI = WorldCount::WorldCountUI + 1;
		GameEngineSound::SoundPlayOneShot("castleend.wav");
	}
}

void Castle::Render()
{
}

