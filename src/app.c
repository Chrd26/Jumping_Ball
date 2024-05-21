#include "app.h"

bool InitApp()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("%s", SDL_GetError());
		return false;
	}
	
	appWindow = SDL_CreateWindow("Jumping Ball", screenwidth, screenheight, SDL_WINDOW_FULLSCREEN);
																				
	if (appWindow == NULL)
	{
		printf("Failed to create window %s", SDL_GetError());
		return false;
	}
	
	printf("SDL Window Created\n");
		
	appRenderer = SDL_CreateRenderer(appWindow, NULL, 0);
	
	if (appRenderer == NULL)
	{
		printf("Failed to create rendenrer %s", SDL_GetError());
		return false;
	}
	
	fontResource.location = "/Contents/Resources/fonts/Montserrat-VariableFont_wght.ttf";
	miniApplication.location = FindResource("/Contents/Resources/modules/jumpcalculations");
    printf("Location: %s\n", miniApplication.location);
	
	if (!TextComponentInit(&fontResource))
	{
		printf("Failed to initialise font module\n");
		return false;
	}
	
	appFont = TTF_OpenFont(fontResource.location, 30);
	TTF_SetFontStyle(appFont, TTF_STYLE_BOLD);
	
	textboxFont = TTF_OpenFont(fontResource.location, 50);
	TTF_SetFontStyle(textboxFont, TTF_STYLE_BOLD);
	
	if (appFont == NULL || textboxFont == NULL)
	{
		printf("Failed to open font ");
		printf("%s\n", TTF_GetError());
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
	interiorTextBox.asciiSubstractionValue = 48;
	
	ball.radius = 80;
	ball.y = windowHeight - ball.radius;
	ball.x = windowWidth * 0.75;
	SDL_StopTextInput();
	
	startButton.x = windowWidth * 0.22;
	startButton.y = windowHeight * 0.3;
	startButton.height = 0;
	startButton.width = 0;
																										
	return true;									
}

void ExitApplication()
{
	SDL_DestroyRenderer(appRenderer);
	SDL_DestroyWindow(appWindow);
	TTF_CloseFont(appFont);
	TTF_CloseFont(textboxFont);
	TTF_Quit();		
	appWindow = NULL;
	appRenderer = NULL;			
	appFont = NULL;
	textboxFont = NULL;										
	SDL_Quit();
}
