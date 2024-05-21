#include "results.h"
// Special thanks to the following SO post for providing a very nice solution
// https://stackoverflow.com/questions/12911299/read-csv-file-in-c
// Strings, pointers, and going out of scope:
// https://stackoverflow.com/questions/32652050/mutating-array-of-char-using-a-function-but-string-values-change-after-function

struct Results GetResults(const char *location, char *value)
{
	struct Results results;
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
        printf("Something went wrong!\n");
        results.maxHeight = 0;
        results.timeToMaximumHeight = 0;
        free(command);
        free(csvLocation);
        results.timeToLand = 0;
        return results;
    }

    FILE *file = fopen(csvLocation, "r");
    char line[1024];
    int counter = 0;

    while(fgets(line, 1024, file))
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
            printf("Copy: %s\n", toCopy);
            tempCopy = toCopy;
            char *endString;

            switch(i)
            {
                case 0:
                    results.maxHeight = strtod(getResult, &endString);
                    break;
                case 1:
                    results.timeToMaximumHeight = strtod(getResult, &endString);
                    break;
                case 2:
                    results.timeToLand = strtod(getResult, &endString);
                    break;
            }
        }
        break;
    }
    

    printf("Max Height: %f", results.maxHeight);
    printf("Time to max height: %f", results.timeToMaximumHeight);
    printf("Time to land: %f", results.timeToLand);

    free(command);
    free(csvLocation);
    fclose(file);
    return results;
}

const char* GetField(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}
