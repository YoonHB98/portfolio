#pragma once

// Ό³Έν :
class Three
{
public:
	// constrcuter destructer
	Three();
	~Three();

	// delete Function
	Three(const Three& _Other) = delete;
	Three(Three&& _Other) noexcept = delete;
	Three& operator=(const Three& _Other) = delete;
	Three& operator=(Three&& _Other) noexcept = delete;

protected:

private:

};

