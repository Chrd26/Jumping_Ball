#include "app.h"

bool InitApp()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("%s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	appWindow = SDL_CreateWindow(	"Jumping Ball", screenwidth,
																				screenheight, SDL_WINDOW_MAXIMIZED);
																				
	if (appWindow == NULL)
	{
		printF("Failed to create window %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	appRenderer = SDL_CreateRenderer(	appWindow, NULL, 0);
	
	if (appRenderer == NULL)
	{
		printf("Failed to create rendenrer %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
																										
										
}

void ExitApplication()
{
	SDL_DestroyRenderer(appRenderer);
	SDL_DestroyWindow(appWindow);		
	mainWindow = NULL;
	appRenderer = NULL;																							
	SDL_Quit();
}
