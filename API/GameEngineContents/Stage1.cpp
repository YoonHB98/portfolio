#include "Stage1.h"
#include "TopUI.h"
#include "Player.h"
#include "Map1.h"


Stage1::Stage1() 
{
}

Stage1::~Stage1() 
{
}

void Stage1::Loading()
{
	Player* Mario;
	Mario = CreateActor<Player>(2);
	Mario->SetPosition(float4{ 0, 500 });
	

}

void Stage1::Update()
{

}
void Stage1::LevelChangeStart()
{
	CreateActor<TopUI>(2);
/*	CreateActor<Player>(2)*/;
	CreateActor<Map1>(1);

}