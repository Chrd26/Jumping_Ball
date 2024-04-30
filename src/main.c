#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "app.h"

int main(void)
{
	double startTick = 0, endTick = 0;
	SDL_Event events;
	// double  frameTime = 0;
    int getCalcFile = system("test -f ../jumpcalculations/app/output/calculations.csv");
    printf("%d\n", getCalcFile);

    if (getCalcFile == 0)
    {
        getCalcFile = system("cd ../jumpcalculations/app/output && rm calculations.csv");

        if (getCalcFile != 0)
        {
            printf("Calculations CSV removal failed\n, %d", errno);
            exit(EXIT_FAILURE);
        }
    }

    // Execute Simulation
    
    if (!InitApp())
    {
		exit(EXIT_FAILURE);
	}
	
	bool quit = false;
	
	while(!quit)
	{
		// Start counting
		startTick = SDL_GetTicks();
		while(SDL_PollEvent(&events))
		{
			switch(events.type)
			{
				case SDL_EVENT_QUIT:
					quit = true;
					break;
			}
		}
		
		SDL_PumpEvents();
		SDL_SetRenderDrawColor(	appRenderer,
														0xAA, 0xAA, 0xFF, 0xFF);
		SDL_RenderClear(appRenderer);
		SDL_RenderPresent(appRenderer);
		
		endTick = SDL_GetTicks();
		// Get Time in Seconds
		// frameTime += (endTick-startTick)/1000;

	}
	
	
	ExitApplication();
    return EXIT_SUCCESS;
}

