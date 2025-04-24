/******************************************************************************
# Author:           Cameron Kuykendall
# Assignment:       d03
# Date:             April 16, 2025
# Description:      This program allows the user to enter a list of integers
#                   and then checks whether a specified range within the list
#                   is sorted in acesnding order. It outputs "yes" if the
#                   range is sorted, and "no" if not.
#
# Input:            Integer count (number of values to input)
#                   A list of integers
#                   Two index values (start and end) for the range to check
#
# Output:           "yes" if the specified range is sorted
#                   "no" if the specified range is not sorted
******************************************************************************/

#include <iostream>
using namespace std;

// FUNCTION PROTOTYPES
void welcomeMessage();
void getUserInput(int arr[], int &count);
void getRange(int count, int &startIndex, int &endIndex);
bool isSorted(int arr[], int startIndex, int endIndex);

int main()
{
    int userInts[20];
    int count, startIndex, endIndex;

    welcomeMessage();
    getUserInput(userInts, count);
    getRange(count, startIndex, endIndex);

    if (isSorted(userInts, startIndex, endIndex))
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }

    return 0;
}

// WELCOME MESSAGE
void welcomeMessage()
{
    cout << "Welcome to the \"Is It Sorted?\" Program" << endl;
}

// GET INTEGER COUNT AND VALUES (WITH VALIDATION)
void getUserInput(int arr[], int &count)
{
    cout << "Enter the number of integers you want to enter (1–20): ";
    cin >> count;

    while (cin.fail() || count < 1 || count > 20)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input. Please enter an integer between 1 and 20: ";
        cin >> count;
    }

    cout << "Please enter " << count << " integers, separated by a space: ";
    for (int i = 0; i < count; i++)
    {
        cin >> arr[i];
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid input. Please enter a valid integer: ";
            cin >> arr[i];
        }
    }
}

// GET RANGE WITH BOUNDS CHECKING
void getRange(int count, int &startIndex, int &endIndex)
{
    cout << "Enter the start and end index of the values to check for sorted (e.g. 0 2): ";
    cin >> startIndex >> endIndex;

    while (cin.fail() || startIndex < 0 || endIndex >= count || startIndex > endIndex)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input. Index must be between 0 and " << count - 1
             << " and start <= end. Try again: ";
        cin >> startIndex >> endIndex;
    }
}

// CHECK IF RANGE IS SORTED
bool isSorted(int arr[], int startIndex, int endIndex)
{
    for (int i = startIndex; i < endIndex; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}
