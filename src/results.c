#include "results.h"
// Special thanks to the following SO post for providing a very nice solution
// https://stackoverflow.com/questions/12911299/read-csv-file-in-c

void GetResults(char *location, char *value)
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
        return;
    }

    FILE *file = fopen(csvLocation, "r");
    char line[1024];

    while(fgets(line, 1024, file))
    {
        char *temp = strdup(line);
        printf("Get Result 1: %s\n", GetField(temp, 2));
        free(temp);
    }


	printf("%s\n", command);
    free(command);
    free(csvLocation);
    fclose(file);
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
