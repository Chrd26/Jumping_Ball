#include "resourcelocator.h"

char* FindResource(char *fileLocation)
{
	char *execPath; 
	getBundlePath(execPath);
	
	strcat(fileLocation, execPath);
	return fileLocation;
}
