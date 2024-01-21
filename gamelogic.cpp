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
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    return true;

}

void Game::ExitGame()
{
    // Destroy Game Elements
    SDL_FreeSurface(imageSurface);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    // Is this even needed?
    // Apparently it is! Failing to do so leads to
    // an undefined behavior, and it might cause problems.
    // Source:
    // https://lazyfoo.net/tutorials/SDL/02_getting_an_image_on_the_screen/index.php
    window = nullptr;
    imageSurface = nullptr;
    window = nullptr;

    // Kill apps
    TTF_Quit();
    SDL_Quit();
}

bool Game::LoadMedia()
{
    imageSurface = SDL_LoadBMP("../Images/owl-from3axis.bmp");
    font = TTF_OpenFont("../fonts/Montserrat-VariableFont_wght.ttf", 25);

    if (font == nullptr)
    {
        std::cout << "Failed to open font" << SDL_GetError() << std::endl;
    }

    if (imageSurface == nullptr)
    {
        std::cout << "Failed to open image" << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

Game::Game()
{
    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
        exit(-1);
    }

    //Load media
    if( !LoadMedia() )
    {
        printf( "Failed to load media!\n" );
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
        SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( renderer );

        //Render red filled quad
        SDL_Rect fillRect = { screenwidth / 4, screenheight/ 4,
                              screenwidth / 2, screenheight / 2 };
        SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderFillRect( renderer, &fillRect );

        //Render green outlined quad
        SDL_Rect outlineRect = { screenwidth / 6, screenheight/ 6,
                                 screenwidth * 2 / 3, screenheight * 2 / 3 };
        SDL_SetRenderDrawColor( renderer, 0x00, 0xFF, 0x00, 0xFF );
        SDL_RenderDrawRect( renderer, &outlineRect );

        //Draw blue horizontal line
        SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0xFF, 0xFF );
        SDL_RenderDrawLine( renderer, 0, screenheight / 2, screenwidth, screenheight / 2 );

        //Draw vertical line of yellow dots
        SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0x00, 0xFF );
        for( int i = 0; i < screenheight; i += 4 )
        {
            SDL_RenderDrawPoint( renderer, screenwidth / 2, i );
        }

        //Update screen
        SDL_RenderPresent( renderer);
    }

    //Free resources and close SDL
    ExitGame();
}
