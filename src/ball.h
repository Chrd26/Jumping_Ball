#pragma once
#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Ball
{
	float x;
	float y;
	float radius;
};

void GenerateBall(struct Ball ball, SDL_Renderer *renderer);
