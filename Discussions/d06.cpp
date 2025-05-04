/******************************************************************************
# Author:        Cameron Kuykendall
# Date:          May 3, 2025
# Description:   This program records and displays pet information provided
#                by the user. It prompts for basic details like animal type,
#                name, age, how long the pet has been owned, and how many
#                times it's fed daily. Input is validated and displayed back
#                in a clean summary.

# Input:         Animal type (string)
#                Pet name (string)
#                Age (int, years)
#                Years owned (int)
#                Times fed daily (int)

# Output:        A summary of all entered pet information, printed to console.
******************************************************************************/

#include <iostream>
#include <cstring>

using namespace std;

struct Pet
{
    char animalType[50];
    char name[50];
    int age;
    int yearsOwned;
    int timesFedDaily;
};

// Function Prototypes
void welcomeMessage();
void createPet(Pet &userPet);
void inputCharArray(char arr[], const char prompt[]);
void inputInt(int &value, const char prompt[]);
void printPet(const Pet &userPet);
void exitMessage();

int main()
{
    Pet userPet;

    welcomeMessage();
    createPet(userPet);
    printPet(userPet);
    exitMessage();

    return 0;
}

// Welcome message
void welcomeMessage()
{
    cout << "Welcome to the Pet Recorder program!" << endl;
    cout << "I will ask some questions about your pet, then save the information for you!\n"
         << endl;
}

// Exit message
void exitMessage()
{
    cout << "\nThanks for using the Pet Recorder! " << endl;
}

// Fill in pet details
void createPet(Pet &userPet)
{
    inputCharArray(userPet.animalType, "What type of animal is it (e.g., Cat, Dog, Elephant): ");
    inputCharArray(userPet.name, "What is your pet's name: ");
    inputInt(userPet.age, "How old are they (In years. decimals will round down *if under a year, enter 1*): ");
    inputInt(userPet.yearsOwned, "How long have they been in your life (In years, decimals will round down): ");
    inputInt(userPet.timesFedDaily, "How many times do you feed them a day (decimals will round down): ");
}

// Input helper for char arrays, take in a line for names longer than 1 word.
void inputCharArray(char arr[], const char prompt[])
{
    cout << prompt;
    cin.getline(arr, 50, '\n');
}

// Input helper for integers, validate for number values greater than 0
void inputInt(int &value, const char prompt[])
{
    cout << prompt;
    cin >> value;
    while (cin.fail() || value <= 0)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Error. Please enter integers(E.g. 2, 4, 14): ";
        cin >> value;
    }

    cin.ignore(100, '\n');
}

// print helper function
void printPet(const Pet &userPet)
{
    cout << "\n--- Pet Summary ---" << endl;
    cout << "Animal Type:       " << userPet.animalType << endl;
    cout << "Name:              " << userPet.name << endl;
    cout << "Age:               " << userPet.age << endl;
    cout << "Years Owned:       " << userPet.yearsOwned << endl;
    cout << "Times Fed Daily:   " << userPet.timesFedDaily << endl;
}
