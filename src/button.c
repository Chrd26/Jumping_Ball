#include "button.h"

void GenerateButton(TTF_Font *font, SDL_Renderer *renderer, struct Button *button, bool isHovering)
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
	
	if (button->width == 0 || button->height == 0)
	{
		button->width = buttonTextSurface->w;
		button->height = buttonTextSurface->h; 
	}
	
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_FRect buttonBorderRect = {button->x, button->y, button->width * 1.3, button->height * 1.3};
																
	if (isHovering)
	{
		SDL_RenderFillRect(renderer, &buttonBorderRect);
	}else
	{
		SDL_RenderRect(renderer, &buttonBorderRect);
	}
	
	SDL_Texture *buttonTextTexture = SDL_CreateTextureFromSurface(renderer, buttonTextSurface);
	const SDL_FRect buttonTextHolder = {button->x * 1.04, button->y * 1.01, button->width, button->height};
																			
	SDL_RenderTexture(renderer, buttonTextTexture, NULL, &buttonTextHolder);
	
	SDL_RenderRect(renderer, &buttonBorderRect);
	
	SDL_DestroySurface(buttonTextSurface);
	buttonTextSurface = NULL;
	SDL_DestroyTexture(buttonTextTexture);
}

bool IsHoveringButton(int mouseX, int mouseY, struct Button button)
{
	if (mouseX >= button.x && mouseX <= button.x + button.width * 1.3)
	{
		if (mouseY >= button.y && mouseY <= button.y + button.height * 1.3)
		{
			return true;
		}
	}
	
	return false;
}
