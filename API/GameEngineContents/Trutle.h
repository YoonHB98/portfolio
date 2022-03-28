#pragma once

// Ό³Έν :
class Trutle
{
public:
	// constrcuter destructer
	Trutle();
	~Trutle();

	// delete Function
	Trutle(const Trutle& _Other) = delete;
	Trutle(Trutle&& _Other) noexcept = delete;
	Trutle& operator=(const Trutle& _Other) = delete;
	Trutle& operator=(Trutle&& _Other) noexcept = delete;

protected:

private:

};

