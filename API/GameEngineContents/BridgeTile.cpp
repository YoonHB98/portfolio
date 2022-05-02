#include "BridgeTile.h"
#include <GameEngineBase/GameEngineSound.h>
#include <GameEngine/GameEngineLevel.h>
#include "Point100.h"
#include "Pause.h"
#include "WorldCount.h"
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineImageManager.h>



BridgeTile::BridgeTile() 
{
}

BridgeTile::~BridgeTile() 
{
}

void BridgeTile::Start()
{
	CheckCollision = CreateCollision("CheckPos", { 40, 2400 }, { -800, 20 });

}

void BridgeTile::Update()
{

	if ( Make)
	{
		
	    Bridge1 = GetLevel()->CreateActor<Bridge>();
		Bridge1->SetPosition(GetPosition() + float4{ 40, 0 });
		Bridge2 = GetLevel()->CreateActor<Bridge>();
		Bridge2->SetPosition(GetPosition() + float4{ 80, 0 });
		Bridge3 = GetLevel()->CreateActor<Bridge>();
		Bridge3->SetPosition(GetPosition() + float4{ 120, 0 });
		Bridge4 = GetLevel()->CreateActor<Bridge>();
		Bridge4->SetPosition(GetPosition() + float4{ 160, 0 });
		Bridge5 = GetLevel()->CreateActor<Bridge>();
		Bridge5->SetPosition(GetPosition() + float4{ 200, 0 });
		Bridge6 = GetLevel()->CreateActor<Bridge>();
		Bridge6->SetPosition(GetPosition() + float4{ 240, 0 });
		Bridge7 = GetLevel()->CreateActor<Bridge>();
		Bridge7->SetPosition(GetPosition() + float4{ 280, 0 });
		Bridge8 = GetLevel()->CreateActor<Bridge>();
		Bridge8->SetPosition(GetPosition() + float4{ 320, 0 });
		Bridge9 = GetLevel()->CreateActor<Bridge>();
		Bridge9->SetPosition(GetPosition() + float4{ 360, 0 });
		Bridge10 = GetLevel()->CreateActor<Bridge>();
		Bridge10->SetPosition(GetPosition() + float4{ 400, 0 });
		Bridge11 = GetLevel()->CreateActor<Bridge>();
		Bridge11->SetPosition(GetPosition() + float4{ 440, 0 });
		Bridge12 = GetLevel()->CreateActor<Bridge>();
		Bridge12->SetPosition(GetPosition() + float4{ 480, 0 });
		Bridge13 = GetLevel()->CreateActor<Bridge>();
		Bridge13->SetPosition(GetPosition() + float4{ 520, 0 });
		Make = false;
	}
	if (Pause::gameend)
	{
		Time_ = Time_ + GameEngineTime::GetDeltaTime();
		if (Time_ > 0.1f && A)
		{
			Bridge13->D_();
			A = false;
		}
		if (Time_ > 0.2f && B)
		{
			Bridge12->D_();
			B = false;
		}
		if (Time_ > 0.3f && C )
		{
			Bridge11->D_();
			C = false;
		}
		if (Time_ > 0.4f &&D)
		{
			Bridge10->D_();
			D = false;
		}
		if (Time_ > 0.5f && E)
		{
			Bridge9->D_();
			E = false;
		}
		if (Time_ > 0.6f && F)
		{
			Bridge8->D_();
			F = false;
		}
		if (Time_ > 0.7f && G)
		{
			Bridge7->D_();
			G = false;
		}
		if (Time_ > 0.8f && H)
		{
			Bridge6->D_();
			H = false;
		}
		if (Time_ > 0.9f && I)
		{
			Bridge5->D_();
			I = false;
		}
		if (Time_ > 1.0f && J)
		{
			Bridge4->D_();
			J= false;
		}
		if (Time_ > 1.1f &&K)
		{
			Bridge3->D_();
			K= false;
		}
		if (Time_ > 1.2f && L)
		{
			Bridge2->D_();
			L = false;
		}
		if (Time_ > 1.3f && M)
		{
			Bridge1->D_();
			M= false;
			Pause::KoopaDeath = true;
		}
	}
}

