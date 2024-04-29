#pragma once
#include <stdio.h>
#include <string.h>
#include <liblocate/liblocate.h>

typedef struct Resource
{
	char *location;
};

char* FindResource(char *fileLocation);
