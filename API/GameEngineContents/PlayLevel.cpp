#include "PlayLevel.h"
#include "TopUI.h"

enum class ORDER
{
	BACKGROUND,
	TopUI,

};

PlayLevel::PlayLevel()
{
}

PlayLevel::~PlayLevel()
{
}

void PlayLevel::Loading()
{

}

void PlayLevel::Update()
{

}
void PlayLevel::LevelChangeStart()
{
	CreateActor<TopUI>("TopUII", (int)ORDER::TopUI);
	

}