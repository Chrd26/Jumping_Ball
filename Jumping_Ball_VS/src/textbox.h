#pragma once
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// This is a text box that can recieve 1 - 3 digit numbers. 
// The box will be a fixed size, a blinking cursor will appear when the
// box is clicked. If it is unclicked, then the blinking cursor will go away.

struct ExteriorBox
{
	int x;
	int y;
	int width;
	int height;
};

struct InteriorBox
{
	char *content;
	char *cursor;
	bool isEnabled;
	bool keyboardPress;
	int x;
	int y;
	int asciiSubstractionValue; // -48
};

void TextBoxHandler(TTF_Font *font, SDL_Renderer *renderer, struct ExteriorBox exteriorBox, 
										struct InteriorBox interiorBox, size_t length, double *frameTime);
bool IsHoveringExteriorBox(int mouseX, int mouseY, struct ExteriorBox exteriorBox);



