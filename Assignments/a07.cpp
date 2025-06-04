/******************************************************************************
# Author:         Cameron Kuykendall
# Date:           May 4, 2025
# Description:    This program takes two integers and uses pointer-based functions
                 to swap them, divide them, and raise one to the power of the other.
#
# Input:          Two integers entered by the user (a, b)
# Output:         Intermediate and final results after calling:
#                   - swapArgs: swaps a and b
#                   - divideArgs: sets a to quotient, b to remainder
#                   - powerArgs: raises a to the power of b
******************************************************************************/

#include <iostream>

using namespace std;

// Prototypes
void swapArgs(int *, int *);
void divideArgs(int *, int *);
void powerArgs(int *, int *);
void readInt(int &a, int &b);

int main()
{
    int a;
    int b;

    readInt(a, b);
    if (a == 0 && b == 0)
    {
        cout << "\nNo operations performed!" << endl;
        return 0;
    }
    cout << "Before call to swapArgs a: " << a << " b: " << b << endl;
    swapArgs(&a, &b);
    divideArgs(&a, &b);
    powerArgs(&a, &b);

    cout << "\nGoodbye!" << endl;

    return 0;
}

// Reads two validated integers from user input by reference
void readInt(int &a, int &b)
{
    cout << "Enter integer 1: ";
    cin >> a;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Error: Please Re-enter integer 1: ";
        cin >> a;
    }
    // clear cin for decimals / leftovers
    cin.ignore(100, '\n');

    cout << "Enter integer 2: ";
    cin >> b;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Error: Please Re-enter integer 2: ";
        cin >> b;
    }
    // clear cin for decimals / leftovers
    cin.ignore(100, '\n');
}

// Swaps the values pointed to by a and b
void swapArgs(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

    cout << "After call to swapArgs a: " << *a << " b: " << *b << endl;
}

// Performs integer division: stores quotient in a and remainder in b
void divideArgs(int *a, int *b)
{
    int temp = *a / *b;
    *b = *a % *b;
    *a = temp;
    cout << "After call to divideArgs a: " << *a << " b: " << *b << endl;
}

// Raises a to the power of b and stores result in a (ignores negatives)
void powerArgs(int *a, int *b)
{
    if (*b == 0)
    {
        *a = 1;
    }
    else
    {
        int base = *a;
        for (int i = 0; i < *b - 1; i++)
        {
            *a *= base;
        }
    }

    cout << "After call to powerArgs is a: " << *a << " b: " << *b << endl;
}
