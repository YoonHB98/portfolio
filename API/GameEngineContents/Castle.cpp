#include "Castle.h"
#include "Pause.h"


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
	EndCollision = CreateCollision("Castle", { 80, 1200 }, { 40, 600 });

	CreateRenderer("Castle.bmp");

}

void Castle::Update()
{
	if (true == EndCollision->CollisionCheck("PlayerHitBox", CollisionType::Rect, CollisionType::Rect))
	{
		
	}
}

void Castle::Render()
{
}

