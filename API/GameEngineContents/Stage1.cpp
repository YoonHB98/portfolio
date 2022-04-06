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
		Actor->GetRenderer()->SetImage("11mapwhite.bmp");

		float4 BackActor = {};
		BackActor.x = (Actor->GetRenderer()->GetImage()->GetScale().Half().x) - (GameEngineWindow::GetScale().Half().x);
		BackActor.y = (Actor->GetRenderer()->GetImage()->GetScale().Half().y) - (GameEngineWindow::GetScale().Half().y);

		Actor->GetRenderer()->SetPivot(BackActor);
	}
	// ºí·Ï
	{
		Block* Actor = CreateActor<Block>(1);
		Actor->CreateBlock(float4{ 1320, 755 });
	}
	{
		Block* Actor = CreateActor<Block>(1);
		Actor->CreateBlock(float4{ 1640, 755 });
	}
	{
		Block* Actor = CreateActor<Block>(1);
		Actor->CreateBlock(float4{  1720, 755 } );
	}
	{
		Block* Actor = CreateActor<Block>(1);
		Actor->CreateBlock(float4{ 1800, 755 });
	}
	{
		Block* Actor = CreateActor<Block>(1);
		Actor->CreateBlock(float4{ 1880, 755 });
		{
			Block* Actor = CreateActor<Block>(1);
			Actor->CreateBlock(float4{ 1960, 755 });
		}
		{
			Block* Actor = CreateActor<Block>(1);
			Actor->CreateBlock(float4{ 1800, 435 });
		}
	}


}

void Stage1::Update()
{

}
void Stage1::LevelChangeStart()
{


}