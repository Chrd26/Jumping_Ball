#pragma once
#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "resourcelocator.h"
#include "text.h"
#include "textbox.h"
#include <stdlib.h>

#define screenheight 720
#define screenwidth 1280
#define LEFT_MOUSE_BUTTON 1
#define RIGHT_MOUSE_BUTTON 4

// Variables
SDL_Window *appWindow;
SDL_Renderer *appRenderer;
TTF_Font *appFont;
TTF_Font *textboxFont;
int windowWidth, windowHeight;
struct Resource fontResource;
struct ExteriorBox exteriorTextBox;
struct InteriorBox interiorTextBox;
float mouseX, mouseY;

// Functions
bool InitApp();
void ExitApplication();


