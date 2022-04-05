#include "Stage1.h"
#include "TopUI.h"
#include "Player.h"
#include "Map1.h"
#include "Block.h"
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>
#include<GameEngine/GameEngineActor.h>
#include <GameEngineBase/GameEngineWindow.h>

Stage1::Stage1() 
{
}

Stage1::~Stage1() 
{
}

void Stage1::Loading()
{
	{
	Player* Mario;
	Mario = CreateActor<Player>(1);
	Mario->SetPosition(float4{ 200, 500 });
	}
	{
		TopUI* UI = CreateActor<TopUI>(1);
	}
	{
		Map1* Actor = CreateActor<Map1>(0);
		Actor->GetRenderer()->SetImage("11map.bmp");

		float4 BackActor = {};
		BackActor.x = (Actor->GetRenderer()->GetImage()->GetScale().Half().x) - (GameEngineWindow::GetScale().Half().x);
		BackActor.y = (Actor->GetRenderer()->GetImage()->GetScale().Half().y) - (GameEngineWindow::GetScale().Half().y);

		Actor->GetRenderer()->SetPivot(BackActor);

		//15800 245 640 600
		Actor->CreateCollision("Flag", { 100,1000 }, { 15160, 0 });
		Actor->CreateCollision("Block", { 200, 200 }, { 0, 200 });
		Actor->CreateCollision("Wall", { 200, 200 }, { 0, -200 });
		Actor->CreateCollision("Wall", { 200, 200 }, { 100, -200 });
	}
	// ºí·Ï
	{
		float4 Pivot = { 1317, 757 };
		float4 CoPivot = Pivot;
		CoPivot.y = Pivot.y + 36;
		Block* Actor = CreateActor<Block>(1);
		Actor->GetRenderer()->SetImage("block.bmp");
		Actor->GetRenderer()->SetPivot(Pivot);
		Actor->CreateCollision("Block", { 80, 10 }, CoPivot);
	}
	{
		float4 Pivot = { 1637, 757 };
		float4 CoPivot = Pivot;
		CoPivot.y = Pivot.y + 36;
		Block* Actor = CreateActor<Block>(1);
		Actor->GetRenderer()->SetImage("block.bmp");
		Actor->GetRenderer()->SetPivot(Pivot);
		Actor->CreateCollision("Block", { 80, 10 }, CoPivot);
	}
	{
		float4 Pivot = { 1717, 757 };
		float4 CoPivot = Pivot;
		CoPivot.y = Pivot.y + 36;
		Block* Actor = CreateActor<Block>(1);
		Actor->GetRenderer()->SetImage("block.bmp");
		Actor->GetRenderer()->SetPivot(Pivot);
		Actor->CreateCollision("Block", { 80, 10 }, CoPivot);
	}
	{
		float4 Pivot = { 1797, 757 };
		float4 CoPivot = Pivot;
		CoPivot.y = Pivot.y + 36;
		Block* Actor = CreateActor<Block>(1);
		Actor->GetRenderer()->SetImage("block.bmp");
		Actor->GetRenderer()->SetPivot(Pivot);
		Actor->CreateCollision("Block", { 80, 10 }, CoPivot);
	}
	{
		float4 Pivot = { 1877, 757 };
		float4 CoPivot = Pivot;
		CoPivot.y = Pivot.y + 36;
		Block* Actor = CreateActor<Block>(1);
		Actor->GetRenderer()->SetImage("block.bmp");
		Actor->GetRenderer()->SetPivot(Pivot);
		Actor->CreateCollision("Block", { 80, 10 }, CoPivot);
	}
	{
		float4 Pivot = { 1957, 757 };
		float4 CoPivot = Pivot;
		CoPivot.y = Pivot.y + 36;
		Block* Actor = CreateActor<Block>(1);
		Actor->GetRenderer()->SetImage("block.bmp");
		Actor->GetRenderer()->SetPivot(Pivot);
		Actor->CreateCollision("Block", { 80, 10 }, CoPivot);
	}
	{
		float4 Pivot = { 1797, 437 };
		float4 CoPivot = Pivot;
		CoPivot.y = Pivot.y + 36;
		Block* Actor = CreateActor<Block>(1);
		Actor->GetRenderer()->SetImage("block.bmp");
		Actor->GetRenderer()->SetPivot(Pivot);
		Actor->CreateCollision("Block", { 80, 10 }, CoPivot);
	}

}

void Stage1::Update()
{

}
void Stage1::LevelChangeStart()
{


}