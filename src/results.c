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
    double g = 9.8;

    if (getValue > 100)
    {
        results.maxHeight = 0;
        results.timeToMaximumHeight = 0;
        results.timeToLand = 0;
        results.doResultsExist = false;
        return results;
    }

    for (int i = 0; i < 3; i++)
    {

        switch(i)
        {
            case 0:
                results.maxHeight = pow((double)getValue, 2) / g; 
                break;
            case 1:
                results.timeToMaximumHeight = (double)getValue / g;
                break;
            case 2:
                results.timeToLand = pow(results.maxHeight/g, 2); 
                break;
        }
    }

    results.doResultsExist = true;

    return results;
}
