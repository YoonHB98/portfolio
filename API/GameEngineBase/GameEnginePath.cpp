#include "GameEnginePath.h"

GameEnginePath::GameEnginePath()
{
}

GameEnginePath::GameEnginePath(const std::filesystem::path& _Path)
	: Path_(_Path)
{

}

GameEnginePath::~GameEnginePath()
{
}

void GameEnginePath::SetCurrentPath()
{
	// 현재 폴더.
	Path_ = std::filesystem::current_path();
}

bool GameEnginePath::IsExits()
{
	//유효한 경로?
	return std::filesystem::exists(Path_);
}

std::string GameEnginePath::GetExtension()
{
	//확장자
	return Path_.extension().string();
}

std::string GameEnginePath::GetFileName()
{
	//파일 이름만
	return Path_.filename().string();
}

std::string GameEnginePath::GetFullPath()
{
	//경로
	return Path_.string();
}