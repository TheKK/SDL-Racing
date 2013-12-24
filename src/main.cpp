/*
 *Author: KK <thumbd03803@gmail.com>
 *
 *main.cpp: nothing to talk about
 *
 */

#include <iostream>
#include <cstdio>
#include "game.h"

int
main ( int argc, char* argv[] )
{
	Game* game;
	game = new Game();

	game -> OnExecute();

	return 0;
}
