#include <Windows.h>

#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineContents/Mario.h>

Mario MyGame;

void GameInit()
{
    //텍스처 로딩 준비 오브젝트 등등

    MyGame.GameInit();
}

void GameLoop()
{
   //실행
    MyGame.GameLoop();
   
}

int __stdcall WinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ char* lpCmdLine,
    _In_ int       nCmdShow)
{
    GameEngineDebug::LeakCheckOn();
   //두개의 윈도우를 띄울 필요가 없음
    GameEngineWindow::GetInst().CreateGameWindow(hInstance, "Mario");
    GameEngineWindow::GetInst().ShowGameWindow();
    GameEngineWindow::GetInst().MessageLoop(GameInit, GameLoop);

    GameEngineWindow::Destroy();

    MyGame.GameEnd();
 
}