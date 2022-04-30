#include "Fire.h"
#include <GameEngineBase/GameEngineSound.h>
#include "Point100.h"
#include "Pause.h"
#include "WorldCount.h"



Fire::Fire() 
	:Speed_(60.0f)
{
}

Fire::~Fire() 
{
}

void Fire::CreateFire(const float4& _Pivot, const float4 &_Angle)
{
	{
		CreateAngleDir = _Angle;
		float4 Pivot = _Pivot;
		SetPosition(Pivot);
		
		Actor = CreateRenderer("Bullet.bmp");
		Actor->SetIndex(0);
		Actor->CreateAnimation("Bullet.bmp", "Fire", 0,2, 0.2f, true);
		Actor->ChangeAnimation("Fire");


	}
}

void Fire::Start()
{
	FireCollision = CreateCollision("MonsterRight", { 20, 20 }, { 0, 0 });

}

void Fire::Update()
{
	AngleDir = CreateAngleDir;
	Angle += 180 * GameEngineTime::GetDeltaTime();
	float4 RotDir = float4::VectorRotationToDegreeZ(AngleDir, Angle);
	Actor->SetPivot(RotDir);
	FireCollision->SetPivot(RotDir);
	AngleDir = float4::DegreeToDirectionFloat4(Angle);

	AngleDir *= 100.0f;
}

