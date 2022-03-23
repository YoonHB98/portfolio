#pragma once
#include <string>
#include <algorithm>


// ���� : string ���ڿ� ó��
class GameEngineString
{
public:
	static void ToUpper(std::string& _Text)
	{
		for (size_t i = 0; i < _Text.size(); i++)
		{
			_Text[i] = std::toupper(_Text[i]);
		}
		  //                             �������            �������          �̰Ÿ� ��������      �� �ٲ��
		  // �ϴ� �ȵǼ� for������
		//std::transform(_Text.begin(), _Text.end(), _Text.begin(), std::toupper);
	}

	static std::string ToUpperReturn(const std::string& _Text)
	{
		//const�ΰ� �ٲ܋�
		std::string NewText = _Text;
		for (size_t i = 0; i < _Text.size(); i++)
		{
			NewText[i] = std::toupper(NewText[i]);
		}
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

