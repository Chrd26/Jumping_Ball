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
    int initialVelocity;
    int operatedVelocity;
    double gravity = 9.8;
    bool doResultsExist;
};


const char* GetField(char* line, int num);
struct Results GetResults(char *value);
