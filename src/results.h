#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

struct Results
{
	double maxHeight;
	double timeToMaximumHeight;
	double timeToLand;
    bool doResultsExist;
};


const char* GetField(char* line, int num);
struct Results GetResults(const char *location, char *value);
