#include "Axe.h"
#include <GameEngineBase/GameEngineSound.h>
#include "Point100.h"
#include "Pause.h"
#include "WorldCount.h"




Axe::Axe() 
{
}

Axe::~Axe() 
{
}

void Axe::Start()
{
	Actor = CreateRenderer("Axe.bmp");
	Actor->SetIndex(0);
	AxeCollision = CreateCollision("Axe", { 40, 40 }, { 0, 0 });
}

void Axe::Update()
{
	if (true == AxeCollision->CollisionCheck("PlayerBot", CollisionType::Rect, CollisionType::Rect)
		|| true == AxeCollision->CollisionCheck("PlayerItem", CollisionType::Rect, CollisionType::Rect))
	{
		Pause::gameend = true;
		Death();
	}

}

