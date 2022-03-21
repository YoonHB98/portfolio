#pragma once

// 설명 :
class GameEngineMath
{
private:
	// constrcuter destructer
	GameEngineMath();
	~GameEngineMath();

	// delete Function
	GameEngineMath(const GameEngineMath& _Other) = delete;
	GameEngineMath(GameEngineMath&& _Other) noexcept = delete;
	GameEngineMath& operator=(const GameEngineMath& _Other) = delete;
	GameEngineMath& operator=(GameEngineMath&& _Other) noexcept = delete;

protected:

private:

};

class float4
{
public:
	float x;
	float y;
	float z;
	float w;
	
public:
	bool IsZero2D()
	{
		return x == 0.0f && y == 0.0f;
	}

public:
	//const 하면 this 도 const -> 자신의 멤버변수가 변경되는 함수를 못씀
	int ix() const
	{
		//float 을 int로 형변환
		return static_cast<int>(x);
	}

	int iy()  const
	{
		return static_cast<int>(y);
	}

	int iz()  const
	{
		return static_cast<int>(z);
	}

	int iw()  const
	{
		return static_cast<int>(w);
	}
	//절반크기 친구들
	int hix()  const
	{
		
		return static_cast<int>(x * 0.5f);
	}

	int hiy()  const
	{
		return static_cast<int>(y * 0.5f);
	}

	int hiz() const
	{
		return static_cast<int>(z * 0.5f);
	}

	//반으로 반환
	float4 Half() const
	{
		return { x * 0.5f, y * 0.5f , z * 0.5f, 1.0f };
	}

public:
	float4()
		: x(0.0f), y(0.0f), z(0.0f), w(1.0f)
	{

	}
	float4(float _x, float _y)
		: x(_x), y(_y), z(0.0f), w(1.0f)
	{

	}
	float4(float _x, float _y, float _z)
		: x(_x), y(_y), z(_z), w(1.0f)
	{

	}
	float4(float _x, float _y, float _z, float _w)
		: x(_x), y(_y), z(_z), w(_w)
	{

	}
};

struct  GameEngineRect
{
public:
	float4 Pos;
	float4 Scale;

public:
	//점 중심으로 방향
	int CenterLeft()
	{
		return Pos.ix() - Scale.hix();
	}

	int CenterRight()
	{
		return Pos.ix() + Scale.hix();
	}

	int CenterTop()
	{
		return Pos.iy() - Scale.hiy();
	}

	int CenterBot()
	{
		return Pos.iy() + Scale.hiy();
	}

public:
	//포지션과 스케일 받고
	GameEngineRect(float4 _Pos, float4 _Scale)
		:Pos(_Pos)
		, Scale(_Scale)
	{

	}

};
