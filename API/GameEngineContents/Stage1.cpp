#include "Stage1.h"
#include "TopUI.h"
#include "Player.h"
#include "Map1.h"
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

		Actor->CreateCollision("Door", { 100, 100 }, { 0, 0 });

		Actor->CreateCollision("Wall", { 100, 100 }, { 0, -200 });
		// 가로길이의 반만큼

	}


}

void Stage1::Update()
{

}
void Stage1::LevelChangeStart()
{


}