// The client file or the driver file
// This file has the main() function
/**************************************************************
* Author: Cameron Kuykendall
* File: main.cpp
* Date: April 22nd, 2025
* Description:
The purpose of this program is to keep track of a Course and
its roster. The Course has a list of students and the number
of students on the roster. Each student has a first name,
last name and gpa for the attributes.

The program loads from a file into the course roster - the
functionalities are to add a student, remove a student,
print the roster, print a single student and to find the
student with the highest gpa.

**************************************************************/
#include <iostream>
#include <cstring>

#include "Student.h"
#include "Course.h"

using namespace std;

int main()
{
  Course course = initCourse();
  ifstream inFile;
  Student highestGpaStudent;
  char userInput[20];
  cout << "Welcome to my Course Roster Program\n"
       << endl;
  inFile.open("students.txt");
  if (!inFile)
  {
    cout << "File did not open! Program Exiting!!" << endl;
    return 0;
  }
  // calls readStudent to read from the file
  readStudent(inFile, course);
  // calls printRoster to print the roster
  cout << "Here is the course roster: " << endl;
  printRoster(course);

  // call the appropriate functions based on the grade level you are choosing.
  // read a last name into a char array and pass to function.
  // declare variables if needed

  cout << "\nEnter the last name of the student to drop: ";
  cin >> userInput;

  dropStudent(userInput, course);

  // calls printRoster to print the roster after the student drop.
  // Uncomment the next 2 lines once you have dropped a student
  cout << "\nHere is the course roster: " << endl;
  printRoster(course);

  // calls findStudentHighestGPA to get Student with highest GPA
  // declare variables if needed

  highestGpaStudent = findStudentHighestGPA(course);

  // calls printStd to print the student with the highest GPA
  cout << "\nThe student with the highest GPA is: ";
  printStd(highestGpaStudent);

  cout << "\nThank you for using my Student Roster program!!" << endl;
  return 0;
}
