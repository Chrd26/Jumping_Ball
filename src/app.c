#include "app.h"

bool InitApp()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("%s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	 int createWindow = SDL_CreateWindowAndRenderer(	"Jumping Ball", screenwidth,
																										screenheight, SDL_WINDOW_MAXIMIZED,
																										appRenderer);
																										
	SDL_DestroyRenderer(appRenderer);
	SDL_DestroyWindow(mainWindow);		
	mainWindow = NULL;
	appRenderer = NULL;		
																						
	SDL_Quit();
										
}
