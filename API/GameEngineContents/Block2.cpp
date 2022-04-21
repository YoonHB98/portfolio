#include "Block.h"
#include "Pause.h"
#include "BlockBreak.h"


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
	}
}

void Block::Start()
{
	//Actor->SetPosition(Pivot);
	//Actor->CreateCollision("Block", { 80, 10 }, CoPivot);
	BlockCollision = CreateCollision("Block", { 40, 1 }, { 0, 20 });

	CreateRenderer("Block.bmp");
	
	//
	/*Image_ = CreateRenderer();*/
}

void Block::Update()
{

	if (true == BlockCollision->CollisionCheck("PlayerHitBox", CollisionType::Rect, CollisionType::Rect))
{
		BlockBreak* RightTop = GetLevel()->CreateActor<BlockBreak>();
		RightTop->SetPosition(GetPosition() + float4 { 20 , - 20});
		BlockBreak* LeftTop = GetLevel()->CreateActor<BlockBreak>();
		LeftTop->SetPosition(GetPosition() + float4{ -20 , -20 });
		BlockBreak* RightBot = GetLevel()->CreateActor<BlockBreak>();
		RightBot->SetPosition(GetPosition() + float4{ 20 , 20 });
		BlockBreak* LeftBot = GetLevel()->CreateActor<BlockBreak>();
		LeftBot->SetPosition(GetPosition() + float4{ -20 , 20 });
		Death();

}
}

void Block::Render()
{
}

