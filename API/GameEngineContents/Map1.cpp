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
	SetPosition(GameEngineWindow::GetScale().Half()+float4(7462.5, 0));
	CreateRenderer("11MAP.BMP");
}

void Map1::Update()
{
}

