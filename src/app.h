#pragma once
#include <SDl3/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <resource.h>

#define screenheight 720
#define screenwidth 1280

// Variables
SDL_Window *appWindow = NULL;
SDL_Renderer *appRenderer = NULL;
Resource appFont;

// Functions
bool InitApp();
void ExitApplication();


