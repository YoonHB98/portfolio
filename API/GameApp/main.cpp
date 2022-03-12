#include <Windows.h>

#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineDebug.h>

void GameLoop()
{
   
   
    Rectangle(GameEngineWindow::GETDC(), 100, 100, 200, 200);
}

int __stdcall WinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ char* lpCmdLine,
    _In_ int       nCmdShow)
{
    GameEngineDebug::LeakCheckOn();
   //�ΰ��� �����츦 ��� �ʿ䰡 ����
    GameEngineWindow::GetInst().CreateGameWindow(hInstance, "mario");
    GameEngineWindow::GetInst().ShowGameWindow();
    GameEngineWindow::GetInst().MessageLoop(GameLoop);

    GameEngineWindow::Destroy();
 
}