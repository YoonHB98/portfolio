#include "BlockBreak.h"

BlockBreak::BlockBreak() 
{
}

BlockBreak::~BlockBreak() 
{
}

void BlockBreak::Start()
{
	Actor = CreateRenderer("BlockBreak.bmp");
	Actor->CreateAnimation("BlockBreak.bmp","Break" , 0, 3, 0.5f, true);
}

void BlockBreak::Update()
{
	Actor->ChangeAnimation("Break");

	Dir += float4::DOWN * GameEngineTime::GetDeltaTime() * 2000.0f;

	SetMove(Dir * GameEngineTime::GetDeltaTime());
}

