#include "app.h"

bool InitApp()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("%s", SDL_GetError());
		return false;
	}
	
	appWindow = SDL_CreateWindow("Jumping Ball", screenwidth, screenheight, SDL_WINDOW_FULLSCREEN|SDL_WINDOW_HIGH_PIXEL_DENSITY);
																				
	if (appWindow == NULL)
	{
		printf("Failed to create window %s", SDL_GetError());
		return false;
	}
	
	appRenderer = SDL_CreateRenderer(appWindow, NULL, 0);
	
	if (appRenderer == NULL)
	{
		printf("Failed to create rendenrer %s", SDL_GetError());
		return false;
	}

    char *temp = "/Contents/Resources/fonts/Montserrat-VariableFont_wght.ttf";

    for (int i = 0; i < strlen(temp); i++)
    {
        fontResource.location[i] = temp[i]; 
    }

    fontResource.location[strlen(temp)] = '\0';
	
	if (!TextComponentInit(&fontResource))
	{
		printf("Failed to initialise font module\n");
		return false;
    }

    char *fontLocCopy = calloc(strlen(fontResource.location), sizeof(char));
    strncpy(fontLocCopy, fontResource.location, strlen(fontResource.location));
	
	appFont = TTF_OpenFont(fontResource.location, 50);
	TTF_SetFontStyle(appFont, TTF_STYLE_BOLD);
	
	textboxFont = TTF_OpenFont(fontLocCopy, 90);
	TTF_SetFontStyle(textboxFont, TTF_STYLE_BOLD);
	
	if (appFont == NULL || textboxFont == NULL)
	{
		printf("Failed to open font ");
		printf("%s\n", TTF_GetError());
		return false;
	}

	SDL_GetWindowSize(appWindow, &windowWidth, &windowHeight);
	windowWidth *= 2;
	windowHeight *= 2;
	
	exteriorTextBox.x  = windowWidth * 0.18;
	exteriorTextBox.y = windowHeight * 0.16;
	exteriorTextBox.width = windowWidth/7;
	exteriorTextBox.height = windowHeight/10;			

	interiorTextBox.cursor = "I";
	interiorTextBox.keyboardPress = false;
	interiorTextBox.asciiSubstractionValue = 48;
    //interiorTextBox.content = calloc(4, sizeof(char));

	ball.radius = 160;
	ball.y = windowHeight - ball.radius;
	ball.x = windowWidth * 0.75;
	
	startButton.x = windowWidth * 0.22;
	startButton.y = windowHeight * 0.3;
	startButton.height = 0;
	startButton.width = 0;
    startButton.text = "Start";

	exitButton.x = windowWidth * 0.225;
	exitButton.y = windowHeight * 0.355;
	exitButton.height = 0;
	exitButton.width = 0;
    exitButton.text = "Exit";

    hasSimStarted = false;
    free(fontLocCopy);
																										
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
