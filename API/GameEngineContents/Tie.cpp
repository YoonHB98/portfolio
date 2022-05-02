#include "Tie.h"
#include <GameEngineBase/GameEngineSound.h>
#include "Point100.h"
#include "Pause.h"
#include "WorldCount.h"




Tie::Tie() 
{
}

Tie::~Tie() 
{
}

void Tie::Start()
{
	Actor = CreateRenderer("Tie.bmp");
	Actor->SetIndex(0);
	TieCollision = CreateCollision("Tie", { 40, 40 }, { 0, 0 });
}

void Tie::Update()
{
	if (Pause::gameend)
	{
		Death();
	}

}

