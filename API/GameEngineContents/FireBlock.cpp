#include "FireBlock.h"
#include <GameEngineBase/GameEngineSound.h>
#include <GameEngine/GameEngineLevel.h>
#include "Point100.h"
#include "Pause.h"
#include "WorldCount.h"
#include "Fire.h"
#include <GameEngine/GameEngineImageManager.h>



FireBlock::FireBlock() 
{
}

FireBlock::~FireBlock() 
{
}

void FireBlock::Start()
{
	CheckCollision = CreateCollision("CheckPos", { 40, 2400 }, { -800, 20 });

}

void FireBlock::Update()
{

	if (true == CheckCollision->CollisionCheck("PlayerHitBox", CollisionType::Rect, CollisionType::Rect)
		&& Make)
	{
		Fire* Fire6 = GetLevel()->CreateActor<Fire>();
		Fire6->CreateFire(GetPosition(), { 0, 0 });
		Fire* Fire1 = GetLevel()->CreateActor<Fire>();
		Fire1->CreateFire(GetPosition(), {20, 0});
		Fire* Fire2 = GetLevel()->CreateActor<Fire>();
		Fire2->CreateFire(GetPosition(), { 40, 0 });
		Fire* Fire3 = GetLevel()->CreateActor<Fire>();
		Fire3->CreateFire(GetPosition(), { 60, 0 });
		Fire* Fire4 = GetLevel()->CreateActor<Fire>();
		Fire4->CreateFire(GetPosition(), { 80, 0 });
		Fire* Fire5 = GetLevel()->CreateActor<Fire>();
		Fire5->CreateFire(GetPosition(), { 100, 0 });

		Make = false;
	}
}

