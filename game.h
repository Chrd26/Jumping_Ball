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
    SDL_Surface *buttonTextSurface = nullptr;
    SDL_Texture *buttonTextTexture = nullptr;
    TTF_Font *font;
    SDL_Rect button;
    SDL_Rect messageRect;
    FILE *csvFile = nullptr;
    SDL_Surface *inputSurface = nullptr;
    SDL_Texture *inputTexture = nullptr;
    SDL_Rect textBox;
    SDL_Surface *instructionsSurface = nullptr;
    SDL_Texture *instructionsTexture = nullptr;
    SDL_Rect instructionsHolder;

// Event Variables
private:
    int mouseX, mouseY;
    bool isStartButtonHovered = false;
    bool isStartButtonClicked = false;
    std::string inputString;
    const char* textInput;

public:
    Game();
    ~Game();

    // Functions
private:
    static void RunCalculations(const char *command);
    bool init();
    void DrawCircle(int radius, int x , int y);
    void StartButton(int x , int y);
    void InstructionText(int x, int y);
    void InputValues(int x , int y);
    static bool IsWithinStartButton(int x, int y);
    static bool EnableText(int getMouseX, int getMouseY);
};
