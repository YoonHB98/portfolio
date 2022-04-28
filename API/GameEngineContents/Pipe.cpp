#include "Pipe.h"
#include "Stage1.h"
#include "Pause.h"

Pipe::Pipe() 
{
}

Pipe::~Pipe() 
{
}

void Pipe::Start()
{
	CreateRenderer("Pipe.bmp");
	PipeCollision = CreateCollision("Pipe", { 20, 80}, { 15,-20 });
}

void Pipe::Update()
{
	if (true == PipeCollision->CollisionCheck("PlayerBot")
		&&Pause::PlayerStatus == "small")
	{
		Pause::pipedown = true;
	}
}

