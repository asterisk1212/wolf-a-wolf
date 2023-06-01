#pragma once
#include <windows.h>
#pragma comment(lib,"winmm.lib")
#include<mmsystem.h>

void clilk()
{
	mciSendString("open ./music/click.mp3 alias clilk", NULL, 0, NULL);
	mciSendString("play clilk ", NULL, 0, NULL);
	//mciSendString("close clilk", 0, 0, 0);
}