#pragma once
#include <Windows.h>
#include <string>

// Ό³Έν :
class GameEngineWindow
{
private:
	static GameEngineWindow* Inst_;

public:
	inline static GameEngineWindow& GetInst()
	{
		return *Inst_;
	}

	static void Destroy()
	{
		if (nullptr != Inst_)
		{
			delete Inst_;
			Inst_ = nullptr;
		}
	}

public:
	void RegClass(HINSTANCE _hInst);
	void CreateGameWindow(HINSTANCE _hInst, const std::string& _Title);
	void ShowGameWindow();
	void MessageLoop();
	void off();
	
	inline HDC GETDC() const
	{
		return HDC_;
	}
protected:

private:
	bool  WindowOn_;

	HINSTANCE hInst_;
	HWND hWnd_;
	std::string Title_;

	HDC HDC_;

	// constrcuter destructer
	GameEngineWindow();
	~GameEngineWindow();

	// delete Function
	GameEngineWindow(const GameEngineWindow& _Other) = delete;
	GameEngineWindow(GameEngineWindow&& _Other) noexcept = delete;
	GameEngineWindow& operator=(const GameEngineWindow& _Other) = delete;
	GameEngineWindow& operator=(GameEngineWindow&& _Other) noexcept = delete;

};

