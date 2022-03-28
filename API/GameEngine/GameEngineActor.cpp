#include "GameEngineActor.h"
#include "GameEngine/GameEngine.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineRenderer.h>

GameEngineActor::GameEngineActor()
	:Level_(nullptr)
{

}

GameEngineActor::~GameEngineActor()
{
	//한번 받고 쓰는 이유 함수 호출스택 쌓기 싫어서
	std::list<GameEngineRenderer*>::iterator StartIter = RenderList_.begin();
	std::list<GameEngineRenderer*>::iterator EndIter = RenderList_.end();
	for (; StartIter != EndIter; ++StartIter)
	{
		if (nullptr == (*StartIter))
		{
			continue;
		}
		delete (*StartIter);
		(*StartIter) = nullptr;
	}
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

GameEngineRenderer* GameEngineActor::CreateRenderer(RenderPivot _PivotType /*= RenderPivot::CENTER*/, const float4& _PivotPos /*= { 0,0 }*/)
{
	GameEngineRenderer* NewRenderer = new GameEngineRenderer();

	NewRenderer->SetActor(this);
	// NewRenderer->SetImageScale();
	NewRenderer->SetPivot(_PivotPos);
	NewRenderer->SetType(_PivotType);

	RenderList_.push_back(NewRenderer);
	return NewRenderer;
}

GameEngineRenderer* GameEngineActor::CreateRenderer(
	const std::string& _Image,
	RenderPivot _PivotType /*= RenderPivot::CENTER*/,
	const float4& _PivotPos /*= { 0,0 }*/
)
{
	GameEngineRenderer* NewRenderer = new GameEngineRenderer();

	NewRenderer->SetActor(this);
	NewRenderer->SetImage(_Image);

	NewRenderer->SetPivot(_PivotPos);
	NewRenderer->SetType(_PivotType);

	RenderList_.push_back(NewRenderer);
	return NewRenderer;

}

void GameEngineActor::Renderering()
{
	StartRenderIter = RenderList_.begin();
	EndRenderIter = RenderList_.end();

	for (; StartRenderIter != EndRenderIter; ++StartRenderIter)
	{
		(*StartRenderIter)->Render();
	}
}

GameEngineRenderer* GameEngineActor::CreateRendererToScale(
	const std::string& _Image, const float4& _Scale,
	RenderPivot _PivotType /*= RenderPivot::CENTER*/, const float4& _PivotPos /*= { 0,0 }*/
)
{
	GameEngineRenderer* NewRenderer = new GameEngineRenderer();

	NewRenderer->SetActor(this);
	NewRenderer->SetImage(_Image);
	NewRenderer->SetScale(_Scale);
	NewRenderer->SetPivot(_PivotPos);
	NewRenderer->SetType(_PivotType);

	RenderList_.push_back(NewRenderer);
	return NewRenderer;
}