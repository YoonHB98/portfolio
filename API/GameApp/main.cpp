#include <Windows.h>

#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineDebug.h>

int __stdcall WinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ char* lpCmdLine,
    _In_ int       nCmdShow)
{
    GameEngineDebug::LeakCheckOn();
   //두개의 윈도우를 띄울 필요가 없음
    GameEngineWindow::GetInst().CreateGameWindow(hInstance, "mario");
    GameEngineWindow::GetInst().ShowGameWindow();
    GameEngineWindow::GetInst().MessageLoop();

    GameEngineWindow::Destroy();
 
}