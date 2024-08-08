#include "text.h"

bool TextComponentInit(Resource *resource)
{
	int getValue = TTF_Init();
	
	if (getValue != 0)
	{
		printf("Failed to load TTF, %s", TTF_GetError());
		return false;
	}

	char *execPath;
	int pathSize = 2048;
	getExecutablePath(&execPath, &pathSize);
	printf(" Path to executable: %s\n", execPath);

	char* ptr = strstr(execPath, "Jumping_Ball_VS.exe");
	int getLength = strlen(execPath);
	int getptrLength = strlen(ptr);
	printf("Substring Position: %s\n", ptr);

	char temp[1024];
	for (int i = 0; i < getLength - getptrLength; i++)
	{
		//printf("%c", execPath[i]);
		temp[i] = execPath[i];
	}

	temp[getLength - getptrLength] = '\0';

	char fontLocation[256] = "Resources\\Fonts\\Montserrat-VariableFont_wght.ttf\0";
	int getTempLength = strlen(temp);
	printf("%d\n", getTempLength);
	int getResourceLocationLength = strlen(fontLocation);
	
	for (int i = getTempLength; i < getResourceLocationLength + getTempLength; i++)
	{
		temp[i] = fontLocation[i - getTempLength];
	}

	temp[getResourceLocationLength + getTempLength] = '\0';
	getTempLength = strlen(temp);

	for (int i = 0; i < getTempLength; i++)
	{
		resource->location[i] = temp[i];
	}

	printf("Result: %s\n", resource->location);
	
	return true;
}

void DisplayText(SDL_Renderer * renderer, TTF_Font *font, char* content, int x, int y)
{
	SDL_Color textColor = {0xff, 0xff, 0xff};
	SDL_Surface *textSurface = TTF_RenderText_Solid(font, content, textColor);
	
	if (textSurface == NULL)
	{
		printf("Failed to create surface: %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	
	if (textTexture == NULL)
	{
		printf("Failed to create texture: %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	float width = textSurface->w;
	float height = textSurface->h;
	
	const SDL_FRect textHolder = {x, y, width, height};
	SDL_RenderTexture(renderer, textTexture, NULL, &textHolder);
	
	SDL_DestroySurface(textSurface);
	textSurface = NULL;
	
	SDL_DestroyTexture(textTexture);
	textTexture = NULL;
}


