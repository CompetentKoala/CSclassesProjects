/******************************************************************************
# Author:           Cameron Kuykendall
# Assignment:       A02
# Date:             April 3, 2025
# Description:      This function generates an encoded file name for a D2L submission
                    using user input including name, lateness, student ID, time, and file name.

# Input:            fName – char array – User’s first name
                    lName – char array – User’s last name
                    lateFlag – bool – Whether the assignment was submitted late
                    parsedID – char array – Last 4 digits of student ID
                    strTime – char array – Submission time in HHMM format
                    fileName – char array – Original file name provided by the user

# Output:           encodeFileName – char array – The complete encoded file name formatted as:
                    lastname_firstname[_LATE]_ID_time_filename

# Specifications:   A02 grade A specifications
******************************************************************************/

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

void welcome();
void encode(char encodeFileName[]);
void displayMenu();
void readOption(char &option);
void encode(char encodeFileName[]);
void readInput(char fName[], char lName[], bool &lateFlag);
void readInput(char parsedID[], char fileName[]);
void readTime(char strTime[]);
void cStringLowerCase(char cString[]);

// MAIN FUNCTION
int main()
{
    char option;
    char encodeFileName[50];

    // Prints a welcome message to the user when the program starts.
    welcome();

    // While option is not q, loop through these steps
    do
    {
        // Displays the main menu with two options: encode a file name or quit.
        displayMenu();

        // Reads the user's menu choice, validates that it is either 'e' or 'q',
        // and converts it to lowercase if needed.
        readOption(option);
        if (option == 'q')
        {
            cout << "\nThank you for using my fileName generator!" << endl;
            return 0;
        }
        else
        {
            // reads all inputs and properly encodes the file name in proper manner
            // Calls readInput, readInput (overload), and read time.
            encode(encodeFileName);
        }

        // Display properly encoded file
        cout << "\nYour encoded file name is: " << encodeFileName << endl;
    } while (option != 'q');

    // Exit message and exit program

    return 0;
}

// Prints a welcome message to the user when the program starts.
void welcome()
{
    cout << "Welcome to my fileName encoding program!!" << endl;
}

// Displays the main menu with two options: encode a file name or quit.
void displayMenu()
{
    cout << "\nPlease pick an option below:" << endl;
    cout << "(e)Encode a file name" << endl;
    cout << "(q)quit" << endl;
}

// Reads the user's menu choice, validates that it is either 'e' or 'q',
// and converts it to lowercase if needed.
void readOption(char &option)
{
    cout << ">>";
    cin >> option;
    option = tolower(option);

    while ((cin.fail()) ||
           (option != 'e' &&
            option != 'q'))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "\nInvalid option! Please try again!!" << endl;
        displayMenu();
        cin >> option;
    }
}

// Gathers all required input data, assembles the encoded file name using
// C-string functions, and stores it in encodeFileName.
void encode(char encodeFileName[])
{
    bool lateFlag;
    char fName[50], lName[50], parsedID[50], fileName[50], strTime[5];
    int i;

    cout << "This program will ask you a few questions and generate\n"
         << "an encoded fileName based on your answers.\n " << endl;

    readInput(fName, lName, lateFlag);
    readInput(parsedID, fileName);
    readTime(strTime);

    strncpy(encodeFileName, lName, 50);
    strcat(encodeFileName, "_");
    strcat(encodeFileName, fName);
    strcat(encodeFileName, "_");
    if (lateFlag == 1)
    {
        strcat(encodeFileName, "LATE");
        strcat(encodeFileName, "_");
    }
    strcat(encodeFileName, parsedID);
    strcat(encodeFileName, "_");
    strcat(encodeFileName, strTime);
    strcat(encodeFileName, "_");
    strcat(encodeFileName, fileName);
}

// Reads the user's first and last name and converts them to lowercase.
// Also asks if the assignment was late and stores the result as a boolean.
void readInput(char fName[], char lName[], bool &lateFlag)
{
    cin.clear();
    cin.ignore(5, '\n');
    char tempLateFlag;

    cout << "Enter your last name: ";
    cin.getline(lName, 50);
    cStringLowerCase(lName);

    cout << "\nEnter your first name: ";
    cin.getline(fName, 50);
    cStringLowerCase(fName);

    cout << "\nWas your assignment Late (y/n)? ";

    cin >> tempLateFlag;
    tempLateFlag = tolower(tempLateFlag);

    while ((cin.fail()) ||
           (tempLateFlag != 'y' &&
            tempLateFlag != 'n'))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "\nInvalid option! Please try again!!" << endl;
        cout << "Was your assignment Late (y/n)? ";
        cin >> tempLateFlag;
        tempLateFlag = tolower(tempLateFlag);
    }

    lateFlag = tempLateFlag == 'y' ? true : false;
    // This void function should take 2 char arrays and 1 bool variable by reference.
    // It reads the student’s first name, last name and if the assignment is late or not. Student last name (e.g. Smith) (char array). Student first name (e.g. Sue) (char array)
    // Make sure all character data for the student’s name is lowercase - you may write a function to convert a cstring to all lowercase.
    // If the assignment was late or not (e.g., Y or N) (bool var). Must do data validation for this.
    // Hint: Remember an overloaded function has the same function name but different types of parameters or the number of parameters are different.
}

// Reads the full student ID in the format ###-##-####, extracts the last 4 digits,
// and stores them in parsedID. Also reads the file name.
void readInput(char parsedID[], char fileName[])
{
    char studentId[50];

    cout << "\nEnter your Student-ID (format: 222-22-2222): ";
    cin >> studentId;
    while (strlen(studentId) != 11 || cin.fail())
    {
        cin.clear();
        cin.ignore(20, '\n');
        cout << "\nIncorrect length of ID. Please enter again: ";
        cin >> studentId;
    }

    cin.clear();
    cout << "\nEnter the file name: ";
    cin >> fileName;

    strncpy(parsedID, studentId + 7, 4);
    parsedID[4] = '\0';

    // This void function should take 1 char array for the parsed 4 digit Student ID that will be returned and another char array for the filename.
    // The Student ID (e.g., 977-15-5587) (char array) is a local variable.
    // Use the strncpy() function to copy from position 7 till the end of the string.
    // strncpy(parsedID, stdID + 7, 4) will copy 4 characters from the 7th position in the
    // stdID string to the parsedID string. Check out this example code file.
    // The name of the file (e.g., prog2.cpp) (char array)
}

// Reads the time of submission in HH:MM format, validates the input,
// and stores it in strTime as a 4-digit C-string with no colon.
void readTime(char strTime[])
{
    int hours;
    int minutes;
    char discard;

    cout << "\nEnter the time submitted (military time - ex: 18:24 for 6:24pm): ";
    cin >> hours >> discard >> minutes;

    while (cin.fail() || discard != ':' || hours < 0 || hours > 23 || minutes < 0 || minutes > 59)

    {
        cout << "\nInvalid Input." << endl;
        cout << "\nEnter the time submitted (military time - ex: 18:24 for 6:24pm): ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> hours >> discard >> minutes;
    }

    cin.ignore(100, '\n');
    if (hours < 10)
    {
        strcpy(strTime, "0");
        strcat(strTime, to_string(hours).c_str());
    }
    else
    {
        strcpy(strTime, to_string(hours).c_str());
    }
    if (minutes < 10)
    {
        strcat(strTime, "0");
        strcat(strTime, to_string(minutes).c_str());
    }
    else
    {
        strcat(strTime, to_string(minutes).c_str());
    }
    strTime[4] = '\0';
}

// Converts all characters in the given C-string to lowercase.
void cStringLowerCase(char cString[])
{
    int i;

    for (i = 0; cString[i] != '\0'; i++)
    {
        cString[i] = tolower(cString[i]);
    }
}
