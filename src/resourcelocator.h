#pragma once
#include <stdio.h>
#include <string.h>
#include <liblocate/liblocate.h>

typedef struct Resource
{
   const char *location;
}Resource;

char* FindResource(const char *fileLocation);
