#include "results.h"
// Special thanks to the following SO post for providing a very nice solution
// https://stackoverflow.com/questions/12911299/read-csv-file-in-c

struct Results GetResults(char *location, char *value)
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
    printf("%s\n", csvLocation);
													
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
        char *stopFirstString;
        char *stopSecondString;
        char *stopThirdString;
        printf("Get Result 1: %s\n", GetField(temp, 0));
        printf("Get Result 2: %s\n", GetField(temp, 1));
        printf("Get Result 3: %s\n", GetField(temp, 2));
        results.maxHeight = strtod(GetField(temp, 0), &stopFirstString);
        results.timeToMaximumHeight = strtod(GetField(temp, 1), &stopSecondString);
        results.timeToLand = strtod(GetField(temp, 2), &stopThirdString);

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
