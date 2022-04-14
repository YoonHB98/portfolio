#pragma once

// Ό³Έν :
class Pause
{
public:
	// constrcuter destructer
	Pause();
	~Pause();

	// delete Function
	Pause(const Pause& _Other) = delete;
	Pause(Pause&& _Other) noexcept = delete;
	Pause& operator=(const Pause& _Other) = delete;
	Pause& operator=(Pause&& _Other) noexcept = delete;
	static bool pause;
protected:

private:

};

