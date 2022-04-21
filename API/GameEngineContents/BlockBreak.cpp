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

	Time = 0;
}

void BlockBreak::Update()
{
	Actor->ChangeAnimation("Break");

}

