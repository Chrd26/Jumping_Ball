#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>

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
    SDL_Surface *inputSurface = nullptr;
    SDL_Texture *inputTexture = nullptr;
    SDL_Rect textBoxRect;
    SDL_Rect textBox;
    SDL_Surface *instructionsSurface1 = nullptr;
    SDL_Surface *instructionsSurface2 = nullptr;
    SDL_Texture *instructionsTexture1 = nullptr;
    SDL_Texture *instructionsTexture2 = nullptr;
    SDL_Rect instructionsHolder1;
    SDL_Rect instructionsHolder2;
    std::string inputChar;
    std::ifstream openCSV;

// Event Variables
private:
    int mouseX, mouseY;
    bool isStartButtonHovered = false;
    bool isStartButtonClicked = false;
    std::string inputString;
    const char* textInput;
    int maxHeight = 0.0f;
    float timeToLand = 0.0f;
    float timeToReachMaxHeight = 0.0f;
    bool hasStarted = false;

public:
    Game();
    ~Game();

    // Functions
private:
    void RunCalculations(std::string value);
    bool init();
    void DrawCircle(int radius, int x , int y);
    void StartButton(int x , int y, std::string buttonName);
    void InstructionsText(int x, int y);
    void InputValues(int x , int y);
    static bool IsWithinStartButton(int x, int y);
    static bool EnableText(int getMouseX, int getMouseY);
};
