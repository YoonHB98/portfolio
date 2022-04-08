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
	void TimerReset();

protected:

private:
	float Time_;
	int SecondTime_;
	int FirstTime_ ;
	bool Start_;
	GameEngineRenderer* RenderRun;
	GameEngineRenderer* Three_;
	GameEngineRenderer* Two_;
	GameEngineRenderer* One_;
	void Start() override;
	void Update() override;
	void Render() override;
};

