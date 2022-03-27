#include "PlayLevel.h"
#include "TopUI.h"
#include "Player.h"

enum class ORDER
{
	BACKGROUND,
	TopUI,
	Mario
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
	CreateActor<TopUI>((int)ORDER::TopUI);
	CreateActor<Player>((int)ORDER::Mario);

}