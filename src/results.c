#include "results.h"


void GetResults(char *location, char *value)
{
	struct Results results;
	char *commandPartFirst = "cd ";
	char *commandPartSecond = "&& fpm run -- ";
	char *command = calloc(	strlen(location) + strlen(value) + strlen(commandPartFirst) + strlen(commandPartSecond), 
													sizeof(char));
	printf("%s\n", command);
	strcpy(command, commandPartFirst);
	printf("%s\n", command);
	strcat(command, location);
	printf("%s\n", command);
	strcat(command, commandPartSecond);
	printf("%s\n", command);
	strcat(command, value);
	printf("%s\n", command);
	
	int getSystemInfo = system(command);
	printf("%d\n", getSystemInfo);
}
