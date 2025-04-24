#include "plantUtils.h"

int main()
{
    Plant plants[MAXPLANTS];
    ifstream plantDataIn;
    ofstream plantDataOut;
    char file[MAXCHAR] = "finprj.txt";
    char choice;
    int plantCount = 0;

    openFile(plantDataIn, file);
    createDataArray(plantDataIn, plants, plantCount);

    welcome();

    while (!cin.fail() && !(choice == 'Q'))
    {
        displayMenu();
        chooseOption(choice, plantDataIn, plantDataOut, plants, plantCount);
    }

    return 0;
}
