#include "results.h"
// Special thanks to the following SO post for providing a very nice solution
// https://stackoverflow.com/questions/12911299/read-csv-file-in-c
// Strings, pointers, and going out of scope:
// https://stackoverflow.com/questions/32652050/mutating-array-of-char-using-a-function-but-string-values-change-after-function

struct Results GetResults(const char **location, char *value)
{
	struct Results results;
    const char *getLocation = *location;
    printf("Get Location: %s\n", getLocation);
	char *commandPartFirst = "cd ";
	char *commandPartSecond = " && fpm run -- ";
	char *command = calloc(	strlen(getLocation) + strlen(value) + strlen(commandPartFirst) + strlen(commandPartSecond), 
													sizeof(char));

    printf("Input location: %s\n", getLocation);
    char *contentsCSV = "/app/output/calculations.csv";
    char *csvLocation = calloc(strlen(getLocation) + strlen(contentsCSV), sizeof(char));
    strcpy(csvLocation, getLocation);
    strcat(csvLocation, contentsCSV);
    printf("%s\n", csvLocation);
													
	strcpy(command, commandPartFirst);
	strcat(command, getLocation);
	strcat(command, commandPartSecond);
	strcat(command, value);
	
	int getSystemInfo = system(command);

    if (getSystemInfo != 0)
    {
        printf("Something went wrong!\n");
        results.maxHeight = 0;
        results.timeToMaximumHeight = 0;
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
        char *endString;
        printf("Get Result 1: %s\n", GetField(temp, 0));
        results.maxHeight = strtod(GetField(temp, 0), &endString);
        results.timeToMaximumHeight = strtod(GetField(temp, 1), &endString);
        results.timeToLand = strtod(GetField(temp, 2), &endString);

        free(temp);
    }

	printf("%s\n", command);
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
