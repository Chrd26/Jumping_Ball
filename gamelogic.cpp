#include "game.h"

void Game::RunCalculations(std::string &value)
{
    std::fstream fin;
    int systemCode = std::system("test -f ../jumpcalculations/app/output/calculations.csv");

    if (systemCode == 0)
    {
        std::system("cd ../jumpcalculations/app/output && rm calculations.csv");
    }

    std::string createCommand = "cd ../jumpcalculations && fpm run -- " + value;
    systemCode = system(createCommand.c_str());

    if (systemCode != 0)
    {
        std::cout << "Failed to run calculations" << std::endl;
        exit(-3);
    }

//    SDL_Delay(100);

    // Open CSV file
    openCSV.open("../jumpcalculations/app/output/calculations.csv");

    std::vector<std::string> csvOutput;
    std::string line;

    // Delimit by comma by adding the delimiter at the end of the
    // argument list of getline.
    int counter = 0;
    while (getline(openCSV, line, '\n'))
    {
        if (counter == 0)
        {
            counter++;
            continue;
        }

        csvOutput.push_back(line);
    }

    openCSV.close();

    std::vector<std::string> temp;
    int pos = 0;

    // Delimit to vector code by Dean R.
    // Source: https://sentry.io/answers/split-string-in-cpp/
    while (pos < csvOutput[0].size())
    {
        pos = int(csvOutput[0].find(','));
        temp.push_back(csvOutput[0].substr(0, pos));
        csvOutput[0].erase(0, pos+1);
    }

    int tempSize = int(temp.size());

    for (int i = 0; i < tempSize; i++)
    {
        std::cout << temp[i] << std::endl;
    }

    maxHeight = std::stof(temp[0]);
    timeToReachMaxHeight = std::stof(temp[1]);
    timeToLand = std::stof(temp[2]);
    initialVel = std::stof(inputString);

    std::cout << "Initial Velocity: " << initialVel << std::endl;
    std::cout << "Max Height: " << maxHeight << std::endl;
    std::cout << "Time to Land: " << timeToLand << std::endl;
    std::cout << "Time to reach max height: " << timeToReachMaxHeight << std::endl;

    hasStarted = true;
}

bool Game::init()
{
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

    if (renderer == nullptr)
    {
        std::cout << "Failed to initialise renderer" << std::endl;
    }
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

// Always assign the width and height of the text's surface to the
// rectangle that holds the text, and then destroy the surface as it's not needed.
// This will make sure that it will not stretch or shrink the text in any way.
//Source:
// https://stackoverflow.com/questions/68261748/my-sdl-ttf-rendered-text-ends-up-streched-how-do-i-avoid-that

void Game::InputValues(const int x, const int y)
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    textBoxRect = {x, y, 105, 25};
    SDL_RenderDrawRect(renderer, &textBoxRect);
    textInput = inputString.c_str();
    SDL_Color inputTextColor = {0xFF, 0xFF, 0xFF, 0xFF};
    inputSurface = TTF_RenderText_Solid(font,
                                        textInput,
                                        inputTextColor);
    if (inputSurface != nullptr)
    {
        textBox = {x,y, inputSurface->w, inputSurface->h};
    }else
    {
        textBox = {x, y, 0, 0};
    }

    inputTexture = SDL_CreateTextureFromSurface(renderer, inputSurface);
    SDL_RenderCopy(renderer, inputTexture, nullptr, &textBox);
    SDL_FreeSurface(inputSurface);
}

bool Game::EnableText(int getMouseX, int getMouseY)
{
    if (getMouseX >= static_cast<int>(screenwidth * 0.24f) && getMouseX <=  static_cast<int>(screenwidth * 0.24f) + 105)
    {
        if (getMouseY >= static_cast<int>(screenheight * 0.45f) && getMouseY <= static_cast<int>(screenheight * 0.45f) + 50)
        {
            return true;
        }
    }

    return false;
}

void Game::InstructionsText(const int x, const int y)
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x0FF, 0x0FF, 0xFF);
    SDL_Color instructionsTextColor = {0xFF, 0xFF, 0xFF, 0xFF};
    instructionsSurface1 = TTF_RenderText_Solid(font,
                                               "Click on the box below, and type the initial velocity.",
                                               instructionsTextColor);
    instructionsHolder1 = {x, y,
                          instructionsSurface1->w,
                          instructionsSurface1->h};
    instructionsTexture1 = SDL_CreateTextureFromSurface(renderer, instructionsSurface1);
    SDL_RenderCopy(renderer, instructionsTexture1, nullptr, &instructionsHolder1);

    instructionsSurface2 = TTF_RenderText_Solid(font,
                                                "Only integers are accepted. Press start when ready.",
                                                instructionsTextColor);
    instructionsHolder2 = {x, y + 20,
                           instructionsSurface2->w,
                           instructionsSurface2->h};
    instructionsTexture2 = SDL_CreateTextureFromSurface(renderer, instructionsSurface2);
    SDL_RenderCopy(renderer, instructionsTexture2, nullptr, &instructionsHolder2);

    SDL_FreeSurface(instructionsSurface1);
    SDL_FreeSurface(instructionsSurface2);
    instructionsSurface1 = nullptr;
    instructionsSurface2 = nullptr;
}

void Game::StartButton(const int x, const int y,const std::string buttonName)
{
    TTF_Font *buttonFont = TTF_OpenFont("../fonts/Montserrat-VariableFont_wght.ttf", 35);
    if (isStartButtonHovered)
    {
        button = {x - 5, y + 3, 90, 50};
        SDL_SetRenderDrawColor(renderer, 0xFF, 0x0FF, 0x0FF, 0xFF);
        SDL_RenderFillRect(renderer, &button);
        SDL_Color textColor = {0, 0, 0};
        buttonTextSurface = TTF_RenderText_Solid(buttonFont, buttonName.c_str(), textColor);
        messageRect = {x, y, buttonTextSurface->w, buttonTextSurface->h};
        buttonTextTexture = SDL_CreateTextureFromSurface(renderer, buttonTextSurface);
        SDL_RenderCopy(renderer, buttonTextTexture, nullptr, &messageRect);
        SDL_FreeSurface(buttonTextSurface);
        buttonTextSurface = nullptr;

        return;
    }

    button = {x - 5, y + 3, 90, 50};
    SDL_RenderDrawRect(renderer, &button);
    SDL_Color textColor = {255, 255, 255};
    buttonTextSurface = TTF_RenderText_Solid(buttonFont, buttonName.c_str(), textColor);
    buttonTextTexture = SDL_CreateTextureFromSurface(renderer, buttonTextSurface);
    messageRect = {x, y, buttonTextSurface->w, buttonTextSurface->h};
    SDL_RenderCopy(renderer, buttonTextTexture, nullptr, &messageRect);
    SDL_FreeSurface(buttonTextSurface);
    buttonTextSurface = nullptr;

    TTF_CloseFont(buttonFont);
}

void Game::DrawCircle(const int radius, const int x, const int y)
{
    // Special thanks to the following thread for the info
    // to calculate the circle:
    // https://math.stackexchange.com/questions/260096/find-the-coordinates-of-a-point-on-a-circle

    double currentDegree = 0.0f;
    while (currentDegree < 360)
    {
        SDL_RenderDrawPoint(renderer,
                            static_cast<int>(radius*cos(currentDegree) + (double)x),
                            static_cast<int>(radius*sin(currentDegree) + (double)y));
        currentDegree += 1.5f;
    }
}

Game::~Game()
{
    // Destroy Game Elements
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(buttonTextTexture);
    TTF_CloseFont(font);
    SDL_DestroyTexture(inputTexture);
    SDL_DestroyTexture(instructionsTexture1);

    // Is this even needed?
    // Apparently it is! Failing to do so leads to
    // an undefined behavior, and it might cause problems.
    // Source:
    // https://lazyfoo.net/tutorials/SDL/02_getting_an_image_on_the_screen/index.php
    window = nullptr;
    renderer = nullptr;
    buttonTextTexture = nullptr;
    inputTexture = nullptr;
    instructionsTexture1 = nullptr;
    font = nullptr;

    // Kill apps
    TTF_Quit();
    SDL_Quit();
}

Game::Game()
{
    int ballRadius = 50;

    //Start up SDL and create window
    if( !init() )
    {
        std::cout << "Failed to initialize SDL" << std::endl;
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
            // Avoid declaring variables in switch cases as
            // other cases might use the declared variables.
            // a switch cases is not a scope
            // Read more:
            // https://stackoverflow.com/questions/5685471/error-jump-to-case-label-in-switch-statement
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
                        isStartButtonHovered = false;

                        if (hasStarted)
                        {
                            StartButton(screenwidth * 0.25f, screenheight * 0.50f, "Stop");
                            break;
                        }

                        StartButton(screenwidth * 0.25f, screenheight * 0.50f, "Start");
                        break;
                    }

                    if (EnableText(mouseX, mouseY))
                    {
                        SDL_StartTextInput();
                        break;
                    }

                    SDL_StopTextInput();

                case SDL_MOUSEBUTTONUP:

                    if (isStartButtonClicked)
                    {
                        isStartButtonClicked = false;
                        isStartButtonHovered = true;

                        if (hasStarted)
                        {
                            StartButton(screenwidth * 0.25f, screenheight * 0.50f, "Start");
                            circlePosition = 1.0f;
                            hasStarted = false;
                            break;
                        }

                        if (inputString.empty())
                        {
                            break;
                        }

                        StartButton(screenwidth * 0.25f, screenheight * 0.50f, "Stop");
                        RunCalculations(inputString);
                        break;
                    }

                case SDL_TEXTINPUT:
                    if (inputString.length() > 2)
                    {
                        break;
                    }

                    inputChar = currentEvent.edit.text;

                    if (inputChar.empty())
                    {
                        break;
                    }

                    try
                    {
                        int getInt = std::stoi(inputChar);
                    }
                    catch(std::invalid_argument)
                    {
                        break;
                    }

                    inputString += currentEvent.edit.text;
                    inputChar.pop_back();

                case SDL_KEYDOWN:
                    if (currentEvent.key.keysym.sym == SDLK_BACKSPACE || currentEvent.key.keysym.sym == SDLK_DELETE)
                    {
                        if (inputString.empty())
                        {
                            break;
                        }

                        inputString.pop_back();
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


        if (hasStarted)
        {
            StartButton(screenwidth * 0.25f, screenheight * 0.50f, "Stop");
        }else
        {
            StartButton(screenwidth * 0.25f, screenheight * 0.50f, "Start");
        }

        // Input Box
        InputValues(static_cast<int>(screenwidth * 0.24f),
                    static_cast<int>(screenheight * 0.45f));

        // Instructions Text
        InstructionsText(screenwidth * 0.09f, screenheight * 0.35f);

        if (hasStarted) {
            if (currentHeight >= maxHeight)
            {
                DrawCircle(ballRadius,
                           screenwidth * 0.75f,
                           screenheight - (float)ballRadius * circlePosition);
            }else
            {
                circlePosition += initialVel/maxHeight;
                std::cout << "Position: " << circlePosition << std::endl;
                DrawCircle(ballRadius,
                        screenwidth * 0.75f,
                        screenheight - (float)ballRadius * circlePosition);
                currentHeight += timeToReachMaxHeight*initialVel;
                std::cout << "Current Height " << currentHeight << std::endl;
            }
        }else
        {
            DrawCircle(ballRadius,
                       screenwidth * 0.75f,
                       screenheight - (float)ballRadius * circlePosition);
        }

        //Update screen
        SDL_RenderPresent(renderer);
    }
}
