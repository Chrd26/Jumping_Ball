#include "textbox.h"

void TextBoxHandler(TTF_Font *font, SDL_Renderer *renderer, struct ExteriorBox exteriorbox, 
										struct InteriorBox interiorTextBox, size_t length, double *frameTime)
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	const SDL_FRect exteriorBoxRect = {exteriorbox.x, exteriorbox.y, exteriorbox.width, exteriorbox.height};
	SDL_RenderRect(renderer, &exteriorBoxRect);
	
	// Textbox text
	if (interiorTextBox.isEnabled && *frameTime < 0.5)
	{
		char temp[5];

		if (strlen(interiorTextBox.content) > 0)
		{
			for (int i = 0; i < strlen(interiorTextBox.content); i++)
			{
				temp[i] = interiorTextBox.content[i];
			}

			temp[strlen(interiorTextBox.content)] = 'I';
			temp[strlen(interiorTextBox.content) + 1] = '\0';
		}
		else
		{
			temp[0] = 'I';
			temp[1] = '\0';
		}

		SDL_Color fontColor = { 0xFF, 0xFF, 0xFF, 0xFF};
		SDL_Surface* interiorTextSurface = TTF_RenderText_Solid(font, temp, fontColor);
		SDL_Texture *interiortextTexture = SDL_CreateTextureFromSurface(renderer, interiorTextSurface);
		const SDL_FRect interiorBoxRect = {	exteriorbox.x * 1.22, exteriorbox.y * 1.125, 
																				interiorTextSurface->w, 
																				interiorTextSurface->h};
		
		SDL_RenderTexture(renderer, interiortextTexture, NULL, &interiorBoxRect);
		SDL_DestroySurface(interiorTextSurface);
		interiorTextSurface = NULL;
		SDL_DestroyTexture(interiortextTexture);
		interiortextTexture = NULL;
	}

	if (interiorTextBox.content != NULL)
	{

		if (interiorTextBox.isEnabled && *frameTime >= 0.5 && strlen(interiorTextBox.content) > 0)
		{
			SDL_Color fontColor = { 0xFF, 0xFF, 0xFF, 0xFF };
			SDL_Surface* interiorTextSurface = TTF_RenderText_Solid(font, interiorTextBox.content, fontColor);
			SDL_Texture* interiortextTexture = SDL_CreateTextureFromSurface(renderer, interiorTextSurface);
			const SDL_FRect interiorBoxRect = { exteriorbox.x * 1.22, exteriorbox.y * 1.125,
																		interiorTextSurface->w,
																		interiorTextSurface->h };

			SDL_RenderTexture(renderer, interiortextTexture, NULL, &interiorBoxRect);
			SDL_DestroySurface(interiorTextSurface);
			interiorTextSurface = NULL;
			SDL_DestroyTexture(interiortextTexture);
			interiortextTexture = NULL;
		}
	}
	
	if (*frameTime >= 1)
	{
		*frameTime = 0;
	}

	if (interiorTextBox.content == NULL)
	{
		return;
	}
	
	if (!interiorTextBox.isEnabled && strlen(interiorTextBox.content) > 0)
	{
		SDL_Color fontColor = {0xFF, 0xFF, 0xFF, 0xFF};
		SDL_Surface *interiorTextSurface = TTF_RenderText_Solid(font, interiorTextBox.content, fontColor);
		SDL_Texture *interiortextTexture = SDL_CreateTextureFromSurface(renderer, interiorTextSurface);
		const SDL_FRect interiorBoxRect = {	exteriorbox.x * 1.22, exteriorbox.y * 1.125, 
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
