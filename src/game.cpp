/*
 *Author: KK <thumbd03803@gmail.com>
 *
 *game.cpp: basic game body 
 *
 */

#include "game.h"

Game::Game ()
{
	SCREEN_NAME = "Racing";
	SCREEN_WIDTH = ConfigLoader::Lua_GetGlobalInt( "width" );
	SCREEN_HEIGHT = 500;

	mainWindow = NULL;
	mainRenderer = NULL;
}

Game::~Game ()
{
	CleanUp();
}

bool
Game::Init ()
{	
	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
		return false;

	mainWindow = SDL_CreateWindow(
			SCREEN_NAME,
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			SCREEN_WIDTH, SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN
			);
	if( mainWindow == NULL ){
		fprintf( stderr, "SDL error: %s\n", SDL_GetError() );
		return false;
	}

	mainRenderer = SDL_CreateRenderer( mainWindow, -1, SDL_RENDERER_ACCELERATED );
	if( mainRenderer == NULL ){
		fprintf( stderr, "SDL error: %s\n", SDL_GetError() );
		return false;
	}

	SDL_SetRenderDrawColor( mainRenderer, 0x00, 0xFF, 0xFF, 0xFF );

	srand( time( NULL ) );

	return true;
}

void
Game::CleanUp ()
{
	SDL_DestroyWindow( mainWindow );
	mainWindow = NULL;

	SDL_DestroyRenderer( mainRenderer );
	mainRenderer = NULL;

	SDL_Quit();
}

void
Game::Update ()
{
}

void
Game::Render ()
{
}

int
Game::OnExecute ()
{
	if( Init() == false )
		return 1;
	else{
		bool isRunning = true;
		SDL_Event e;

		while( isRunning ){
			SDL_RenderClear( mainRenderer );
			SDL_RenderPresent( mainRenderer );
			
			while( SDL_PollEvent( &e ) ){
				if( e.type == SDL_KEYDOWN ){
					if( e.key.keysym.sym == SDLK_q )
						isRunning = false;

					if( e.key.keysym.sym == SDLK_d ){
						SDL_RenderClear( mainRenderer );
						SDL_Delay( 1000 );
					}
				}
			}	
		}
	}	
	return 0;
}
