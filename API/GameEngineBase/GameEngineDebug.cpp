#include "GameEngineDebug.h"


GameEngineDebug::GameEngineDebug() 
{
}

GameEngineDebug::~GameEngineDebug() 
{
}

void GameEngineDebug::LeakCheckOn()
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
}

//void GameEngineDebug::MsgBoxAssert(const std::string& _Text)
//{
//	//그냥 소리
//	MessageBeep(0);
//	//처음에 윈도우 핸들 넣어달라 하는대 안 넣어주면 알아서 하나 만들어줌.
//	MessageBoxA(nullptr, _Text.c_str(), "Error", MB_OK);
//	assert(false);
//
//}