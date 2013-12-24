/*
 *Author: KK <thumbd03803@gmail.com>
 *
 *game.h
 *
 */
#ifndef GAME
#define GAME

#include <iostream>
#include <cstdio>
#include <SDL2/SDL.h>
#include "configLoader.h"

class Game
{
	public:
		Game();
		~Game();
		bool Init ();
		void CleanUp ();
		void Update ();
		void Render ();
		int OnExecute ();

	private:
		SDL_Window* mainWindow;
		SDL_Renderer* mainRenderer;
		char* SCREEN_NAME;
		int SCREEN_WIDTH;
		int SCREEN_HEIGHT;
};
#endif








