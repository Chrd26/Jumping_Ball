#include "game.h"

int main()
{
    int systemCode = std::system("test -f ../jumpcalculations/app/output/calculations.csv");

    if (systemCode == 0)
    {
        std::system("cd ../jumpcalculations/app/output && rm calculations.csv");
    }

    Game game;

    return 0;
}
