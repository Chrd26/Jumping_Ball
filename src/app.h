#pragma once
#include <SDl3/SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define screenheight 720
#define screenwidth 1280

// Methods
SDL_Window *appWindow = NULL;
SDL_Renderer *appRenderer = NULL;

// Functions
bool InitApp();
void ExitApplication();


