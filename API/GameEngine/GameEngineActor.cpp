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

//포지션 스케일 지정해주고 호출하면 액터 크기를 알 수 있음
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
GameEngineRenderer* GameEngineActor::CreateRenderer(
	const std::string& _Image,
	RenderPivot _PivotType /*= RenderPivot::CENTER*/,
	const float4& _PivotPos /*= { 0,0 }*/
)
{
	return;
}