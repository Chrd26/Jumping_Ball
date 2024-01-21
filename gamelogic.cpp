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

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    return true;

}

void Game::ExitGame()
{
    // Destroy Game Elements
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    // Is this even needed?
    // Apparently it is! Failing to do so leads to
    // an undefined behavior, and it might cause problems.
    // Source:
    // https://lazyfoo.net/tutorials/SDL/02_getting_an_image_on_the_screen/index.php
    window = nullptr;
    window = nullptr;

    // Kill apps
    TTF_Quit();
    SDL_Quit();
}

Game::Game()
{
    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
        exit(-1);
    }

    // load font
    font = TTF_OpenFont("../fonts/Montserrat-VariableFont_wght.ttf", 25);

    if (font == nullptr)
    {
        std::cout << "Failed to open font" << SDL_GetError() << std::endl;
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
        //Update screen
        SDL_RenderPresent( renderer);
    }

    //Free resources and close SDL
    ExitGame();
}
