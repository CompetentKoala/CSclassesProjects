#ifndef PLANTUTILS_H
#define PLANTUTILS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cctype>

using namespace std;

const int MAXCHAR = 100;
const int MAXNOTECHAR = 40;
const int MAXPLANTS = 50;

struct Plant
{
    char plantName[MAXCHAR];
    char sunlightNeeded[MAXCHAR];
    int wateringPerWeek;
    char petSafe;
    char notes[MAXNOTECHAR];
};

// Function Prototypes
int openFile(ifstream &plantData, char file[]);
void createDataArray(ifstream &plantData, Plant plants[MAXPLANTS], int &plantCount);
void displayMenu();
void welcome();
void chooseOption(char &choice, ifstream &plantDataIn, ostream &plantDataOut, Plant plants[MAXPLANTS], int &plantCount);
void addPlant(ifstream &plantData, Plant plants[MAXPLANTS], int &plantCount);
void removePlant(Plant plants[MAXPLANTS], int &plantCount);
void searchSunlightAmount(Plant plants[MAXPLANTS], int &plantCount);
void searchPetSafePlants(Plant plants[MAXPLANTS], int &plantCount);
void printPlantArray(ostream &plantData, Plant plants[MAXPLANTS], int plantCount);
void savePlantDataToFile(const char filename[], Plant plants[MAXPLANTS], int plantCount);

#endif
