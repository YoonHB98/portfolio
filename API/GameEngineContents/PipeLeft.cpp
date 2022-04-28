#include "PipeLeft.h"
#include "Stage1.h"
#include "Pause.h"

PipeLeft::PipeLeft() 
{
}

PipeLeft::~PipeLeft() 
{
}

void PipeLeft::Start()
{
	CreateRenderer("PipeLeft.bmp");
	PipeLeftCollision = CreateCollision("PipeLeft", { 80, 40}, { -10,0 });
}

void PipeLeft::Update()
{
	if (true == PipeLeftCollision->CollisionCheck("PlayerItem"))
	{
		Pause::pipeleft = true;
	}
}

