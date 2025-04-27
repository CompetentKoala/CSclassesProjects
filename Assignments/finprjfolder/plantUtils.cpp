#include "plantUtils.h"

// Opens a file for reading plant data
int openFile(ifstream &plantData, char file[])
{
    plantData.open(file);
    if (!plantData.is_open())
    {
        cout << "Error: Couldn't find / read file\n";
        return 1;
    }
    return 0;
}

// Reads data from file into the plants array
void createDataArray(ifstream &plantData, Plant plants[MAXPLANTS], int &plantCount)
{
    while (plantData.getline(plants[plantCount].plantName, MAXCHAR, ';'))
    {
        plantData.getline(plants[plantCount].sunlightNeeded, MAXCHAR, ';');
        plantData >> plants[plantCount].wateringPerWeek;
        plantData.ignore(20, ';');
        plantData >> plants[plantCount].petSafe;
        plantData.ignore(20, ';');
        plantData.getline(plants[plantCount].notes, MAXNOTECHAR);
        plantCount++;
    }
}

// Displays the main menu options
void displayMenu()
{
    cout << "\nPlease choose an option from the menu below\n";
    cout << "(A)dd new plant\n(R)emove a plant\n(P)rint all plants\n(S)earch by sunlight\n(F)ind pet-safe plants\n(Q)uit\n>> ";
}

// Displays a welcome message
void welcome()
{
    cout << "\nWelcome to the plant collection program!\n";
}

// Handles the user's menu choice and calls the correct function
void chooseOption(char &choice, ifstream &plantDataIn, ostream &plantDataOut, Plant plants[MAXPLANTS], int &plantCount)
{
    cin >> choice;
    choice = toupper(choice);
    switch (choice)
    {
    case 'A':
        cout << "\nPlease enter the plant information below!\n";
        addPlant(plantDataIn, plants, plantCount);
        savePlantDataToFile("finprj.txt", plants, plantCount);
        break;
    case 'R':
        cout << "\nLet's remove a plant from the collection!\n";
        removePlant(plants, plantCount);
        savePlantDataToFile("finprj.txt", plants, plantCount);
        break;
    case 'P':
        cout << "\nHere is the list of the plants\n";
        printPlantArray(plantDataOut, plants, plantCount);
        break;
    case 'S':
        cout << "\nFind plants with similar sunlight requirements\n";
        searchSunlightAmount(plants, plantCount);
        break;
    case 'F':
        cout << endl;
        searchPetSafePlants(plants, plantCount);
        break;
    case 'Q':
        cout << "\nYou chose to QUIT!\n";
        cout << "\nThanks for using my final project Plant Collector!\n";
        break;
    default:
        cout << "Invalid input. Please enter: A, R, P, S, Q\n";
        cin.clear();
        break;
    }
}

// Adds a new plant with user input and validation
void addPlant(ifstream &plantData, Plant plants[MAXPLANTS], int &plantCount)
{
    if (plantCount >= MAXPLANTS)
    {
        cout << "Plant list is FULL.\n";
        return;
    }
    cin.ignore(100, '\n');
    cout << "\nWhat is the name of the plant: ";
    cin.getline(plants[plantCount].plantName, MAXCHAR);

    cout << "What type of sunlight does it need (full,partial,shade): ";
    cin.getline(plants[plantCount].sunlightNeeded, MAXCHAR);
    while (strcmp(plants[plantCount].sunlightNeeded, "full") != 0 && strcmp(plants[plantCount].sunlightNeeded, "partial") != 0 && strcmp(plants[plantCount].sunlightNeeded, "shade") != 0)
    {
        cout << "Invalid response. Please enter (full, partial, shade): ";
        cin.getline(plants[plantCount].sunlightNeeded, MAXCHAR);
    }

    cout << "How many times a week does it need watered: ";
    cin >> plants[plantCount].wateringPerWeek;
    while (cin.fail() || plants[plantCount].wateringPerWeek < 0 || plants[plantCount].wateringPerWeek > 7)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid number. Please enter 0 - 7: ";
        cin >> plants[plantCount].wateringPerWeek;
    }

    cin.ignore(100, '\n');
    cout << "Is it pet safe (y/n): ";
    cin >> plants[plantCount].petSafe;
    plants[plantCount].petSafe = toupper(plants[plantCount].petSafe);
    while (plants[plantCount].petSafe != 'Y' && plants[plantCount].petSafe != 'N')
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input. (Please enter y/n): ";
        cin >> plants[plantCount].petSafe;
        plants[plantCount].petSafe = toupper(plants[plantCount].petSafe);
    }

    cin.ignore(100, '\n');
    cout << "Any additional notes? (limit to 40 characters): ";
    cin.getline(plants[plantCount].notes, MAXNOTECHAR);

    plantCount++;
    cout << "\nPlant Added!\n";
}

// Removes a plant by name and shifts the array
void removePlant(Plant plants[MAXPLANTS], int &plantCount)
{
    char plantToRemove[MAXCHAR];
    bool found = false;

    cout << "\nType the name of the plant you wish to remove exactly as it was entered: ";
    cin.ignore(100, '\n');
    cin.getline(plantToRemove, MAXCHAR);

    int i = 0;
    while (i < plantCount && !found)
    {
        if (strcmp(plants[i].plantName, plantToRemove) == 0)
        {
            for (int j = i; j < plantCount - 1; j++)
            {
                plants[j] = plants[j + 1];
            }
            plantCount--;
            found = true;
        }
        else
        {
            i++;
        }
    }

    if (found)
    {
        cout << "\nThe " << plantToRemove << " was removed from the list\n";
    }
    else
    {
        cout << "\nThe " << plantToRemove << " plant was not found!\n";
    }
}

// Prints the full list of plants in table format
void printPlantArray(ostream &plantData, Plant plants[MAXPLANTS], int plantCount)
{
    cout << setw(21) << left << "\nPlant Name" << setw(12) << "Sunlight" << setw(10)
         << "Water" << setw(18) << "Pet Safe" << "Notes\n";
    cout << setfill('-') << setw(90) << "-" << setfill(' ') << endl;
    for (int i = 0; i < plantCount; i++)
    {
        cout << setw(20) << left << plants[i].plantName;
        cout << setw(14) << plants[i].sunlightNeeded;
        cout << setw(11) << plants[i].wateringPerWeek;
        cout << setw(10) << plants[i].petSafe;
        cout << plants[i].notes << endl;
    }
}

// Searches and prints plants matching the sunlight type
void searchSunlightAmount(Plant plants[MAXPLANTS], int &plantCount)
{
    char sunlightType[MAXCHAR];
    cout << "\nWhat type of sunlight? (full, partial, shade): ";
    cin >> sunlightType;
    while (strcmp(sunlightType, "full") != 0 && strcmp(sunlightType, "partial") != 0 && strcmp(sunlightType, "shade") != 0)
    {
        cout << "Invalid response. Try again: ";
        cin >> sunlightType;
    }

    cout << "\nHere are plants that need " << sunlightType << " sunlight:\n";
    for (int i = 0; i < plantCount; i++)
    {
        if (strcmp(plants[i].sunlightNeeded, sunlightType) == 0)
        {
            cout << setw(20) << left << plants[i].plantName;
            cout << setw(14) << plants[i].sunlightNeeded;
            cout << setw(11) << plants[i].wateringPerWeek;
            cout << setw(10) << plants[i].petSafe;
            cout << plants[i].notes << endl;
        }
    }
}

// Displays all plants that are safe for pets
void searchPetSafePlants(Plant plants[MAXPLANTS], int &plantCount)
{
    cout << "\nHere are the pet-safe plants:\n";
    cout << setw(21) << left << "\nPlant Name" << setw(12) << "Sunlight" << setw(10)
         << "Water" << setw(18) << "Pet Safe" << "Notes\n";
    cout << setfill('-') << setw(90) << "-" << setfill(' ') << endl;
    for (int i = 0; i < plantCount; i++)
    {
        if (plants[i].petSafe == 'Y')
        {
            cout << setw(20) << left << plants[i].plantName;
            cout << setw(14) << plants[i].sunlightNeeded;
            cout << setw(11) << plants[i].wateringPerWeek;
            cout << setw(10) << plants[i].petSafe;
            cout << plants[i].notes << endl;
        }
    }
}

// Saves the current plant data back to a file
void savePlantDataToFile(const char filename[], Plant plants[MAXPLANTS], int plantCount)
{
    ofstream outFile(filename);
    if (!outFile.is_open())
    {
        cout << "Error: could not write to file." << endl;
        return;
    }

    for (int i = 0; i < plantCount; ++i)
    {
        outFile << plants[i].plantName << ";"
                << plants[i].sunlightNeeded << ";"
                << plants[i].wateringPerWeek << ";"
                << plants[i].petSafe << ";"
                << plants[i].notes << endl;
    }

    outFile.close();
}
