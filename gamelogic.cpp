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

    SDL_Color textColor = {255, 255, 255};
    textSurface = TTF_RenderText_Solid(font, "Start", textColor);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    return true;

}

void Game::StartButton(int x, int y)
{
    button = {x - 5, y + 5, 90, 75};
    SDL_RenderDrawRect(renderer, &button);

    message = SDL_CreateTextureFromSurface(renderer, textSurface);
    messageRect = {x, y,80, 80};
    SDL_RenderCopy(renderer, message, NULL, &messageRect);
}

void Game::DrawCircle( int radius, int x, int y)
{
    double currentDegree = 0.0f;
    while (currentDegree < 360)
    {
        SDL_RenderDrawPoint(renderer,
                            static_cast<int>(radius*cos(currentDegree) + (double)x),
                            static_cast<int>(radius*sin(currentDegree) + (double)y));
        currentDegree += 0.1f;
    }

    // Special thanks to the following thread for the info
    // to calculate the circle:
    // https://math.stackexchange.com/questions/260096/find-the-coordinates-of-a-point-on-a-circle
}

void Game::ExitGame()
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
            //User requests quit
            if( currentEvent.type == SDL_QUIT )
            {
                quit = true;
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
        SDL_RenderPresent( renderer);
    }

    //Free resources and close SDL
    ExitGame();
}
