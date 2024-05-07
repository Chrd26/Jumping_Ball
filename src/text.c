#include "text.h"

bool TextComponentInit(Resource *resource)
{
	int getValue = TTF_Init();
	
	if (getValue != 0)
	{
		printf("Failed to load TTF, %s", TTF_GetError());
		return false;
	}
	
	// load font
	resource->location = FindResource(resource->location);
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


