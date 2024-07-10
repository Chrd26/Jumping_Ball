#include "resourcelocator.h"

char* FindResource(const char *fileLocation)
{
	char *execPath; 
	unsigned int lengthValue = 2048;
	getBundlePath(&execPath, &lengthValue);
	strcat(execPath, fileLocation);
	return execPath;
}
