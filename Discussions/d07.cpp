/******************************************************************************
# Author:           Cameron Kuykendall
# Assignment:       Pointer Vocabulary Program
# Date:             May 27, 2025
# Description:      This program presents a menu to the user explaining the
#                   different uses of the asterisk (*) in C++ programming,
#                   including variable declaration, dereferencing, arithmetic,
#                   function pointers, and pointer to pointer syntax.
#                   The user can select a menu option to learn more about each
#                   usage, or quit the program.
# Input:            A single character corresponding to a menu option (1–5, Q)
# Output:           Explanations of pointer-related concepts in C++
******************************************************************************/

#include <iostream>

using namespace std;

// Prints the welcome message
void welcomeMessage();

// Displays the main menu
void displayMenu();

// Gets validated user input (single character)
void getUserInput(char &userInput);

// Shows the explanation for the selected menu option
void displaySelectedOption(char userInput);

int main()
{
    char userInput;

    welcomeMessage();

    while (userInput != 'Q')
    {
        displayMenu();
        getUserInput(userInput);
        displaySelectedOption(userInput);
    }

    cout << "Thanks for using the program! BYE!" << endl;
    return 0;
}

// Prints the welcome message to the user
void welcomeMessage()
{
    cout << "Welcome to the pointer vocabulary program!" << endl;
    cout << "Select a menu option below to learn about each use of '*' in c++" << endl;
}

// Outputs the menu options
void displayMenu()
{
    cout << "\n1. Variable declaration" << endl;
    cout << "2. Dereferencing" << endl;
    cout << "3. Arithmetic" << endl;
    cout << "4. Function return/param type" << endl;
    cout << "5. Pointer to pointer" << endl;
    cout << "Q. Quit the program" << endl;
}

// Prompts user for a single character input and validates it
void getUserInput(char &userInput)
{
    char userChar;

    while (true)
    {
        cout << "\n>> ";
        cin >> userChar;

        if (cin.peek() == '\n') // user pressed Enter right after one char
        {
            userInput = toupper(userChar);
            break;
        }
        else
        {
            cout << "Please enter only one character." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}

// Displays the explanation for the selected option
void displaySelectedOption(char userInput)
{
    switch (userInput)
    {
    case '1':
        cout << "\nThis use is for Declaring a pointer" << endl;
        cout << "Example: int* ptr;" << endl;
        break;
    case '2':
        cout << "\nThis use is for Accessing a value at pointer address" << endl;
        cout << "Example: *ptr = 5;" << endl;
        break;
    case '3':
        cout << "\nThis use is for using '*' to multiply values" << endl;
        cout << "Example: a * b" << endl;
        break;
    case '4':
        cout << "\nThis use is for pointing to a function" << endl;
        cout << "Example: int* foo()" << endl;
        break;
    case '5':
        cout << "\nThis use is for pointing to another pointer (multiple layers)" << endl;
        cout << "Example: int** ptr2;" << endl;
        break;
    case 'Q':
        break;

    default:
        cout << "You did not enter a correct menu item!" << endl;
        break;
    }
}
