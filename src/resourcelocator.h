#pragma once
#include <stdio.h>
#include <string.h>
#include <liblocate/liblocate.h>

typedef struct Resource
{
   char location[1024];
}Resource;

char* FindResource(const char *fileLocation);
