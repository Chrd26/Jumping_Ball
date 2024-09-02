#include "app.h"

bool InitApp(struct Application *application)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("%s", SDL_GetError());
		return false;
	}
	
	application->appWindow = SDL_CreateWindow(	"Jumping Ball", 
												screenwidth, 
												screenheight, 
												SDL_WINDOW_FULLSCREEN|SDL_WINDOW_HIGH_PIXEL_DENSITY);
																				
	if (application->appWindow == NULL)
	{
		printf("Failed to create window %s", SDL_GetError());
		return false;
	}
	
	application->appRenderer = SDL_CreateRenderer(	application->appWindow, 
													NULL, 
													0);
	
	if (application->appRenderer == NULL)
	{
		printf("Failed to create rendenrer %s", SDL_GetError());
		return false;
	}

    char *temp = "/Contents/Resources/fonts/Montserrat-VariableFont_wght.ttf\0";

    for (int i = 0; i < strlen(temp); i++)
    {
        application->fontResource.location[i] = temp[i]; 
    }

    application->fontResource.location[strlen(temp)] = '\0';
	
	if (!TextComponentInit(&application->fontResource))
	{
		printf("Failed to initialise font module\n");
		return false;
    }

    char *fontLocCopy = calloc(	strlen(application->fontResource.location), 
								sizeof(char));
    strncpy(	fontLocCopy, 
				application->fontResource.location, 
				strlen(application->fontResource.location));
	
	application->appFont = TTF_OpenFont(application->fontResource.location, 50);
	TTF_SetFontStyle(application->appFont, TTF_STYLE_BOLD);
	
	application->textboxFont = TTF_OpenFont(fontLocCopy, 90);
	TTF_SetFontStyle(application->textboxFont, TTF_STYLE_BOLD);
	
	if (application->appFont == NULL || application->textboxFont == NULL)
	{
		printf("Failed to open font ");
		printf("%s\n", TTF_GetError());
		return false;
	}

	SDL_GetWindowSize(	application->appWindow, 
						&application->windowWidth, 
						&application->windowHeight);
						
	application->windowWidth *= 2;
	application->windowHeight *= 2;
	
	application->exteriorTextBox.x  = application->windowWidth * 0.18;
	application->exteriorTextBox.y = application->windowHeight * 0.16;
	application->exteriorTextBox.width = application->windowWidth/7;
	application->exteriorTextBox.height = application->windowHeight/10;			

	application->interiorTextBox.cursor = "I";
	application->interiorTextBox.keyboardPress = false;
	application->interiorTextBox.asciiSubstractionValue = 48;

	application->ball.radius = 160;
	application->ball.y = application->windowHeight - application->ball.radius;
	application->ball.x = application->windowWidth * 0.75;
	
	application->startButton.x = application->windowWidth * 0.22;
	application->startButton.y = application->windowHeight * 0.3;
	application->startButton.height = 0;
	application->startButton.width = 0;
    application->startButton.text = "Start";

	application->exitButton.x = application->windowWidth * 0.225;
	application->exitButton.y = application->windowHeight * 0.355;
	application->exitButton.height = 0;
	application->exitButton.width = 0;
    application->exitButton.text = "Exit";

    application->hasSimStarted = false;
    free(fontLocCopy);
																										
	return true;									
}

void ExitApplication(struct Application *application)
{
	SDL_DestroyRenderer(application->appRenderer);
	SDL_DestroyWindow(application->appWindow);
	TTF_CloseFont(application->appFont);
	TTF_CloseFont(application->textboxFont);
	TTF_Quit();		
	application->appWindow = NULL;
	application->appRenderer = NULL;			
	application->appFont = NULL;
	application->textboxFont = NULL;										
	SDL_Quit();
}
