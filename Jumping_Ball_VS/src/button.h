#pragma once
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <stdbool.h>
#include <stdlib.h>

struct Button 
{
	int x;
	int y;
	float width;
	float height;
    char *text;
};

void GenerateButton(TTF_Font *font, SDL_Renderer *renderer, struct Button *button, bool isHovering);
bool IsHoveringButton(int mouseX, int mouseY, struct Button button);
