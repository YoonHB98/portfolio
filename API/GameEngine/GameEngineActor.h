#pragma once
#include <GameEngineBase/GameEngineNameObject.h>
#include <GameEngineBase/GameEngineMath.h>
#include "GameEngineEnum.h"
#include <list>

// 설명 :
class GameEngineRenderer;
class GameEngineLevel;
class GameEngineActor : public GameEngineNameObject
{
public:
	friend GameEngineLevel;

	// constrcuter destructer
	GameEngineActor();
	virtual ~GameEngineActor();

	// delete Function
	GameEngineActor(const GameEngineActor& _Other) = delete;
	GameEngineActor(GameEngineActor&& _Other) noexcept = delete;
	GameEngineActor& operator=(const GameEngineActor& _Other) = delete;
	GameEngineActor& operator=(GameEngineActor&& _Other) noexcept = delete;

	inline float4 GetPosition()
	{
		return Position_;
	}
	inline float4 GetScale()
	{
		return Scale_;
	}

	inline void SetPosition(float4 _Value)
	{
		Position_ = _Value;
	}
	inline void SetScale(float4 _Value)
	{
		Scale_ = _Value;
	}


protected:
	// 시작할때 뭔가를 하고 싶은데 생성자에서는 절대로 못할 부분들을 처리한다.
	virtual void Start() = 0;
	// 지속적으로 게임이 실행될때 호출된다.
	virtual void Update() {}
	virtual void Render() {}

	void DebugRectRender();

private:
	GameEngineLevel* Level_;
	float4 Position_;
	float4 Scale_;

	// 나를 만들어준 레벨
	inline void SetLevel(GameEngineLevel* _Level)
	{
		Level_ = _Level;
	}

// // // // // // // // // // // // // // // // // // // // // // // // // // // // Render
public:

	// 디폴트 인자는 선언에서만 지정 가능
	GameEngineRenderer* CreateRenderer(const std::string& _Image, RenderPivot _PivotType = RenderPivot::TOP, const float4& _PivotPos = { 0,0 });

private:
	// 플레이어 하나에도 hp바 등등 내용이 많아지므로
	// 그걸 전담하는 클래스를 만들어서 세부적인 내용은 그걸로
	// 벡터로 하면 붙어서 new로 하면 어디 할당되는지 모름 따라서 벡터가 제일 효율이 좋긴함
	// 리스트에 힙으로 관리함 일단
	std::list<GameEngineRenderer*> RenderList_;
};





