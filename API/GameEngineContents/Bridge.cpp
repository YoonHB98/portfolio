#include "Bridge.h"
#include <GameEngineBase/GameEngineSound.h>
#include "Point100.h"
#include "Pause.h"
#include "WorldCount.h"




Bridge::Bridge() 
{
}

Bridge::~Bridge() 
{
}

void Bridge::D_()
{
	GameEngineSound::SoundPlayOneShot("bridgebreak.wav");
	Death();
}

void Bridge::Start()
{
	Actor = CreateRenderer("Bridge.bmp");
	Actor->SetIndex(0);
	BridgeCollision = CreateCollision("Bridge", { 40, 40 }, { 0, 0 });
}

void Bridge::Update()
{
	

}

