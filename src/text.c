#include "text.h"

bool TextComponentInit(Resource *resource)
{
	int getValue = TTF_Init();
	
	if (getValue != 0)
	{
		printf("Failed to load TTF, %s", TTF_GetError());
		return false;
	}
	
	// load font
	resource->location = FindResource(resource->location);
	return true;
}


