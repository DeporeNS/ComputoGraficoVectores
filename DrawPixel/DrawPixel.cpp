#include "pch.h"
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <cmath>

//Screen dimension constants
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;
//Starts up SDL and creates window
bool init();


//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);


			}
		}
	}

	return success;
}
void close()
{
	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;


	SDL_Quit();
}


int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event e;

		//While application is running
		while (!quit)
		{
			//Handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{
				//User requests quit
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
			}

			//Clear screen
			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(gRenderer);


			//Draw vertical line of yellow dots
			for (int j = 0; j < SCREEN_WIDTH; j += 60)
			{
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x90, 0x90, 0xFF);
				for (int i = 0; i < SCREEN_HEIGHT; i += 1)
				{
					SDL_RenderDrawPoint(gRenderer, j, i);
				}
			}

			for (int j = 0; j < SCREEN_HEIGHT; j += 60)
			{
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x90, 0x90, 0xFF);
				for (int i = 0; i < SCREEN_WIDTH; i += 1)
				{
					SDL_RenderDrawPoint(gRenderer, i, j);
				}
			}

			SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
			for (int i = 0; i < SCREEN_HEIGHT; i += 1)
			{
				SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, i);
			}

			SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
			for (int i = 0; i < SCREEN_WIDTH; i += 1)
			{
				SDL_RenderDrawPoint(gRenderer, i, SCREEN_HEIGHT / 2);
			}

			//Update screen
			SDL_RenderPresent(gRenderer);
		}

	}

	//Free resources and close SDL
	close();

	return 0;
}
