/******************************************************************************
# Author:           Cameron Kuykendall
# Assignment:       A03
# Date:             April 5, 2025
# Description:      This program inputs in scores entered by the user
                    (must be between 0.0, and 4.0 or an error message will be output and
                    the question repromoted) and stops recieving them in if the user enters
                    -1. The program will display the scores along with the assigned grade
                    for each score (A, B, C, D, F). It will then sort the grades in ascending
                    order and display them again. It will then display the median score with
                    2 decimals.

# Input:            scores – double – Score entered by the user (between 0 and 4, or -1 to end input)

# Output:           Welcome message – string – welcom and score instructions
                    Input prompt – string – Prompt for score entry (">>")
                    Error messages – string – Displayed for invalid entries (non-numeric or out-of-range)
                    Unsorted list output – double and char – Original scores with their letter grades
                    Sorted list output – double and char – Scores sorted in ascending order with grades
                    Median score – double – The calculated median of the sorted score list
                    Exit message – string – Thank you message when program ends

# Specifications:   A03 grade A specifications
******************************************************************************/

#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

void welcome();
void exit();
void readScores(double scores[], int &count);
void readDouble(string prompt, double &num);
void calcGrade(double scores[], char grade[], int count);
void printList(double scores[], char grades[], int count);
void sort(double scores[], char grade[], int count);
double median(double scores[], int count);

int main()
{
    int MAX = 20;
    double scores[MAX];
    char grades[MAX];
    int count = 0;

    cout << fixed << setprecision(1);

    welcome();

    readScores(scores, count);

    calcGrade(scores, grades, count);

    printList(scores, grades, count);

    cout << fixed << setprecision(2);
    cout << "\nThe median score is: " << median(scores, count);

    exit();

    return 0;
    /// Declare all variables needed. The 2 arrays (double scores[], and char grades[]) must be declared in main().
    // Call readScores() and send scores and count to it. This will fill the scores array from the user. You should call the readDouble() function to read and validate the scores before adding them to the scores array.
    // count will have the number of values read.
    // Call calcGrade()function that takes the scores array and an empty grades array and fills the grades array with letter grades.
    // Call the printList function to print the lists.
    // Call the sort function to sort the list based on scores.
    // Call the printList function to print the lists.
    // Call the median function to find the median and print it in main().
    // Assume the arrays will always contain fewer than 20 values. You must not let the user enter more than 20 values.
}

void welcome()
{
    cout << "Welcome to my Parallel Arrays program!" << endl;
    cout << "Please enter the list of scores (-1 to end input:)" << endl;
    cout << "Valid scores are between 0 and 4 inclusive." << endl;
}

void readScores(double scores[], int &count)
{
    while (true)
    {
        readDouble(">>", scores[count]);
        if (scores[count] == -1)
        {
            break;
        }
        while (scores[count] < 0.0 || scores[count] > 4.0)
        {
            cout << "Invalid score, Please try again!!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            readDouble(">>", scores[count]);
        };
        count++;
    }
}

void readDouble(string prompt, double &num)
{
    cout << prompt;
    cin >> num;
    while (cin.fail())
    {
        cout << "Invalid score, Please try again!!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << prompt;
        cin >> num;
    }
    // This function should be used any time you read any floats or doubles from the user. Use this function to read the numerical scores from the user.
    // It takes a string prompt, outputs it, reads a number from the user, validates and returns the num by reference.
    // Write it exactly like the readInt from assignment 1 but declare a double or float instead of an int. See Samplea01.cpp for the readInt function.
    // You must catch all invalid data such as characters, negative numbers etc.
}

void calcGrade(double scores[], char grade[], int count)
{
    int i = 0;
    for (i = 0; i < count; i++)
    {
        if (scores[i] > 3.3)
        {
            grade[i] = 'A';
        }
        else if (scores[i] > 2.7 && scores[i] <= 3.3)
        {
            grade[i] = 'B';
        }
        else if (scores[i] > 1.9 && scores[i] <= 2.7)
        {
            grade[i] = 'C';
        }
        else if (scores[i] > 1.1 && scores[i] <= 1.9)
        {
            grade[i] = 'D';
        }
        else
        {
            grade[i] = 'F';
        }
    }
}

void printList(double scores[], char grades[], int count)
{
    int i;
    cout << "\nYour stats are as below: " << endl;

    cout << "\nThe list of scores and their grades are:" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << scores[i] << " " << grades[i] << endl;
    }
    cout << "\nThe list sorted by scores in ascending order:" << endl;

    sort(scores, grades, count);

    for (int i = 0; i < count; i++)
    {
        cout << scores[i] << " " << grades[i] << endl;
    }

    // Go through a for loop and print the scores and the corresponding grades for each item.
    // void sort(double scores[], char grade[], int count)
    // Sort the arrays using the given sorting algorithm. This is called Selection Sort. Use only this algorithm to sort your list. To see how the Selection Card Sort Algorithm works, watch this video from Virginia Tech.
    // Be careful and make sure you sort based on the scores array and swap the corresponding element in the grade array to maintain the correspondence between the two arrays. Meaning if you swap the scores in index 0 and 5, you must also swap the corresponding grades in index 0 and 5.
    // Watch this Python Video to help you with the sorting algorithm. Try this Selection Sort Animation by Y. Daniel Liang.

    // procedure selection sort
    //    list  : array of items
    //    count : size of list
    //    for i = 0 to count - 1
    //    /* set current element as minimum*/
    //   	min = i
    //   	/*go through the list and find the smallest element*/
    //   	for j = i+1 to count
    //      		if list[j] < list[min] then
    //         		min = j;
    //      		end if
    //   	end for
    //   	/* swap the minimum element with the current element
    // If they are not the same element*/
    //   	if min != i  then
    //      		swap list[min] and list[i]
    //   	end if
    //    end for
    // end procedure
}

void sort(double scores[], char grades[], int count)
{
    int i;
    int pass;
    for (pass = 0; pass < count; pass++)
    {
        int min = pass;
        for (i = pass + 1; i < count; i++)
        {
            if (scores[i] < scores[min])
            {
                min = i;
            }
        }
        if (min != pass)
        {
            double temp = scores[min];
            scores[min] = scores[pass];
            scores[pass] = temp;

            char tempGrade = grades[min];
            grades[min] = grades[pass];
            grades[pass] = tempGrade;
        }
    }
}

double median(double scores[], int count)
{
    if (count % 2 == 0)
    {
        return (scores[(count / 2) - 1] + scores[count / 2]) / 2;
    }
    else
    {
        return scores[count / 2];
    }

    return 0.0;

    // After sorting, write this function to identify the median score. The median is located in the middle of the array if the array’s size is odd. Otherwise, the median is the average of the middle two values.
    // Return the median to main() and output in main() with two decimal places.
}

void exit()
{
    cout << "\n\nThank you for using my Parallel Arrays program!!" << endl;
}
