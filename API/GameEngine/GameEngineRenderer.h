#pragma once
#include "GameEngineActorSubObject.h"
#include "GameEngineEnum.h"


//액터가 먼저냐 랜더가 먼저냐 처럼 상하가 확실하면 쓰는대 아니면 순환참조 위험성
//그냥 include안하고 전방선언만
class GameEngineImage;
// 설명 :  그려주는 친구
class GameEngineRenderer : public GameEngineActorSubObject
{
	friend GameEngineActor;

public:
	// constrcuter destructer
	GameEngineRenderer();
	~GameEngineRenderer();

	// delete Function
	GameEngineRenderer(const GameEngineRenderer& _Other) = delete;
	GameEngineRenderer(GameEngineRenderer&& _Other) noexcept = delete;
	GameEngineRenderer& operator=(const GameEngineRenderer& _Other) = delete;
	GameEngineRenderer& operator=(GameEngineRenderer&& _Other) noexcept = delete;


	inline void SetTransColor(unsigned int _Color)
	{
		TransColor_ = _Color;
	}


	inline void SetPivot(const float4& _Pos)
	{
		RenderPivot_ = _Pos;
	}

	inline void SetType(const RenderPivot& _Type)
	{
		PivotType_ = _Type;
	}

	inline void SetScaleMode(const RenderScaleMode& _Mode)
	{
		ScaleMode_ = _Mode;
	}

	void SetImageScale();

	inline void SetScale(const float4& _Scale)
	{
		ScaleMode_ = RenderScaleMode::User;
		RenderScale_ = _Scale;
	}



	void SetImage(const std::string& _Name);

protected:
	void Render();

private:
	GameEngineImage* Image_; //이미지
	RenderPivot PivotType_; // 센터 bot
	RenderScaleMode ScaleMode_;
	float4 RenderPivot_;
	float4 RenderScale_;
	unsigned int TransColor_;

};

