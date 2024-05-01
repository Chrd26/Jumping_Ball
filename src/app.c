#include "app.h"

bool InitApp()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("%s", SDL_GetError());
		return false;
	}
	
	printf("SDL started\n");
	
	appWindow = SDL_CreateWindow(	"Jumping Ball", screenwidth, screenheight, 
																SDL_WINDOW_FULLSCREEN);
																				
	if (appWindow == NULL)
	{
		printf("Failed to create window %s", SDL_GetError());
		return false;
	}
	
	printf("SDL Window Created\n");
		
	appRenderer = SDL_CreateRenderer(	appWindow, NULL, 0);
	
	if (appRenderer == NULL)
	{
		printf("Failed to create rendenrer %s", SDL_GetError());
		return false;
	}
	
	printf("SDL Renderer Created\n");
	
	fontResource.location = "/Contents/Resources/fonts/Montserrat-VariableFont_wght.ttf";
	
	if (!TextComponentInit(&fontResource))
	{
		printf("Failed to initialise font module\n");
		return false;
	}
	
	printf("%s\n", fontResource.location);
	
	appFont = TTF_OpenFont(fontResource.location, 50);
	
	if (appFont == NULL)
	{
		printf("Failed to open font\n");
		return false;
	}
	
	printf("Text Component Started\n");
																										
	return true;									
}

void ExitApplication()
{
	SDL_DestroyRenderer(appRenderer);
	SDL_DestroyWindow(appWindow);		
	appWindow = NULL;
	appRenderer = NULL;																							
	SDL_Quit();
}
