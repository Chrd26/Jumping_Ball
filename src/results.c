#include "results.h"
// Special thanks to the following SO post for providing a very nice solution
// https://stackoverflow.com/questions/12911299/read-csv-file-in-c
// Strings, pointers, and going out of scope:
// https://stackoverflow.com/questions/32652050/mutating-array-of-char-using-a-function-but-string-values-change-after-function

struct Results GetResults(const char *location, char *value)
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

	char *commandPartFirst = "cd ";
	char *commandPartSecond = " && fpm run -- ";
	char *command = calloc(	strlen(location) + strlen(value) + strlen(commandPartFirst) + strlen(commandPartSecond), 
                            sizeof(char));

    char *contentsCSV = "/app/output/calculations.csv";
    char *csvLocation = calloc(strlen(location) + strlen(contentsCSV), sizeof(char));
    strcpy(csvLocation, location);
    strcat(csvLocation, contentsCSV);
													
	strcpy(command, commandPartFirst);
	strcat(command, location);
	strcat(command, commandPartSecond);
	strcat(command, value);
	
	int getSystemInfo = system(command);

    if (getSystemInfo != 0)
    {
        results.maxHeight = 0;
        results.timeToMaximumHeight = 0;
        results.timeToLand = 0;
        results.doResultsExist = false;
        free(command);
        free(csvLocation);
        exit(-1);
    }

    FILE *file = fopen(csvLocation, "r");
    char line[1024];
    int counter = 0;

    if (file == NULL)
    {
        printf("Failed to open file\n");
        exit(EXIT_FAILURE);
    }

    while(fgets(line, sizeof(line), file) != NULL)
    {
        if (counter == 0)
        {
            counter++;
            continue;
        }

        char *temp = strdup(line);
        char *separatedValues;
        char *tempCopy = temp;

        // Separate results
        // Read more : 
        // https://stackoverflow.com/questions/6205195/given-a-starting-and-ending-indices-how-can-i-copy-part-of-a-string-in-c
        for (int i = 0; i < 3; i++)
        {
            char *characterLoc = strchr(tempCopy, ',');
            size_t index  = (size_t)(characterLoc - tempCopy);
            char *toCopy = calloc(strlen(tempCopy) - index, sizeof(char));
            char *getResult = calloc(index, sizeof(char));
            strncpy(getResult, tempCopy, index);
            strncpy(toCopy, tempCopy + index + 1, strlen(tempCopy )- index);
            tempCopy = toCopy;
            char *endString;

            switch(i)
            {
                case 0:
                    //results.maxHeight = atof(&getResult[0]);
                    results.maxHeight = strtod(getResult, &endString) * 1/2 * 9.8; 
                    break;
                case 1:
                    //results.timeToMaximumHeight = atof(&getResult[0]);
                    results.timeToMaximumHeight = strtod(getResult, &endString) / 9.8;
                    break;
                case 2:
                    //results.timeToLand = atof(&getResult[0]);
                    results.timeToLand = pow(2 * results.maxHeight/9.8), 2; 
                    break;
            }
            free(getResult);
        }
    }

    results.doResultsExist = true;

    free(command);
    free(csvLocation);
    fclose(file);
    return results;
}
