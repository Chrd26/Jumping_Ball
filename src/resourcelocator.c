#include "resourcelocator.h"

char* FindResource(char *fileLocation)
{
	char *execPath; 
	getBundlePath(execPath);
	printf("%s\n", execPath);
	
	strcat(execPath, fileLocation);
	return execPath;
}
