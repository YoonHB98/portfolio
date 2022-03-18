#include "GameEngineImage.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineWindow.h>

GameEngineImage::GameEngineImage()
{
}

GameEngineImage::~GameEngineImage()
{
}



bool GameEngineImage::Create(float4 _Scale)
{
	if (true == _Scale.IsZero2D())
	{
		MsgBoxAssert("크기가 0인 이미지를 제작하려고 했습니다.");
		return false;
	}

	// 먼저 비트맵을 만들어
	// 이미지 크기만한
	BitMap_ = CreateCompatibleBitmap(GameEngineWindow::GetHDC(), _Scale.ix(), _Scale.iy());

	// 비어있지가 않아요
	ImageDC_ = CreateCompatibleDC(nullptr);

	if (nullptr == ImageDC_)
	{
		MsgBoxAssert("ImageDc 생성에 실패했습니다.");
	}

	OldBitMap_ = (HBITMAP)SelectObject(ImageDC_, BitMap_);

	ImageScaleCheck();

	return true;
}

void GameEngineImage::ImageScaleCheck()
{
	GetObject(BitMap_, sizeof(BITMAP), &Info_);
}

//class HBITMAP 
//{
//	float4 Size;
//	int* Pixels;
//};