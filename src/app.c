#include "app.h"

bool InitApp()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("%s", SDL_GetError());
		return false;
	}
	
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
	
	fontResource.location = "/Contents/Resources/fonts/Montserrat-VariableFont_wght.ttf";
	
	if (!TextComponentInit(&fontResource))
	{
		printf("Failed to initialise font module\n");
		return false;
	}
	
	appFont = TTF_OpenFont(fontResource.location, 30);
	TTF_SetFontStyle(appFont, TTF_STYLE_BOLD);
	
	if (appFont == NULL)
	{
		printf("Failed to open font\n");
		return false;
	}
	
	SDL_GetWindowSize(appWindow, &windowWidth, &windowHeight);
	
	exteriorTextBox.x  = windowWidth * 0.18;
	exteriorTextBox.y = windowHeight * 0.16;
	exteriorTextBox.width = windowWidth/7;
	exteriorTextBox.height = windowHeight/10;			
	
	interiorTextBox.cursor = "I";
	interiorTextBox.content = calloc(4, sizeof(char));
	interiorTextBox.keyboardPress = false;
																										
	return true;									
}

void ExitApplication()
{
	SDL_DestroyRenderer(appRenderer);
	SDL_DestroyWindow(appWindow);
	TTF_CloseFont(appFont);
	TTF_Quit();		
	appWindow = NULL;
	appRenderer = NULL;																							
	SDL_Quit();
}
