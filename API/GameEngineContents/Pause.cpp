#include "Pause.h"


Pause::Pause() 
{
}

Pause::~Pause() 
{
}
bool Pause::first = true;
bool Pause::pause = false;
bool Pause::death = false;
bool Pause::end = false;
std::string Pause::PlayerStatus = "small";
float4 Pause::PlayerPosition = (float4{ 100, 480 });
bool Pause:: bigfirst = true;
bool Pause::smallfirst =false;
bool Pause::flowerfirst = false;
bool Pause::flower = false;
bool Pause::star = false;
bool Pause::endtime = false;
bool Pause::flag = false;
bool Pause::pipedown = false;
bool Pause::pipeleft = false;
bool Pause::CreateKeyFirst = true;
bool Pause::gameend = false;