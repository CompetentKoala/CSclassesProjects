// The implementation file for Course.h
// It loads students from a text file.
#include <iostream>
#include <cstring>

#include "Course.h"
#include "Student.h"
using namespace std;

// initiaizes a course variable and returns it. The array is empty
// and the number of students is set to 0.
Course initCourse()
{
	Course course;
	course.numStudents = 0;
	return course;
}

// reads a student from the file and calls AddStudent
void readStudent(ifstream &inFile, Course &course)
{
	Student tempStudent;
	while (inFile.getline(tempStudent.first, 20, ';'))
	{
		inFile.getline(tempStudent.last, 20, ';');
		inFile >> tempStudent.gpa;
		inFile.ignore(10, '\n');

		addStudent(tempStudent, course);
	}
}

// adds a student to the roster, and increment count
// modify this function to add the student sorted by name
// do not use any sorting functions.
// See this example in zyBooks Section 14.7 [https://learn.zybooks.com/zybook/PCCCS161BSpring23/chapter/14/section/7]
void addStudent(Student student, Course &course)
{
	int i = 0;

	// Empty list, insert at 0
	if (course.numStudents == 0)
	{
		course.roster[0] = student;
	}
	else
	{
		// Find where to insert by comparing last names
		for (i = 0; i < course.numStudents; i++)
		{
			if (!(strcmp(course.roster[i].last, student.last) < 0))
			{
				break;
			}
		}

		// Shift students right to make room
		for (int j = course.numStudents; j > i; j--)
		{
			course.roster[j] = course.roster[j - 1];
		}

		course.roster[i] = student;
	}

	course.numStudents++;
}

// prints a whole Course roster calling student print.
// use a for loop and print all the students
// must call the printStd function in Student.h
void printRoster(Course course)
{
	for (int i = 0; i < course.numStudents; i++)
	{
		printStd(course.roster[i]);
	}
}

/*Based on the grade level you are doing: Please read the appropriate level assignment document.
add code and function comments for the below 2 functions.
*/

void dropStudent(char *lastname, Course &course)
{
	for (int i = 0; i < course.numStudents; i++)
	{
		if (strcmp(lastname, course.roster[i].last) == 0)
		{
			cout << "\nFound and removed student: " << course.roster[i].first << " " << course.roster[i].last << endl;
			for (int j = i; j < course.numStudents - 1; j++)
			{
				strcpy(course.roster[j].first, course.roster[j + 1].first);
				strcpy(course.roster[j].last, course.roster[j + 1].last);
				course.roster[j].gpa = course.roster[j + 1].gpa;
			}
			course.numStudents--;
		}
	}
	// This function receives the name of a student and the course
	// and removes the student with that name from the roster.

	// If the name does not exist, do not do anything.

	// Notice the lastname is received as a pointer. See section15.4

	// Receiving arrays as pointers in Functions in zybooks for the
	// pointer syntax.
	// Course variable is received by reference since the number of
	//  students and the array will change if you remove a student
	//  from the list.

	// Test the function by adding code to main() - there are comments
	// where you should add code and call the function.
}

Student findStudentHighestGPA(Course course)
{
	double maxGpa = course.roster[0].gpa;
	Student maxGpaStudent = course.roster[0];
	for (int i = 1; i < course.numStudents; i++)
	{
		if (course.roster[i].gpa > maxGpa)
		{
			maxGpaStudent = course.roster[i];
			maxGpa = course.roster[i].gpa;
		}
	}
	return maxGpaStudent;
}
