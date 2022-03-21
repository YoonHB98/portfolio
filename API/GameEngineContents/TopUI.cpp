#include "TopUI.h"

TopUI::TopUI()
{
}

TopUI::~TopUI()
{
}


void TopUI::Start()
{
	SetPosition({ 680, 100 });
	SetScale({ 1360, 200 });
}

void TopUI::Render()
{
	DebugRectRender();
}