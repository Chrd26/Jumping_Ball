#pragma once
#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "resourcelocator.h"
#include "text.h"

#define screenheight 720
#define screenwidth 1280

// Variables
SDL_Window *appWindow;
SDL_Renderer *appRenderer;
TTF_Font *appFont;
struct Resource fontResource;

// Functions
bool InitApp();
void ExitApplication();


