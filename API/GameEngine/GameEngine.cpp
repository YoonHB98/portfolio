#include "GameEngine.h"
#include <GameEngineBase/GameEngineWindow.h>
#include "GameEngineLevel.h"
#include "GameEngineImageManager.h"

std::map<std::string, GameEngineLevel*> GameEngine::AllLevel_;
//현재 레벨
GameEngineLevel* GameEngine::CurrentLevel_ = nullptr;
GameEngineLevel* GameEngine::NextLevel_ = nullptr;
//먼게임임
GameEngine* GameEngine::UserContents_ = nullptr;
// 그려지면 화면에 진짜 나오게 되는 이미지
GameEngineImage* GameEngine::WindowMainImage_ = nullptr; 
GameEngineImage* GameEngine::BackBufferImage_ = nullptr;

HDC GameEngine::BackBufferDC()
{
    return BackBufferImage_->ImageDC();
}

GameEngine::GameEngine()
{
}

GameEngine::~GameEngine()
{

}

void GameEngine::GameInit()
{

}

void GameEngine::GameLoop()
{

}

void GameEngine::GameEnd()
{

}




void GameEngine::WindowCreate()
{
    GameEngineWindow::GetInst().CreateGameWindow(nullptr, "GameWindow");
    GameEngineWindow::GetInst().ShowGameWindow();
    GameEngineWindow::GetInst().MessageLoop(EngineInit, EngineLoop);
}

void GameEngine::EngineInit()
{
    // 여기서 윈도우의 크기가 결정될것
    UserContents_->GameInit();

    // 백버퍼를 만들어 낸다.
    BackBufferImage_ = GameEngineImageManager::GetInst()->Create("BackBuffer", GameEngineWindow::GetScale());
}
void GameEngine::EngineLoop()
{
    // 엔진수준에서 매 프레임마다 체크하고 싶은거
    UserContents_->GameLoop();

    // t실행하는 도중 현재레벨이 바뀌지 않게
    if (nullptr != NextLevel_)
    {
        if (nullptr != CurrentLevel_)
        {
            CurrentLevel_->LevelChangeEnd();
        }

        CurrentLevel_ = NextLevel_;

        if (nullptr != CurrentLevel_)
        {
            CurrentLevel_->LevelChangeStart();
        }

        NextLevel_ = nullptr;
    }
    //돌릴 수 없으면
    if (nullptr == CurrentLevel_)
    {
        MsgBoxAssert("Level is nullptr => GameEngine Loop Error");
    }


    // 레벨수준 시간제한이 있는 게임이라면
    // 매 프레임마다 시간을 체크해야하는데 그런일을 게임 그자체의 루프
    CurrentLevel_->Update();
    CurrentLevel_->ActorUpdate();
    CurrentLevel_->ActorRender();

}

void GameEngine::EngineEnd()
{
    UserContents_->GameEnd();

    std::map<std::string, GameEngineLevel*>::iterator StartIter = AllLevel_.begin();
    std::map<std::string, GameEngineLevel*>::iterator EndIter = AllLevel_.end();

    for (; StartIter != EndIter; ++StartIter)
    {
        if (nullptr == StartIter->second)
        {
            continue;
        }
        delete StartIter->second;
    }
    GameEngineImageManager::Destroy();

    GameEngineWindow::Destroy();
}

void GameEngine::ChangeLevel(const std::string& _Name)
{
    std::map<std::string, GameEngineLevel*>::iterator FindIter = AllLevel_.find(_Name);

    //end인대 레벨을 바꿀려 하면
    if (AllLevel_.end() == FindIter)
    {
        MsgBoxAssert("Level Find Error");
        return;
    }
    NextLevel_ = FindIter->second;
}