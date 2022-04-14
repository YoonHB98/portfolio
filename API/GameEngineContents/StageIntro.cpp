#include "StageIntro.h"
#include "LevelIntro.h"
#include "Point.h"
#include "WorldCount.h"
#include "Pause.h"
#include "TopUI.h"

StageIntro::StageIntro() 
{
}

StageIntro::~StageIntro() 
{
}

void StageIntro::Loading()
{
	CreateActor<LevelIntro>(0);
	CreateActor<Coin>(1);
	CreateActor<Point>(1);
	WorldCount* UI = CreateActor<WorldCount>(2);

}

void StageIntro::Update()
{
	Pause::pause = false;
}

