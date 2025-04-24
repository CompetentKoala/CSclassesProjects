/******************************************************************************
# Author:           Cameron Kuykendall
# Assignment:       A04
# Date:             April 7, 2025
# Description:      This program stores a list of course numbers and their enrollment counts.
                    The user enters the course number and the amount of students in that class
                    the program will sort them in order as they are entered. THen it will
                    print them, then will delete any class from the list that has less than 10 students, then reprint.

# Input:            courseNums – char array – List of course numbers entered by the user
                    students – int array – Corresponding number of enrolled students per course

# Output:           Welcome message – string – Initial greeting for the user
                    Input prompt – string – Prompts for course number and student count
                    Final list – char and int – List after cancellation of low-enrollment courses
                    Exit message – string – Thank you message when program ends

# Specifications:   A04 grade A specifications
******************************************************************************/

#include <iostream>
#include <string> 
#include <iomanip>
#include <cctype>

using namespace std;

// Constant Variables
const int MAXCHAR = 51;
const int MAXCOURSES = 20;

// Prototypes
void welcome();
void readInput(char courseNums[][MAXCHAR], int students[], int &count);
void readInt(string prompt, int &num);
void printList(char courseNums[][MAXCHAR], int students[], int count);
void cancelCourses(char courseNums[][MAXCHAR], int students[], int &count);
void capitalizeCharArray(char charArray[]);
void exit();

// MAIN PROGRAM
int main()
{
    // Declare vars.
    char courseNums[MAXCOURSES][MAXCHAR];
    int students[MAXCOURSES];
    int count = 0;

    // Displays a welcome message and instructions for using the Course Rosters program.
    welcome();

    // Collects course numbers and enrollment data from the user until "QUIT" is entered.
    readInput(courseNums, students, count);

    // Sorts and prints the list of course numbers with their corresponding student enrollments.
    printList(courseNums, students, count);

    // Removes all courses from the list that have fewer than 10 enrolled students.
    cancelCourses(courseNums, students, count);

    // Prints the list of course numbers with their corresponding student enrollments.
    printList(courseNums, students, count);

    // Exit Message
    exit();

    // END PROGRAM
    return 0;
}

// Displays a welcome message and instructions for using the Course Rosters program.
void welcome()
{
    cout << "Welcome to my Course Rosters program!!" << endl;
    cout << "Enter course number and students enrolled when prompted." << endl;
    cout << "Enter Quit or quit for course number when you are done." << endl;
}
// Collects course numbers amount of students from the user until "QUIT/quit" is entered.
void readInput(char courseNums[][MAXCHAR], int students[], int &count)
{
    char tempCourse[MAXCHAR];
    int num = 0;

    cout << "Enter course number: ";
    cin >> tempCourse;
    capitalizeCharArray(tempCourse);

    while (strcmp(tempCourse, "QUIT") != 0)
    {
        readInt("Number of students enrolled: ", num);

        int insertPos = count;
        for (int i = 0; i < count && insertPos == count; i++)
        {
            if (strcmp(tempCourse, courseNums[i]) < 0)
            {
                insertPos = i;
            }
        }

        for (int j = count; j > insertPos; j--)
        {
            strcpy(courseNums[j], courseNums[j - 1]);
            students[j] = students[j - 1];
        }

        strcpy(courseNums[insertPos], tempCourse);
        students[insertPos] = num;
        count++;

        cout << "Enter course number: ";
        cin >> tempCourse;
        capitalizeCharArray(tempCourse);
    }
}
// Prompts the user for an integer input and validates that it’s between 0 and 25.
void readInt(string prompt, int &num)
{
    cout << prompt;
    cin >> num;
    while (cin.fail() || num > 25 || num < 0)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid number!! Please enter a number between 0 and 25" << endl;
        cout << prompt;
        cin >> num;
    }
}
// Sorts and prints the list of course numbers with their corresponding student enrollments.
void printList(char courseNums[][MAXCHAR], int students[], int count)
{

    cout << "\nList of courses and students:" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << setw(15) << left << courseNums[i] << right << students[i];
        cout << endl;
    }
}
// Removes all courses from the list that have fewer than 10 enrolled students.
void cancelCourses(char courseNums[][MAXCHAR], int students[], int &count)
{
    for (int i = 0; i < count; i++)
    {
        if (students[i] < 10)
        {
            for (int j = i; j < count - 1; j++)
            {
                strcpy(courseNums[j], courseNums[j + 1]);
                students[j] = students[j + 1];
            }
            count--;
            i--;
        }
    }
}
// Converts all characters in a given char array to uppercase.
void capitalizeCharArray(char charArray[])

{
    for (int i = 0; charArray[i] != '\0'; i++)
    {
        charArray[i] = toupper(charArray[i]);
    }
}

// Displays a thank-you message signaling the end of the program.
void exit()
{
    cout << "\n\nThank you for checking out my Course Rosters program!" << endl;
}
