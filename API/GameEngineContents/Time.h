#pragma once

// Ό³Έν :
class Time
{
public:
	// constrcuter destructer
	Time();
	~Time();

	// delete Function
	Time(const Time& _Other) = delete;
	Time(Time&& _Other) noexcept = delete;
	Time& operator=(const Time& _Other) = delete;
	Time& operator=(Time&& _Other) noexcept = delete;

protected:

private:

};

