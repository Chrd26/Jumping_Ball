#include "startbutton.h"

void GenerateButton(TTF_Font *font, SDL_Renderer *renderer, struct StartButton *startButton, bool isHovering)
{	
	SDL_Color color;

	if (isHovering) 
	{
		color.r = 0x00;
		color.g = 0x00;
		color.b = 0x00;
		color.a = 0xFF;
	}else
	{
		color.r = 0xFF;
		color.g = 0xFF;
		color.b = 0xFF;
		color.a = 0xFF;
	}
	
	SDL_Surface *buttonTextSurface = TTF_RenderText_Solid(font, "Start", color);
	
	if (startButton->width == 0 || startButton->height == 0)
	{
		startButton->width = buttonTextSurface->w;
		startButton->height = buttonTextSurface->h; 
	}
	
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_FRect buttonBorderRect = {startButton->x, startButton->y, 
																startButton->width * 1.3, startButton->height * 1.3};
																
	if (isHovering)
	{
		SDL_RenderFillRect(renderer, &buttonBorderRect);
	}else
	{
		SDL_RenderRect(renderer, &buttonBorderRect);
	}
	
	SDL_Texture *buttonTextTexture = SDL_CreateTextureFromSurface(renderer, buttonTextSurface);
	const SDL_FRect buttonTextHolder = {startButton->x * 1.04, startButton->y * 1.01, 
																			startButton->width, startButton->height};
																			
	SDL_RenderTexture(renderer, buttonTextTexture, NULL, &buttonTextHolder);
	
	SDL_RenderRect(renderer, &buttonBorderRect);
	
	SDL_DestroySurface(buttonTextSurface);
	buttonTextSurface = NULL;
	SDL_DestroyTexture(buttonTextTexture);
}

bool IsHoveringStartButton(int mouseX, int mouseY, struct StartButton startButton)
{
	if (mouseX >= startButton.x&& mouseX <= startButton.x + startButton.width * 1.3)
	{
		if (mouseY >= startButton.y && mouseY <= startButton.y + startButton.height * 1.3)
		{
			return true;
		}
	}
	
	return false;
}
