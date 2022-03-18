#include "GameEngineActor.h"
#include "GameEngine/GameEngine.h"
#include <GameEngineBase/GameEngineWindow.h>

GameEngineActor::GameEngineActor()
	:Level_(nullptr)
{

}

GameEngineActor::~GameEngineActor() 
{
}

//������ ������ �������ְ� ȣ���ϸ� ���� ũ�⸦ �� �� ����
void GameEngineActor::DebugRectRender()
{
	GameEngineRect DebugRect(Position_, Scale_);


	Rectangle(
		GameEngine::BackBufferDC(),
		DebugRect.CenterLeft(),
		DebugRect.CenterTop(),
		DebugRect.CenterRight(),
		DebugRect.CenterBot()
		);
}