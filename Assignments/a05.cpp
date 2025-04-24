/******************************************************************************
# Author:           Cameron Kuykendall
# Assignment:       A05
# Date:             April 12, 2025
# Description:      This program reads job titles, salaries, and remote percentages
                    from a file. It determines which job title has the highest salary,
                    calculates the average remote percentage for that job title, and
                    prints a formatted table of all job data.

# Input:            a05.txt – file – Contains job title;salary;remote (0/100) on each line
                    jobTitle – char array – Stores job titles read from file
                    salaryRemoteArray – int 2D array – Stores salary and remote % for each job

# Output:           Formatted job list – string/int – Occupation, Salary, Remote %
                    Summary stats – string/int/double – Highest salary, associated job title,
                    and average remote percentage for that title

# Specifications:   A05 specifications
******************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int MAXROW = 25;
const int MAXCOLUMN = 2;
const int MAXCHAR = 51;

int openFile(ifstream &inputFile, char fileName[]);

void readAndAnalyzeData(ifstream &inputFile, char jobTitle[][MAXCHAR],
                        int salaryRemoteArray[][2], int &maxSalary,
                        char maxSalaryJobTitle[MAXCHAR], int &count);

void remotePercentageCalculation(char jobTitle[][MAXCHAR], int &maxSalary,
                                 int &count, char maxSalaryJobTitle[MAXCHAR],
                                 double &remotePercentage, int salaryRemoteArray[][2]);

void printArray(char jobTitle[][MAXCHAR], int salaryRemoteArray[][2], int &maxSalary,
                double &remotePercentage, char maxSalaryJobTitle[MAXCHAR], int &count);

int main()
{
    // individual vars
    ifstream inputFile;
    char fileName[] = "a05.txt";
    char jobTitle[MAXROW][MAXCHAR];
    double remotePercentage = 0;
    int maxSalary = 0;
    char maxSalaryJobTitle[MAXCHAR];
    int salaryRemoteArray[MAXROW][MAXCOLUMN];
    int count = 0;

    openFile(inputFile, fileName);
    readAndAnalyzeData(inputFile, jobTitle, salaryRemoteArray, maxSalary, maxSalaryJobTitle, count);
    remotePercentageCalculation(jobTitle, maxSalary, count, maxSalaryJobTitle, remotePercentage, salaryRemoteArray);
    printArray(jobTitle, salaryRemoteArray, maxSalary, remotePercentage, maxSalaryJobTitle, count);
    return 0;
}
// Opens the input file and checks for errors
int openFile(ifstream &inputFile, char fileName[])
{
    inputFile.open(fileName);

    if (!inputFile.is_open())
    {
        cout << "error: couldn't find / open " << fileName << endl;
        return 1;
    }
    cout << "FOUND FILE!" << endl;
    return 0;
}

// Reads one line of job data into arrays
void createArrays(ifstream &inputFile, char jobTitle[][MAXCHAR], int salaryRemoteArray[][2], int &count)
{
    inputFile.getline(jobTitle[count], MAXCHAR, ';');
    inputFile >> salaryRemoteArray[count][0];
    inputFile.ignore(5, ';');
    inputFile >> salaryRemoteArray[count][1];
    inputFile.ignore(5, '\n');
    count++;
}

// Reads all data and finds the job with the highest salary
void readAndAnalyzeData(ifstream &inputFile, char jobTitle[][MAXCHAR],
                        int salaryRemoteArray[][2], int &maxSalary,
                        char maxSalaryJobTitle[MAXCHAR], int &count)
{

    while (!inputFile.eof())
    {
        createArrays(inputFile, jobTitle, salaryRemoteArray, count);

        if (count == 1)
        {
            maxSalary = salaryRemoteArray[count - 1][0];
            strcpy(maxSalaryJobTitle, jobTitle[count - 1]);
        }
        else if (count > 1 && salaryRemoteArray[count - 1][0] > maxSalary)
        {

            if (strcmp(jobTitle[count - 1], maxSalaryJobTitle) != 0)
            {
                maxSalary = salaryRemoteArray[count - 1][0];
                strcpy(maxSalaryJobTitle, jobTitle[count - 1]);
            }
            else if (strcmp(maxSalaryJobTitle, jobTitle[count - 1]) == 0)
            {
                maxSalary = salaryRemoteArray[count - 1][0];
                strcpy(maxSalaryJobTitle, jobTitle[count - 1]);
            }
        }
    }
}

// Calculates average remote % for the highest-paying job title
void remotePercentageCalculation(char jobTitle[][MAXCHAR], int &maxSalary,
                                 int &count, char maxSalaryJobTitle[MAXCHAR],
                                 double &remotePercentage, int salaryRemoteArray[][2])
{
    int jobTitleCount = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(jobTitle[i], maxSalaryJobTitle) == 0)
        {
            jobTitleCount++;
            remotePercentage += salaryRemoteArray[i][1];
        }
    }

    remotePercentage /= jobTitleCount;
}

// Displays the job data table and summary information
void printArray(char jobTitle[][MAXCHAR],
                int salaryRemoteArray[][2], int &maxSalary,
                double &remotePercentage, char maxSalaryJobTitle[MAXCHAR], int &count)
{
    cout << left << setw(22) << "\nOccupation" // job title column
         << right << setw(10) << "Salary"      // label

         << "    "
         << right << setw(9) << "Remote (0/100)" // label

         << endl;
    cout << setfill('-') << setw(54) << '-' << endl;
    cout << setfill(' ');
    for (int i = 0; i < count - 1; i++)
    {
        cout
            << left << setw(25) << jobTitle[i]            // job title column
            << "$ " << setw(7) << salaryRemoteArray[i][0] // salary
            << "    "
            << setw(3) << right << salaryRemoteArray[i][1] // remote %
            << endl;
    }

    cout << "\nThe highest paying job is: " << maxSalaryJobTitle << endl;
    cout << "The highest salary is: $" << maxSalary << endl;
    cout << fixed << setprecision(1) << "The job is remote " << remotePercentage << "% of the time." << endl;
}
