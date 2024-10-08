#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "app.h"

int main(void)
{
    if (!InitApp())
    {
        exit(EXIT_FAILURE);
    }

    double startTick = 0, endTick = 0, cursorTimer = 0; 
    // double deltaTime = 0;
    char *temp;
    size_t currentStringSize = 0;
    Uint32 mouseState;
    bool quit = false;
    SDL_Event events;

    while(!quit)
    {
        // Start counting
        startTick = SDL_GetTicks();
        SDL_RenderClear(appRenderer);	
        currentStringSize = strlen(interiorTextBox.content);

        while(SDL_PollEvent(&events))
        {
            switch(events.type)
            {
                case SDL_EVENT_QUIT:
                    quit = true;
					break;
                case SDL_EVENT_MOUSE_BUTTON_UP:
                    if (mouseState == LEFT_MOUSE_BUTTON)
                    {
                        if (IsHoveringExteriorBox(mouseX, mouseY, exteriorTextBox))
                        {
                            
                            if(!interiorTextBox.isEnabled && hasSimStarted == false)
                            {
                                interiorTextBox.isEnabled = true;
                                SDL_StartTextInput();
                            }
                            break;
                        }

                        if (IsHoveringButton(mouseX, mouseY, startButton))
                        {
                            if (!hasSimStarted)
                            {
                                executionResults = GetResults(interiorTextBox.content); 

                                if (executionResults.doResultsExist)
                                {
                                    hasSimStarted = true;
                                }else
                                {
                                    break;
                                }

                                //free(interiorTextBox.content);
                                //interiorTextBox.content = calloc(4, sizeof(char));
                                memset(interiorTextBox.content, 0, 1024);
                            }else
                            {
                                hasSimStarted = false;
                            }
                        }

                        if (IsHoveringButton(mouseX, mouseY, exitButton))
                        {
                            quit = true;
                        }

                        interiorTextBox.isEnabled = false;
                        SDL_StopTextInput();
                    }
                break;
                case SDL_EVENT_TEXT_INPUT:
                    if (currentStringSize >= 3)
                    {
                        break;
                    }

                    int getVal = (int)*events.text.text;

                    if (getVal - 48 < 0 || getVal - 48 > 9)
                    {
                        break;
                    }
                    
                    char *newCharacter = events.text.text;
                    char cpyTemp[1024];

                    if (strlen(interiorTextBox.content) == 0)
                    {
                        for (int i = 0; i < strlen(newCharacter); i++)
                        {
                            interiorTextBox.content[i] = newCharacter[i];
                        }
                    }
                    else
                    {
                        for (int i = 0; i < strlen(interiorTextBox.content); i++)
                        {
                            cpyTemp[i] = interiorTextBox.content[i];
                        }

                        cpyTemp[strlen(interiorTextBox.content)] = newCharacter[0];
                        cpyTemp[strlen(interiorTextBox.content) + 1] = '\0';

                        for (int k = 0; k < strlen(cpyTemp); k++)
                        {
                            interiorTextBox.content[k] = cpyTemp[k];
                        }

                        interiorTextBox.content[strlen(cpyTemp)] = '\0';
                        printf("Result: %s", interiorTextBox.content);
                    }
 
                break;
                case SDL_EVENT_KEY_UP:
                    switch(events.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            interiorTextBox.isEnabled = false;
                            SDL_StopTextInput();
							break;
                        case SDLK_BACKSPACE:
                        
                          if (currentStringSize <= 0)
                            {
                                break;
                            }

                            char cpyTemp[1024];

                            for (int i = 0; i < strlen(interiorTextBox.content) - 1; i++)
                            {
                                cpyTemp[i] = interiorTextBox.content[i];
                            }

                            cpyTemp[strlen(interiorTextBox.content) - 1] = '\0';

                            for (int j = 0; j < strlen(cpyTemp); j++)
                            {
                                interiorTextBox.content[j] = cpyTemp[j];
                            }

                            interiorTextBox.content[strlen(cpyTemp)] = '\0';

                            printf("Deleted string %s\n", interiorTextBox.content);
                                
                            break;
                    }
                    
					break;
            }
        }

        SDL_PumpEvents();
        mouseState = SDL_GetMouseState(&mouseX, &mouseY);
        
        mouseX *= 2;
        mouseY *= 2;

        DisplayText(appRenderer, appFont, "Add a starting value under 200 and press start", 
                    windowWidth * 0.065, windowHeight * 0.1);	
        SDL_SetRenderDrawColor(	appRenderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderLine(appRenderer, windowWidth/2, 0, windowWidth/2,  windowHeight);

        TextBoxHandler(	textboxFont, appRenderer, exteriorTextBox, interiorTextBox, 
                       strlen(interiorTextBox.content), &cursorTimer);

        // Simulation, it might be a good idea to use it in a function
        if(hasSimStarted)
        {
            if (executionResults.operatedVelocity > 0)
            {
                printf("%d\n", executionResults.operatedVelocity);

                if (executionResults.upwardsMovement) 
                {
                    ball.y -= (double)executionResults.operatedVelocity;
                    executionResults.operatedVelocity -= (int)executionResults.gravity;  
                }else
                {
                    ball.y += (double)executionResults.operatedVelocity;
                    executionResults.operatedVelocity += (int)executionResults.gravity; 

                    if (ball.y > windowHeight - ball.radius)
                    {
                        executionResults.operatedVelocity = 0;
                    }
                }
            }
            else if (executionResults.operatedVelocity <= 0) 
            {
                if (!executionResults.upwardsMovement && executionResults.initialVelocity > 1)
                {
                    executionResults.initialVelocity = executionResults.initialVelocity / 1.1;
                }

                executionResults.upwardsMovement = !executionResults.upwardsMovement;
                
                if (executionResults.upwardsMovement)
                {
					executionResults.operatedVelocity = executionResults.initialVelocity;
				}else
				{
					executionResults.operatedVelocity = executionResults.initialVelocity / 2;
				}
				

                if (executionResults.initialVelocity <= 1)
                {
                    hasSimStarted = false;
                }
            }

            startButton.text = "Stop";

        }else
        {
            ball.y = windowHeight - ball.radius;
            startButton.text = "Start";
        }

        GenerateBall(ball, appRenderer);

        if ((mouseState &SDL_BUTTON_LMASK) != 0 && IsHoveringButton(mouseX, mouseY, startButton))
        {
            GenerateButton(appFont, appRenderer, &startButton, false);
        }
        else
        {
            GenerateButton(appFont, appRenderer, &startButton, IsHoveringButton(mouseX, mouseY, startButton));
        }


        if ((mouseState &SDL_BUTTON_LMASK) != 0 && IsHoveringButton(mouseX, mouseY, exitButton))
        {
            GenerateButton(appFont, appRenderer, &exitButton, false);
        }
        else
        {
            GenerateButton(appFont, appRenderer, &exitButton, IsHoveringButton(mouseX, mouseY, exitButton));
        }

        SDL_SetRenderDrawColor(	appRenderer, 0x55, 0x55, 0x66, 0xAA);	
        SDL_RenderPresent(appRenderer);										

        endTick = SDL_GetTicks();

        if (interiorTextBox.isEnabled)
        {
            cursorTimer += (endTick-startTick)/1000;
        }

        //deltaTime = (endTick-startTick)/1000;
        
    }

    ExitApplication();
    return EXIT_SUCCESS;
}

