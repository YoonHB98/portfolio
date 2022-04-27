#include "Map1Under.h"
#include <GameEngineBase/GameEngineWindow.h>



Map1Under::Map1Under() 
{
}

Map1Under::~Map1Under() 
{
}

void Map1Under::Start()
{
	//SetPosition(float4(7301, 681));
	//CreateRenderer("11map.BMP");

	SetScale(GameEngineWindow::GetScale());

	Image_ = CreateRenderer();
}

void Map1Under::Render()
{
}

