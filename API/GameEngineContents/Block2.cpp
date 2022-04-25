#include "Block2.h"
#include "Pause.h"
#include "BlockBreak.h"
#include <GameEngineBase/GameEngineSound.h>


Block2::Block2() 
{
}

Block2::~Block2() 
{
}

void Block2::CreateBlock2(const float4& _Pivot)
{
	{
		float4 Pivot = _Pivot;
		float4 CoPivot = Pivot;
		CoPivot.y = Pivot.y + 36;
		
		SetPosition(Pivot);
	}
}

void Block2::Start()
{
	//Actor->SetPosition(Pivot);
	//Actor->CreateCollision("Block2", { 80, 10 }, CoPivot);
	Block2Collision = CreateCollision("Block", { 40, 1 }, { 0, 20 });

	CreateRenderer("Block.bmp");
	
	//
	/*Image_ = CreateRenderer();*/
}

void Block2::Update()
{

	if (true == Block2Collision->CollisionCheck("PlayerHitBox", CollisionType::Rect, CollisionType::Rect))
{
		GameEngineSound::SoundPlayOneShot("blockbreak.wav");
		BlockBreak* RightTop = GetLevel()->CreateActor<BlockBreak>();
		RightTop->SetPosition(GetPosition() + float4 { 20 , - 20});
		RightTop->Dir = (float4{ 150 , -200 });
		BlockBreak* LeftTop = GetLevel()->CreateActor<BlockBreak>();
		LeftTop->SetPosition(GetPosition() + float4{ -20 , -20 });
		LeftTop->Dir = (float4{ -150 , -200 });
		BlockBreak* RightBot = GetLevel()->CreateActor<BlockBreak>();
		RightBot->SetPosition(GetPosition() + float4{ 20 , 20 });
		RightBot->Dir  = (float4{ 150 , -40 });
		BlockBreak* LeftBot = GetLevel()->CreateActor<BlockBreak>();
		LeftBot->SetPosition(GetPosition() + float4{ -20 , 20 });
		LeftBot->Dir = float4{ -150 , -40 };
		Death();

}
}

void Block2::Render()
{
}

