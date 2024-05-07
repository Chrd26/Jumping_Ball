#pragma once
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "resourcelocator.h"

bool TextComponentInit(Resource *resource);
void DisplayText(SDL_Renderer *renderer, TTF_Font *font, char *content, int x, int y);
