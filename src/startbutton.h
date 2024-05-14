#pragma once
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <stdbool.h>
#include <stdlib.h>

struct StartButton
{
	int x;
	int y;
	float width;
	float height;
};

void GenerateButton(TTF_Font *font, SDL_Renderer *renderer, struct StartButton *startButton, bool isHovering);
bool IsHoveringStartButton(int mouseX, int mouseY, struct StartButton startButton);
