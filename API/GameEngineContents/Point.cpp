#include "Point.h"

Point::Point() 
{
}

Point::~Point() 
{
}

void Point::Start()
{
	SetPosition({ 640, 600 });
	SetScale({ 1280, 200 });
}

void Point::Render()
{
	DebugRectRender();
}