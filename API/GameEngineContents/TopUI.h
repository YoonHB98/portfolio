#pragma once
#include <GameEngine/GameEngineActor.h>
// Ό³Έν :
class TopUI : public GameEngineActor
{
public:
	// constrcuter destructer
	TopUI();
	~TopUI();

	// delete Function
	TopUI(const TopUI& _Other) = delete;
	TopUI(TopUI&& _Other) noexcept = delete;
	TopUI& operator=(const TopUI& _Other) = delete;
	TopUI& operator=(TopUI&& _Other) noexcept = delete;

protected:

private:
	float Time_ = 400;
	int SecondTime_ = 100;
	int FirstTime_ = 10;
	bool Start_ = true;
	GameEngineRenderer* RenderRun;
	GameEngineRenderer* Three_;
	GameEngineRenderer* Two_;
	GameEngineRenderer* One_;
	void Start() override;
	void Update() override;
	void Render() override;
};

