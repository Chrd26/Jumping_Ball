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

            printf("Result: %s\n", getResult);
            free(getResult);
            char *endLine;

            switch(i)
            {
                case 0:
                    results.maxHeight = strtod(getResult, &endLine);
                    printf("Case 0\n");
                    break;
                case 1:
                    results.timeToMaximumHeight = strtod(getResult, &endLine);
                    printf("Case 1\n");
                    break;
                case 2:
                    results.timeToLand = strtod(getResult, &endLine);
                    printf("Case 2\n");
                    break;
            }

            printf("%d\n", i);
        }

    }

    printf("Exit\n");
    
    //printf("Max Height: %f\n", results.maxHeight);
    //printf("Time to max height: %f\n", results.timeToMaximumHeight);
    //printf("Time to land: %f\n", results.timeToLand);

    free(command);
    free(csvLocation);
    fclose(file);
    printf("Exit\n");
    return results;
}
