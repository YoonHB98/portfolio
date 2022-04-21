#include "BlockBreak.h"

BlockBreak::BlockBreak() 
{
}

BlockBreak::~BlockBreak() 
{
}

void BlockBreak::Start()
{
	Actor = CreateRenderer("BlockBreak.bmp");
	Actor->CreateAnimation("BlockBreak.bmp","Break" , 0, 3, 0.5f, true);

	Time = 0;
}

void BlockBreak::Update()
{
	int a = 0;
	if (a > 360)
	{
		a = 0;
	}
	if (a< 360)
	{
		a = a + 1;
	}
	Time = Time + GameEngineTime::GetDeltaTime();
	Actor->ChangeAnimation("Break");
	float4 AngleDir = { 100.0f, 0.0f };
	Angle += 180 * GameEngineTime::GetDeltaTime();
	if (Angle > 180)
	{
		Angle = 0;
	}
	float4 RotDir = float4::VectorRotationToDegreeZ(AngleDir, Angle);
	Actor->SetPivot(RotDir);

	//if (Time <= 0.15f)
	//{
	//	MoveDir = float4::UP;
	//	SetMove(MoveDir * GameEngineTime::GetDeltaTime() * 200.0f);
	//}else
	//if (Time <= 0.3f)
	//{
	//	MoveDir = (float4::UP * 0.6 )+ float4::RIGHT;
	//	SetMove(MoveDir * GameEngineTime::GetDeltaTime() * 200.0f);
	//}else
	//	if (Time <= 0.45f)
	//	{
	//		MoveDir = (float4::UP * 0.5) + float4::RIGHT;
	//		SetMove(MoveDir * GameEngineTime::GetDeltaTime() * 200.0f);
	//	}
	//	else
	//		if (Time <= 0.6f)
	//		{
	//			MoveDir = (float4::UP * 0.4) + float4::RIGHT;
	//			SetMove(MoveDir * GameEngineTime::GetDeltaTime() * 200.0f);
	//		}
	//		else
	//			if (Time <= 0.75f)
	//			{
	//				MoveDir = (float4::UP * 0.3) + float4::RIGHT;
	//				SetMove(MoveDir * GameEngineTime::GetDeltaTime() * 200.0f);
	//			}
	//			else
	//				if (Time <= 0.9f)
	//				{
	//					MoveDir = (float4::UP * 0.2) + float4::RIGHT;
	//					SetMove(MoveDir * GameEngineTime::GetDeltaTime() * 200.0f);
	//				}
	//				else
	//					if (Time <= 1.05f)
	//					{
	//						MoveDir = (float4::UP * 0.1) + float4::RIGHT;
	//						SetMove(MoveDir * GameEngineTime::GetDeltaTime() * 200.0f);
	//					}
	//					else
	//if (Time< 1.2f)
	//{
	//	MoveDir = float4::DOWN + (float4::RIGHT * 0.7);
	//	SetMove(MoveDir * GameEngineTime::GetDeltaTime() * 300.0f);
	//}else
	//	if (Time < 1.35f)
	//	{
	//		MoveDir = float4::DOWN + (float4::RIGHT * 0.6);
	//		SetMove(MoveDir * GameEngineTime::GetDeltaTime() * 300.0f);
	//	}
	//	else
	//		if (Time < 1.5f)
	//		{
	//			MoveDir = float4::DOWN + (float4::RIGHT * 0.5);
	//			SetMove(MoveDir * GameEngineTime::GetDeltaTime() * 300.0f);
	//		}
	//		else
	//if (Time < 1.65f)
	//{
	//	MoveDir = float4::DOWN + (float4::RIGHT * 0.4);
	//	SetMove(MoveDir * GameEngineTime::GetDeltaTime() * 300.0f);
	//}
	//else
	//	if (Time < 1.8f)
	//	{
	//		MoveDir = float4::DOWN + (float4::RIGHT * 0.3);
	//		SetMove(MoveDir * GameEngineTime::GetDeltaTime() * 300.0f);
	//	}
	//	else
	//		if (Time < 1.95f)
	//		{
	//			MoveDir = float4::DOWN + (float4::RIGHT * 0.2);
	//			SetMove(MoveDir * GameEngineTime::GetDeltaTime() * 300.0f);
	//		}
	//		else
	//			if (Time > 2.1f)
	//			{
	//				MoveDir = float4::DOWN + (float4::RIGHT * 0.1);
	//				SetMove(MoveDir * GameEngineTime::GetDeltaTime() * 300.0f);
	//			}
	
}

