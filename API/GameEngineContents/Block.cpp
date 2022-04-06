#include "Block.h"
#include <GameEngine/GameEngineLevel.h>
#include <GameEngine/GameEngineActor.h>

Block::Block() 
{
}

Block::~Block() 
{
}

void Block::CreateBlock(const float4& _Pivot)
{
	{
		float4 Pivot = _Pivot;
		float4 CoPivot = Pivot;
		CoPivot.y = Pivot.y + 36;
		
		SetPosition(Pivot);
		CreateCollision("Block", { 80, 10 }, CoPivot);
	}
}

void Block::Start()
{
	//Actor->SetPosition(Pivot);
	//Actor->CreateCollision("Block", { 80, 10 }, CoPivot);
	BlockCollision = CreateCollision("Block", { 80, 20 }, { 0, 40 });

	CreateRenderer("Block.bmp");
	//
	/*Image_ = CreateRenderer();*/
}

void Block::Update()
{
	if (true == BlockCollision->CollisionCheck("PlayerHitBox", CollisionType::Rect, CollisionType::Rect))
{
		SetMove(float4::UP * GameEngineTime::GetDeltaTime() * 200.0f);
}
}

