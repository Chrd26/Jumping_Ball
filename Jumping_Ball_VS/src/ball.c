#include "ball.h"

void GenerateBall(struct Ball ball, SDL_Renderer *renderer)
{
	// Center of ball
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	
	// Generate center
	SDL_RenderPoint(renderer, ball.x, ball.y);							
	
	// special thanks 
	// https://math.stackexchange.com/questions/260096/find-the-coordinates-of-a-point-on-a-circle
	// https://www.sanfoundry.com/c-tutorials-various-trigonometric-functions-standard-library/
	for (float i = 0; i < 360; i += 1)
	{
		SDL_RenderPoint(renderer, (ball.radius * cos(i)) + ball.x, (ball.radius* sin(i)) + ball.y);
	}
}
