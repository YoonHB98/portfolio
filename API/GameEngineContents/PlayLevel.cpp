#include "PlayLevel.h"
#include "Point.h"

enum class ORDER
{
	BACKGROUND,
	Point,
	MONSTER,
	UI
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
	CreateActor<Point>("PointUI", (int)ORDER::Point);

}