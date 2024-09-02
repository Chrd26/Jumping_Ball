#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "app.h"

int main(void)
{
	struct Application application;
    if (!InitApp(&application))
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
        SDL_RenderClear(application.appRenderer);	
        currentStringSize = strlen(application.interiorTextBox.content);

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
                        if (IsHoveringExteriorBox(	application.mouseX, 
													application.mouseY, 
													application.exteriorTextBox))
                        {
                            
                            if(!application.interiorTextBox.isEnabled && application.hasSimStarted == false)
                            {
                                application.interiorTextBox.isEnabled = true;
                                SDL_StartTextInput();
                            }
                            break;
                        }

                        if (IsHoveringButton(	application.mouseX, 
												application.mouseY, 
												application.startButton))
                        {
                            if (!application.hasSimStarted)
                            {
                                application.executionResults = GetResults(application.interiorTextBox.content); 

                                if (application.executionResults.doResultsExist)
                                {
                                    application.hasSimStarted = true;
                                }else
                                {
                                    break;
                                }

                                //free(interiorTextBox.content);
                                //interiorTextBox.content = calloc(4, sizeof(char));
                                memset(application.interiorTextBox.content, 0, 1024);
                            }else
                            {
                                application.hasSimStarted = false;
                            }
                        }

                        if (IsHoveringButton(	application.mouseX, 
												application.mouseY, 
												application.exitButton))
                        {
                            quit = true;
                        }

                        application.interiorTextBox.isEnabled = false;
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

                    if (strlen(application.interiorTextBox.content) == 0)
                    {
                        for (int i = 0; i < strlen(newCharacter); i++)
                        {
                            application.interiorTextBox.content[i] = newCharacter[i];
                        }
                    }
                    else
                    {
                        for (int i = 0; i < strlen(application.interiorTextBox.content); i++)
                        {
                            cpyTemp[i] = application.interiorTextBox.content[i];
                        }

                        cpyTemp[strlen(application.interiorTextBox.content)] = newCharacter[0];
                        cpyTemp[strlen(application.interiorTextBox.content) + 1] = '\0';

                        for (int k = 0; k < strlen(cpyTemp); k++)
                        {
                            application.interiorTextBox.content[k] = cpyTemp[k];
                        }

                        application.interiorTextBox.content[strlen(cpyTemp)] = '\0';
                        printf("Result: %s", application.interiorTextBox.content);
                    }
 
                break;
                case SDL_EVENT_KEY_UP:
                    switch(events.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            application.interiorTextBox.isEnabled = false;
                            SDL_StopTextInput();
							break;
                        case SDLK_BACKSPACE:
                        
                          if (currentStringSize <= 0)
                            {
                                break;
                            }

                            char cpyTemp[1024];

                            for (int i = 0; i < strlen(application.interiorTextBox.content) - 1; i++)
                            {
                                cpyTemp[i] = application.interiorTextBox.content[i];
                            }

                            cpyTemp[strlen(application.interiorTextBox.content) - 1] = '\0';

                            for (int j = 0; j < strlen(cpyTemp); j++)
                            {
                                application.interiorTextBox.content[j] = cpyTemp[j];
                            }

                            application.interiorTextBox.content[strlen(cpyTemp)] = '\0';

                            printf(	"Deleted string %s\n", 
									application.interiorTextBox.content);
                                
                            break;
                    }
                    
					break;
            }
        }

        SDL_PumpEvents();
        mouseState = SDL_GetMouseState(&application.mouseX, &application.mouseY);
        
        application.mouseX *= 2;
        application.mouseY *= 2;

        DisplayText(application.appRenderer, application.appFont, "Add a starting value under 200 and press start", 
                    application.windowWidth * 0.065, application.windowHeight * 0.1);	
        SDL_SetRenderDrawColor(application.appRenderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderLine(	application.appRenderer, 
						application.windowWidth/2, 
						0, 
						application.windowWidth/2,  
						application.windowHeight);

        TextBoxHandler(	application.textboxFont, application.appRenderer, 
						application.exteriorTextBox, 
						application.interiorTextBox, 
						strlen(application.interiorTextBox.content), &cursorTimer);

        // Simulation, it might be a good idea to use it in a function
        if(application.hasSimStarted)
        {
            if (application.executionResults.operatedVelocity > 0)
            {
                printf("%d\n", application.executionResults.operatedVelocity);

                if (application.executionResults.upwardsMovement) 
                {
                    application.ball.y -= (double)application.executionResults.operatedVelocity;
                    application.executionResults.operatedVelocity -= (int)application.executionResults.gravity;  
                }else
                {
                    application.ball.y += (double)application.executionResults.operatedVelocity;
                    application.executionResults.operatedVelocity += (int)application.executionResults.gravity; 

                    if (application.ball.y > application.windowHeight - application.ball.radius)
                    {
                        application.executionResults.operatedVelocity = 0;
                    }
                }
            }
            else if (application.executionResults.operatedVelocity <= 0) 
            {
                if (!application.executionResults.upwardsMovement && application.executionResults.initialVelocity > 1)
                {
                    application.executionResults.initialVelocity = application.executionResults.initialVelocity / 1.1;
                }

                application.executionResults.upwardsMovement = !application.executionResults.upwardsMovement;
                
                if (application.executionResults.upwardsMovement)
                {
					application.executionResults.operatedVelocity = application.executionResults.initialVelocity;
				}else
				{
					application.executionResults.operatedVelocity = application.executionResults.initialVelocity / 2;
				}
				

                if (application.executionResults.initialVelocity <= 1)
                {
                    application.hasSimStarted = false;
                }
            }

            application.startButton.text = "Stop";

        }else
        {
            application.ball.y = application.windowHeight - application.ball.radius;
            application.startButton.text = "Start";
        }

        GenerateBall(application.ball, application.appRenderer);

        if ((mouseState &SDL_BUTTON_LMASK) != 0 && IsHoveringButton(	application.mouseX, 
																		application.mouseY, 
																		application.startButton))
        {
            GenerateButton(	application.appFont, 
							application.appRenderer, 
							&application.startButton, false);
        }
        else
        {
            GenerateButton(	application.appFont, application.appRenderer, 
							&application.startButton, 
							IsHoveringButton(	application.mouseX, 
												application.mouseY, 
												application.startButton));
        }


        if ((mouseState &SDL_BUTTON_LMASK) != 0 && IsHoveringButton(application.mouseX, 
																	application.mouseY, 
																	application.exitButton))
        {
            GenerateButton(	application.appFont, 
							application.appRenderer, 
							&application.exitButton, false);
        }
        else
        {
            GenerateButton(	application.appFont, 
							application.appRenderer, 
							&application.exitButton, 
							IsHoveringButton(	application.mouseX, 
												application.mouseY, 
												application.exitButton));
        }

        SDL_SetRenderDrawColor(	application.appRenderer, 0x55, 0x55, 0x66, 0xAA);	
        SDL_RenderPresent(application.appRenderer);										

        endTick = SDL_GetTicks();

        if (application.interiorTextBox.isEnabled)
        {
            cursorTimer += (endTick-startTick)/1000;
        }

        //deltaTime = (endTick-startTick)/1000;
        
    }

    ExitApplication(&application);
    return EXIT_SUCCESS;
}

