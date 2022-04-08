#pragma once

// Ό³Έν :
class Name
{
public:
	// constrcuter destructer
	Name();
	~Name();

	// delete Function
	Name(const Name& _Other) = delete;
	Name(Name&& _Other) noexcept = delete;
	Name& operator=(const Name& _Other) = delete;
	Name& operator=(Name&& _Other) noexcept = delete;

protected:

private:

};

