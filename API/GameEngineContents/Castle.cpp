#include "Castle.h"
#include "Pause.h"
#include "WorldCount.h"
#include "GameEngineBase/GameEngineSound.h"
#include "CastleFlag.h"


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
	EndCollision = CreateCollision("Castle", {10,2000 }, { -238, -400 });

	CreateRenderer("Castle.bmp");

}

void Castle::Update()
{
	if (Pause::flag
		&& flagfirst)
	{
		flagfirst = false;
		Pause::flag = false;
		CastleFlag* Ptr = GetLevel()->CreateActor<CastleFlag>(1);
		Ptr->SetPosition(GetPosition() + float4{ 0, -50 });
	}
	if (true == EndCollision->CollisionCheck("PlayerItem", CollisionType::Rect, CollisionType::Rect)
		&& Pause::first)
	{
		Pause::first = false;
		Pause::end = true;
		GameEngineSound::SoundPlayOneShot("levelend.wav");
	}
}

void Castle::Render()
{
}

