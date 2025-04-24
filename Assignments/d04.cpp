/******************************************************************************
# Author:           Cameron Kuykendall
# Assignment:       d04
# Date:             April 16, 2025
# Description:      This program shifts an array starting from a user-specified
#                   index. The result is a rearranged version of the original
#                   array printed to the screen.
#
# Input:            Integer array[], integer count, integer indexToShift
#
# Output:           Shifted version of the original array
******************************************************************************/

#include <iostream>
using namespace std;

// Function prototypes
void welcome();
void getUserInput(int array[], int &count, int &indexToShift);
void shiftToRight(int array[], int &count, int &indexToShift, int shiftedArray[]);
void printArray(int shiftedArray[], int &count);

int main()
{
    int array[50];         // original array
    int shiftedArray[50];  // shifted version of array
    int count, indexToShift;

    welcome();                                 // greet user
    getUserInput(array, count, indexToShift);  // get array and shift index
    shiftToRight(array, count, indexToShift, shiftedArray);  // do the shift
    printArray(shiftedArray, count);           // display result

    return 0;
}

// Displays welcome message
void welcome()
{
    cout << "Welcome to the shifting array program" << endl;
}

// Gets the array size, values, and shift index from user
void getUserInput(int array[], int &count, int &indexToShift)
{
    cout << "\nEnter the amount of numbers you want to enter in the array: ";
    cin >> count;

    // Prompt user to enter array values
    cout << "\nBegin entering the " << count << " numbers: " << endl;

    for (int i = 0; i < count; i++)
    {
        cin >> array[i];
        // Validate input
        while (cin.fail())
        {
            cout << "Invalid input: ";
            cin.clear();
            cin.ignore(100, '\n');
            cin >> array[i];
        }
    }

    // Get index to start shifting from
    cout << "\nEnter the index to start the shift: ";
    cin >> indexToShift;
}

// Rearranges array starting from indexToShift
void shiftToRight(int array[], int &count, int &indexToShift, int shiftedArray[])
{
    int shiftedArrayCount = 0;

    // Copy values from indexToShift to end
    for (int i = indexToShift; i < count; i++)
    {
        shiftedArray[shiftedArrayCount] = array[i];
        shiftedArrayCount++;
    }

    // Copy values from beginning to indexToShift - 1
    for (int i = 0; i < indexToShift; i++)
    {
        shiftedArray[shiftedArrayCount] = array[i];
        shiftedArrayCount++;
    }
}

// Displays the shifted array
void printArray(int shiftedArray[], int &count)
{
    cout << "\nThe shifted array is: ";
    for (int i = 0; i < count; i++)
    {
        cout << shiftedArray[i] << " ";
    }
    cout << endl;
}
