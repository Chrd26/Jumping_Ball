#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(void)
{
    int getCalcFile = system("test -f ../jumpcalculations/app/output/calculations.csv");
    printf("%d\n", getCalcFile);

    if (getCalcFile == 0)
    {
        getCalcFile = system("cd ../jumpcalculations/app/output && rm calculations.csv");

        if (getCalcFile != 0)
        {
            printf("Calculations CSV removal failed\n, %d", errno);
            exit(EXIT_FAILURE);
        }
    }


    // Execute Simulation


    return EXIT_FAILURE;
}

