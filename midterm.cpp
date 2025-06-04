/**************************************************************
# Author:         Cameron Kuykendall
# Date:           May 4, 2025
# Assignment:     MiDTERM
# Description:    A simple queue program that lets
                 the user add (+) or remove (-) values from
                  a fixed-size
                   queue. Prints the queue after each action
                   and shows errors for overflow or missing values.

# Inputs:
#   - userInput: char ('+' to enqueue, '-' to dequeue, 'q' to quit)
#   - val:       int value entered by the user

# Outputs:
#   - Error messages if queue is full, empty, or value not found
#   - Updated queue printed to the console after each operation
**************************************************************/

#include <iostream>
using namespace std;

// Function declarations
int enqueue(int queue[], int &size, int val);  // Adds a value to the end of the queue
int dequeue(int queue[], int &size, int &val); // Removes all values up to and including a match
void printQueue(int queue[], int size);        // Prints current queue contents

const int MAX = 3; // Maximum number of elements in the queue

int main()
{
    int queue[MAX];
    int size = 0;
    char userInput;
    int val;

    // Prompt user for first action
    cout << "Enter option: ";
    cin >> userInput;

    // Main loop continues until user enters 'q'
    while (userInput != 'q')
    {
        if (userInput == '+')
        {
            enqueue(queue, size, val); // ADD VAL
        }
        else if (userInput == '-')
        {
            dequeue(queue, size, val); // REMOV. VAL
        }
        else
        {
            cout << "invalid option" << endl;
            printQueue(queue, size); // Show queue
        }

        // Clear input buffer and get next command
        cin.clear();
        cin.ignore(100, '\n');
        cout << "\nEnter option: ";
        cin >> userInput;
    }

    cout << "\nGoodbye!" << endl;
    return 0;
}

// Adds a new value to the end of the queue if there's space
int enqueue(int queue[], int &size, int val)
{
    cout << "Integer: ";
    cin >> val;

    if (size >= MAX)
    {
        cout << "Error: Queue Overflow!\n";
        printQueue(queue, size);
        return 1;
    }

    queue[size] = val;
    size++;
    printQueue(queue, size);
    return 0;
}

// Removes all values up to and including the first match from the queue
int dequeue(int queue[], int &size, int &val)
{

    cout << "Integer: ";
    cin >> val;

    if (size <= 0)
    {
        cout << "Queue Empty.\n";
        printQueue(queue, size);
        return 1;
    }

    int index = -1;

    // Find the index of the value to match
    for (int i = 0; i < size; i++)
    {
        if (queue[i] == val)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << val << " is not in the queue." << endl;
    }
    else
    {
        // Shift all values after the match to the front
        for (int i = 0; i < size - index - 1; i++)
        {
            queue[i] = queue[i + index + 1];
        }

        size -= (index + 1); // shrink size
    }

    printQueue(queue, size);
    return 0;
}

// Prints the contents of the queue
void printQueue(int queue[], int size)
{
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << queue[i];
        if (i != size - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}
