#include "Map1.h"
#include <GameEngineBase/GameEngineWindow.h>



Map1::Map1() 
{
}

Map1::~Map1() 
{
}

void Map1::Start()
{
	//SetPosition(float4(7301, 681));
	//CreateRenderer("11map.BMP");

	SetScale(GameEngineWindow::GetScale());

	Image_ = CreateRenderer();
}

void Map1::Render()
{
}

