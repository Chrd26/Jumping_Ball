#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <cstring>

#define screenheight 720
#define screenwidth 1280

class Game {
// Main components
private:
    SDL_Window *window = nullptr;
    SDL_Surface *imageSurface = nullptr;
    SDL_Renderer *renderer = nullptr;
    std::string textInput;
    TTF_Font *font;

public:
    Game();

private:
    static void RunCalculations(const char *command);
    void ExitGame();
    bool LoadMedia();
    bool init();
};
