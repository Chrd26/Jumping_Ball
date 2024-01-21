#include "game.h"

int main()
{
    int systemCode = std::system("../jumpcalculations/app/output && rm calculations.csv");

    if (systemCode != 0)
    {
        std::cout << "Failed to remove CSV file or doesn't exist." << std::endl;
    }

    Game game;

    return 0;
}
