#pragma once
#include <crtdbg.h>
#include<string>
#include<assert.h>
#include <Windows.h>
// 설명 :
class GameEngineDebug
{
public:
	static void LeakCheckOn();
	//메모리 아낄 겸 수정하지 않을거라고 명시할려고 const & 로 했음
	//static void MsgBoxAssert(const std::string&);
protected:

private:
	// constrcuter destructer
	//내부를 그냥 객체 없이 쓸거라 private
	GameEngineDebug();
	~GameEngineDebug();

	// delete Function
	GameEngineDebug(const GameEngineDebug& _Other) = delete;
	GameEngineDebug(GameEngineDebug&& _Other) noexcept = delete;
	GameEngineDebug& operator=(const GameEngineDebug& _Other) = delete;
	GameEngineDebug& operator=(GameEngineDebug&& _Other) noexcept = delete;

};

#define MsgBoxAssert(Text) 	MessageBeep(0); \
MessageBoxA(nullptr, Text, "Error", MB_OK); \
assert(false); \

#define MsgBoxAssertString(Text) 	MessageBeep(0); \
MessageBoxA(nullptr, (Text).c_str(), "Error", MB_OK); \
assert(false); 


