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
//	//�׳� �Ҹ�
//	MessageBeep(0);
//	//ó���� ������ �ڵ� �־�޶� �ϴ´� �� �־��ָ� �˾Ƽ� �ϳ� �������.
//	MessageBoxA(nullptr, _Text.c_str(), "Error", MB_OK);
//	assert(false);
//
//}