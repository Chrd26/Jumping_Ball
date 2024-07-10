#include "results.h"
// Special thanks to the following SO post for providing a very nice solution
// https://stackoverflow.com/questions/12911299/read-csv-file-in-c
// Strings, pointers, and going out of scope:
// https://stackoverflow.com/questions/32652050/mutating-array-of-char-using-a-function-but-string-values-change-after-function

struct Results GetResults(char *value)
{
    struct Results results;
    if (value == NULL || value[0] == '\0')
    {
        results.maxHeight = 0;
        results.timeToMaximumHeight = 0;
        results.timeToLand = 0;
        results.doResultsExist = false;
        return results;
    }

    int getValue = atoi(value);

    if (getValue > 100)
    {
        results.maxHeight = 0;
        results.timeToMaximumHeight = 0;
        results.timeToLand = 0;
        results.doResultsExist = false;
        return results;
    }

    results.initialVelocity = getValue;
    results.operatedVelocity = results.initialVelocity;
    results.gravity = 9.8;
    results.timeToLand = pow(results.maxHeight / results.gravity, 2); 
    results.timeToMaximumHeight = (double)results.initialVelocity / results.gravity;
    results.maxHeight = pow((double)results.initialVelocity, 2) / results.gravity; 
    results.doResultsExist = true;
    results.upwardsMovement = true; 

    return results;
}
