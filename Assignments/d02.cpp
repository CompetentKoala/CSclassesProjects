/******************************************************************************
# Author:           Cameron Kuykendall
# Assignment:       D02
# Date:             April 11, 2025
# Description:      Prompts the user for a word (letters only), a 4-digit number
                    (digits only), and a symbol (punctuation). Each input is
                    validated and combined into a strong password.

# Input:            userWord   – char[] – Letters only
                    userYear   – char[] – 4-digit number
                    userSymbol – char[] – One punctuation character

# Output:           Prompts and error messages for validation
                    Final assembled strong password

# Specifications:   D02 grade specifications
******************************************************************************/

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

// Constants
const int MAXCHAR = 20;

// Prototypes
void inputData(const string &prompt, char data[], int limit, int (*charCheck)(int));
void createPassword(char word[], char year[], char symbol[], char newPassword[]);

// Main Program
int main()
{

    // Declare Variables
    char userWord[MAXCHAR];
    char userYear[MAXCHAR];
    char userSymbol[MAXCHAR];
    char strongPassword[MAXCHAR * 3];

    // Welcome Message
    cout << "Welcome to the STRONG password creator!" << endl;

    // Input Data && validate each
    inputData("\nFirst, enter ONE word you will remember. It can be your name, a street name, anything you want!", userWord, MAXCHAR, isalpha);
    inputData("Next, enter a number you can remember. Limit this to a 4-digit number.", userYear, 5, isdigit);
    inputData("Finally, enter a symbol you can remember. Make sure it's on your keyboard.", userSymbol, 2, ispunct);

    // Combine the threee inputs into one
    createPassword(userWord, userYear, userSymbol, strongPassword);

    // Display strong password and Exit Message
    cout << "\nYour strong password is: " << strongPassword << endl;
    cout << "\nThanks for using the STRONG password creator!" << endl;

    return 0;
}

void inputData(const string &prompt, char data[], int limit, int (*charCheck)(int))
{
    bool valid = false;
    while (!valid)
    {
        // get input
        cout << prompt << endl;
        cin.getline(data, limit);

        // errors
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }
        // check if characters are the proper characters per input. EX. digit, alpha, punc.
        valid = true;
        for (int i = 0; data[i] != '\0'; ++i)
        {
            if (!charCheck(data[i]))
            {
                valid = false;
                break;
            }
        }
        // if not correct type, try again.
        if (!valid)
        {
            cout << "Invalid input. Please try again." << endl;
        }
    }
}

void createPassword(char word[], char year[], char symbol[], char newPassword[])
{
    strcpy(newPassword, word);
    strcat(newPassword, year);
    strcat(newPassword, symbol);
}
