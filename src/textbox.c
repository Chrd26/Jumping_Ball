#include "textbox.h"

void TextBoxHandler(TTF_Font *font, SDL_Renderer *renderer, struct ExteriorBox exteriorbox, 
										struct InteriorBox interiorTextBox)
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_FRect exteriorBoxRect = {exteriorbox.x, exteriorbox.y, exteriorbox.width, exteriorbox.height};
	SDL_RenderRect(renderer, &exteriorBoxRect);
	
	if (interiorTextBox.isEnabled)
	{
		SDL_Color fontColor = {0xFF, 0xFF, 0xFF, 0xFF};
		strncat(interiorTextBox.content, interiorTextBox.cursor, 1);
		SDL_Surface *interiorTextSurface = TTF_RenderText_Solid(font, interiorTextBox.content, fontColor);
		SDL_Texture *interiortextTexture = SDL_CreateTextureFromSurface(renderer, interiorTextSurface);
		SDL_FRect interiorBoxRect = {	exteriorbox.x, exteriorbox.y, 
																	interiorTextSurface->w, 
																	interiorTextSurface->h};
		
		SDL_RenderTexture(renderer, interiortextTexture, NULL, &interiorBoxRect);
		SDL_DestroySurface(interiorTextSurface);
		interiorTextSurface = NULL;
		SDL_DestroyTexture(interiortextTexture);
		interiortextTexture = NULL;
	}
}

bool IsHoveringExteriorBox(int mouseX, int mouseY, struct ExteriorBox exteriorBox)
{
	if (mouseX >= exteriorBox.x && mouseX <= exteriorBox.x + exteriorBox.width)
	{
		if (mouseY >= exteriorBox.y && mouseY <= exteriorBox.y + exteriorBox.height)
		{
			return true;
		}
	}
	
	return false;
}
