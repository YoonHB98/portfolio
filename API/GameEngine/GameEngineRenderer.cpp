﻿#include "GameEngineRenderer.h"
#include "GameEngineImageManager.h"
#include "GameEngine.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineTime.h>



#pragma comment(lib, "msimg32.lib")

GameEngineRenderer::GameEngineRenderer()
	: Image_(nullptr)
	, PivotType_(RenderPivot::CENTER)
	, ScaleMode_(RenderScaleMode::Image)
	, TransColor_(RGB(255, 0, 255))
	, RenderImagePivot_({ 0,0 })
{
}

GameEngineRenderer::~GameEngineRenderer()
{
}

void GameEngineRenderer::SetImageScale()
{
	if (nullptr == Image_)
	{
		MsgBoxAssert("존재하지 않는 이미지로 크기를 조절하려고 했습니다.");
		return;
	}

	ScaleMode_ = RenderScaleMode::Image;
	RenderScale_ = Image_->GetScale();
	RenderImageScale_ = Image_->GetScale();
}


void GameEngineRenderer::SetImage(const std::string& _Name)
{
	GameEngineImage* FindImage = GameEngineImageManager::GetInst()->Find(_Name);
	if (nullptr == FindImage)
	{
		MsgBoxAssertString(_Name + "존재하지 않는 이미지를 랜더러에 세팅하려고 했습니다.");
		return;
	}

	Image_ = FindImage;
	SetImageScale();
}

void GameEngineRenderer::Render()
{
	if (nullptr != CurrentAnimation_)
	{
		CurrentAnimation_->Update();
	}

	if (nullptr == Image_)
	{
		MsgBoxAssert("랜더러에 이미지가 세팅되어 있지 않으면 랜더링이 안됩니다.");
		return;
	}

	float4 RenderPos = GetActor()->GetPosition() + RenderPivot_;

	switch (PivotType_)
	{
	case RenderPivot::CENTER:
		GameEngine::BackBufferImage()->TransCopy(Image_, RenderPos - RenderScale_.Half(), RenderScale_, RenderImagePivot_, RenderImageScale_, TransColor_);
		break;
	case RenderPivot::BOT:
		// GameEngine::BackBufferImage()->TransCopyCenterScale(Image_, RenderPos, RenderScale, TransColor_);
		break;
	default:
		break;
	}
}

void GameEngineRenderer::SetIndex(size_t _Index)
{
	if (false == Image_->IsCut())
	{
		MsgBoxAssert("이미지를 부분적으로 사용할수 있게 잘려지있지 않은 이미지 입니다.");
		return;
	}

	RenderImagePivot_ = Image_->GetCutPivot(_Index);
	RenderScale_ = Image_->GetCutScale(_Index);
	RenderImageScale_ = Image_->GetCutScale(_Index);
}

/////////////////////////////////////// 애니메이션


void GameEngineRenderer::ChangeAnimation(const std::string& _Name)
{
	std::map<std::string, FrameAnimation>::iterator FindIter = Animations_.find(_Name);

	if (Animations_.end() == FindIter)
	{
		MsgBoxAssert("존재하지 않는 애니메이션으로 체인지 하려고 했습니다.");
		return;
	}

	CurrentAnimation_ = &FindIter->second;
}

void GameEngineRenderer::CreateAnimation(
	const std::string& _Image,
	const std::string& _Name,
	int _StartIndex,
	int _EndIndex,
	float _InterTime,
	bool _Loop /*= true*/)
{
	GameEngineImage* FindImage = GameEngineImageManager::GetInst()->Find(_Image);

	if (nullptr == FindImage)
	{
		MsgBoxAssert("존재하지 않는 이미지로 애니메이션을 만들려고 했습니다.");
		return;
	}

	if (Animations_.end() != Animations_.find(_Name))
	{
		MsgBoxAssert("이미 존재하는 애니메이션을 또 만들려고 했습니다..");
		return;
	}

	//FrameAnimation Animation;
	//Animation.insert(std::make_pair(, FrameAnimation()));
	FrameAnimation& NewAnimation = Animations_[_Name];
	NewAnimation.Renderer_ = this;
	NewAnimation.Image_ = FindImage;
	NewAnimation.CurrentFrame_ = _StartIndex;
	NewAnimation.StartFrame_ = _StartIndex;
	NewAnimation.EndFrame_ = _EndIndex;
	NewAnimation.CurrentInterTime_ = _InterTime;
	NewAnimation.InterTime_ = _InterTime;
	NewAnimation.Loop_ = _Loop;


}

void GameEngineRenderer::FrameAnimation::Update()
{
	CurrentInterTime_ -= GameEngineTime::GetInst()->GetDeltaTime();
	if (0 >= CurrentInterTime_)
	{
		CurrentInterTime_ = InterTime_;
		++CurrentFrame_;

		if (EndFrame_ < CurrentFrame_)
		{
			if (true == Loop_)
			{
				CurrentFrame_ = StartFrame_;
			}
			else
			{
				CurrentFrame_ = EndFrame_;
			}
		}
	}


	Renderer_->Image_ = Image_;
	Renderer_->SetIndex(CurrentFrame_);
}