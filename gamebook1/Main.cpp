// Copyright (c) 2018 Weyr Software
#include "Game.h"

void main(int p_Argc, void** p_Argv[]) 
{
	//
	Game snakegame; 
	//
	while (!snakegame.viGetWindow()->viIsDone())
	{
		//
		snakegame.viHandleInput();
		snakegame.viUpdate();
		snakegame.viRender();
		snakegame.viRestartClock();
	}
}