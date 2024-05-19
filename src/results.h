#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Results
{
	double maxHeight;
	double timeToMaximumHeight;
	double timeToLand;
};


const char* GetField(char* line, int num);
struct Results GetResults(const char **location, char *value);
