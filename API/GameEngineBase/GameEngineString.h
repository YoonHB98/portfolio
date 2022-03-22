#pragma once
#include <string>
#include <algorithm>


// 설명 : string 문자열 처리
class GameEngineString
{
public:
	static void ToUpper(std::string& _Text)
	{
		  //                             여기부터            여기까지          이거를 시작으로      다 바꿔라
		std::transform(_Text.begin(), _Text.end(), _Text.begin(), std::toupper);
	}

	static std::string ToUpperReturn(const std::string& _Text)
	{
		//const인거 바꿀떄
		std::string NewText = _Text;
		std::transform(NewText.begin(), NewText.end(), NewText.begin(), std::toupper);
		return NewText;
	}

protected:

private:
	// constrcuter destructer
	GameEngineString();
	~GameEngineString();

	// delete Function
	GameEngineString(const GameEngineString& _Other) = delete;
	GameEngineString(GameEngineString&& _Other) noexcept = delete;
	GameEngineString& operator=(const GameEngineString& _Other) = delete;
	GameEngineString& operator=(GameEngineString&& _Other) noexcept = delete;


};

