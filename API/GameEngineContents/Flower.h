#pragma once

// Ό³Έν :
class Flower
{
public:
	// constrcuter destructer
	Flower();
	~Flower();

	// delete Function
	Flower(const Flower& _Other) = delete;
	Flower(Flower&& _Other) noexcept = delete;
	Flower& operator=(const Flower& _Other) = delete;
	Flower& operator=(Flower&& _Other) noexcept = delete;

protected:

private:

};

