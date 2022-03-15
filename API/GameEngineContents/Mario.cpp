#include "Mario.h"
#include "PlayLevel.h"
#include "TitleLevel.h"
#include  "EndingLevel.h"

Mario::Mario() 
{
}

Mario::~Mario() 
{
}

void Mario::GameInit()
{
	CreateLevel<TitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");
	CreateLevel<EndingLevel>("Ending");
	ChangeLevel("Title");
}
void Mario::GameLoop()
{

}
void Mario::GameEnd()
{

}

