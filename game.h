#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <cstring>
#include <cmath>

#define screenheight 720
#define screenwidth 1280

class Game {
// Main components
private:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_Surface *textSurface = nullptr;
    SDL_Texture *message = nullptr;
    std::string textInput;
    TTF_Font *font;
    SDL_Rect button;
    SDL_Rect messageRect;
    FILE *csvFile = nullptr;
    SDL_Surface *inputSurface = nullptr;
    SDL_Texture *inputTexture = nullptr;

// Event Variables
private:
    int mouseX, mouseY;
    bool isStartButtonHovered = false;
    bool isStartButtonClicked = false;

public:
    Game();
    ~Game();

private:
    static void RunCalculations(const char *command);
    bool init();
    void DrawCircle(int radius, int x , int y);
    void StartButton(int x , int y);
    bool IsWithinStartButton(int x, int y);
};
