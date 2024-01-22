#include "game.h"

void Game::RunCalculations(const char *command)
{
    int code = system(command);

    if (code != 0)
    {
        std::cout << "Failed to run calculations" << std::endl;
        exit(-3);
    }
}

bool Game::init()
{
    // Note, I had some issues due to the surface
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0 || TTF_Init() < 0)
    {
        std::cout << "Failed to initialise SDL " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("Jumping Ball", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, screenwidth, screenheight,
                              SDL_WINDOW_SHOWN);

    if (window == nullptr)
    {
        std::cout << "SDL failed to create a window" << std::endl;
    }

    // load font
    font = TTF_OpenFont("../fonts/Montserrat-VariableFont_wght.ttf", 20);

    if (font == nullptr)
    {
        std::cout << "Failed to open font" << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    return true;

}

bool Game::IsWithinStartButton(int x, int y)
{
    if (x >= static_cast<int>((float)screenwidth * 0.25f) && x <= screenwidth * 0.25 + 90)
    {
        if (y >= static_cast<int>((float) screenheight * 0.50f) && y <= screenheight * 0.50 + 75)
        {
            return true;
        }
    }

    return false;
}

void Game::StartButton(const int x, const int y)
{
    if (isStartButtonHovered)
    {

        SDL_SetRenderDrawColor(renderer, 0xFF, 0x0FF, 0x0FF, 0xFF);
        button = {x - 5, y + 5, 90, 75};
        SDL_RenderFillRect(renderer, &button);

        SDL_Color textColor = {0, 0, 0};
        textSurface = TTF_RenderText_Solid(font, "Start", textColor);
        message = SDL_CreateTextureFromSurface(renderer, textSurface);
        messageRect = {x, y,80, 80};
        SDL_RenderCopy(renderer, message, nullptr, &messageRect);

        return;
    }

    // Button
    button = {x - 5, y + 5, 90, 75};
    SDL_RenderDrawRect(renderer, &button);
    // Render Message
    SDL_Color textColor = {255, 255, 255};
    textSurface = TTF_RenderText_Solid(font, "Start", textColor);
    message = SDL_CreateTextureFromSurface(renderer, textSurface);
    messageRect = {x, y,80, 80};
    SDL_RenderCopy(renderer, message, nullptr, &messageRect);

}

void Game::DrawCircle(const int radius, const int x, const int y)
{
    double currentDegree = 0.0f;
    while (currentDegree < 360)
    {
        SDL_RenderDrawPoint(renderer,
                            static_cast<int>(radius*cos(currentDegree) + (double)x),
                            static_cast<int>(radius*sin(currentDegree) + (double)y));
        currentDegree += 1.5f;
    }

    // Special thanks to the following thread for the info
    // to calculate the circle:
    // https://math.stackexchange.com/questions/260096/find-the-coordinates-of-a-point-on-a-circle
}

Game::~Game()
{
    // Destroy Game Elements
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(message);
    TTF_CloseFont(font);

    // Is this even needed?
    // Apparently it is! Failing to do so leads to
    // an undefined behavior, and it might cause problems.
    // Source:
    // https://lazyfoo.net/tutorials/SDL/02_getting_an_image_on_the_screen/index.php
    window = nullptr;
    renderer = nullptr;
    textSurface = nullptr;
    message = nullptr;

    // Kill apps
    TTF_Quit();
    SDL_Quit();
}

Game::Game()
{
    int ballRadius = 50;
    float circlePosition = 1.0f;
    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
        exit(-1);
    }


    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event currentEvent;

    //While application is running
    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &currentEvent ) != 0 )
        {
            switch (currentEvent.type)
            {
                case SDL_QUIT:
                    quit = true;
                    break;

                case SDL_MOUSEMOTION:
                    SDL_GetMouseState(&mouseX, &mouseY);

                    if (IsWithinStartButton(mouseX, mouseY))
                    {
                        isStartButtonHovered = true;
                        break;
                    }

                    isStartButtonHovered = false;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    SDL_GetMouseState(&mouseX, &mouseY);

                    if (IsWithinStartButton(mouseX, mouseY))
                    {
                        isStartButtonClicked = true;
                        break;
                    }

                case SDL_MOUSEBUTTONUP:

                    if (isStartButtonClicked)
                    {
                        isStartButtonClicked = false;
                        break;
                    }
            }
        }

        //Clear screen
        SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0xFF );
        SDL_RenderClear( renderer );

        //Draw Separator
        SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderDrawLine( renderer, screenwidth * 0.55f,
                            0,
                            screenwidth * 0.55f,
                            screenheight);

        DrawCircle(ballRadius,screenwidth * 0.75f,
                   screenheight - (float)ballRadius * circlePosition);

        circlePosition += 0.001f;
        StartButton(screenwidth * 0.25f, screenheight * 0.50f);

        //Update screen
        SDL_RenderPresent(renderer);
    }

}
