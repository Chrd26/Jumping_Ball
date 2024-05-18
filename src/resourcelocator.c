#include "resourcelocator.h"

char* FindResource(char *fileLocation)
{
	char *execPath; 
	unsigned int lengthValue = 1024;
	getBundlePath(&execPath, &lengthValue);
	strcat(execPath, fileLocation);
	return execPath;
}
