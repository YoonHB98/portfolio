#include <Windows.h>

#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineContents/Mario.h>

Mario MyGame;

void GameInit()
{
    //�ؽ�ó �ε� �غ� ������Ʈ ���

    MyGame.GameInit();
}

void GameLoop()
{
   //����
    MyGame.GameLoop();
   
}

int __stdcall WinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ char* lpCmdLine,
    _In_ int       nCmdShow)
{
    GameEngineDebug::LeakCheckOn();
   //�ΰ��� �����츦 ��� �ʿ䰡 ����
    GameEngineWindow::GetInst().CreateGameWindow(hInstance, "Mario");
    GameEngineWindow::GetInst().ShowGameWindow();
    GameEngineWindow::GetInst().MessageLoop(GameInit, GameLoop);

    GameEngineWindow::Destroy();

    MyGame.GameEnd();
 
}