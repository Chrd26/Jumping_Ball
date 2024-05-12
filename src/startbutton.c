#include "startbutton.h"

void GenerateButton(TTF_Font *font, SDL_Renderer *renderer, struct StartButton &startButton, bool isHovering)
{
	SDL_Color color = {0xFF, 0xFF, 0xFF, 0xFF};
	SDL_Surface *buttonTextSurface = TTF_RenderText_Solid(font, "Start", color);
	
	if (startButton.width == 0 || startButton.height == 0)
	{
		startButton.width = buttonTextSurface->w;
		startButton.height = buttonTextSurface->height; 
	}
	
	SDL_Texture *buttonTextTexture = SDL_CreateTextureFromSurface(renderer, buttonTextSurface);
	const SDL_FRect buttonTextHolder = {startButton.x, startButton.y, 
																			startButton.width, startButton.height};
																			
	SDL_RenderTexture(renderer, buttonTextTexture, NULL, &buttonTextHolder);
	
}
