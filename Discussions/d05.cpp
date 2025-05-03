/******************************************************************************
# Author: Cameron Kuykendall
# Lab: d05
# Date: April 27th, 2025
# Description: Reads major enrollment data, calculates the percentage of men
#              and women per major, and identifies the highest paying major.
# Input: Input file name, output file name
# Output: A formatted table of major names, percent men, percent women, and the top paying major
# Sources: d05 specs.
******************************************************************************/

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// function prototypes
bool openFile(ifstream &inFile, char fileName[]);
void ratioCalc(ifstream& inFile, ofstream& outFile, char majors[][100], int &majorCount);
void getMajors(ifstream& inFile, char majors[][100], int &majorCount);
void highestPayMajor(ifstream& inFile, ofstream& outFile, char majors[][100], int &majorCount);


// main
int main() {
  ifstream inFile;
  ofstream outFile;
  char outputFileName[100];
  char fileName[100];
  char majors[100][100];
  int majorCount = 0;

  cout << "Enter name of input file:";
  cin >> fileName;
  cout << "Enter name of output file:";
  cin >> outputFileName;


//open in File
  if (!openFile(inFile, fileName)) {
    cout << "file did not open. Program terminating!!!";
    return 0;
  }
//open out File
  outFile.open(outputFileName);
  if (!outFile) {
      cout << "Output file did not open. Program terminating!!!" << endl;
      return 0;
  }

  getMajors(inFile, majors, majorCount);

  ratioCalc(inFile,outFile,majors,majorCount);
  highestPayMajor(inFile, outFile, majors, majorCount);

  inFile.close();
  outFile.close();
}

// function to open file
// returns true if file opens
// returns false if file does not open for any reason
// parameters: file stream variable by reference and fileName
bool openFile(ifstream &inFile, char fileName[]) {
  inFile.open(fileName);
  if (!inFile) {
    return false;
  }
  return true;
}
//Makes a list of the majors and gets the count
void getMajors(ifstream& inFile, char majors[][100], int &majorCount){
    char temp[100];
    inFile.ignore(100, '\n');

while (inFile >> temp)
{
    inFile >> majors[majorCount];
    inFile.ignore(100, '\n');

    majorCount++;
}
inFile.clear(); // clear EOF flag
inFile.seekg(0, ios::beg); // go back to beginning of file

}

// write the ratioCalc function below this
void ratioCalc(ifstream& inFile, ofstream& outFile, char majors[][100], int &majorCount){

    char temp[100];
    double totalInMajor;
    double totalMen;
    double totalWoman;
    double percentMen;
    double percentWoman;

    inFile.ignore(100, '\n');

    outFile << fixed << setprecision(2);
        outFile << left << setw(45) << "MAJOR" << setw(15) << "PERCENT MEN" << setw(15) << "PERCENT WOMAN" << endl;
        outFile << setfill('-') << setw(75) << "" << endl;
        outFile << setfill(' ');

    for (int i = 0; i < majorCount; i ++){
        inFile >> temp >> temp >> temp >> totalInMajor;
        inFile >> totalMen;
        inFile >> totalWoman;
        inFile.ignore(100, '\n');

        percentMen =( totalMen / totalInMajor) * 100;
        percentWoman = ( totalWoman / totalInMajor) * 100;

        outFile << setw(49) << majors[i]
                << setw(15) << percentMen
                << setw(15) << percentWoman << endl;

    }
    inFile.clear();          // clear eof and fail bits
    inFile.seekg(0, ios::beg); // go back to start of file

    }

void highestPayMajor(ifstream& inFile, ofstream& outFile, char majors[][100], int &majorCount){
    char temp[100];

    int currentSalary = 0;
    int maxSalary = 0;
    int maxSalaryIndex = 0;

    inFile.ignore(100, '\n');

    for (int i = 0; i < majorCount; i ++){
        inFile >> temp >> temp >> temp >> temp >> temp >> temp;
        inFile >> currentSalary;
        inFile.ignore(100, '\n');

        if (currentSalary > maxSalary){
            maxSalary = currentSalary;
            maxSalaryIndex = i;
        }
    }

    outFile << "\n\nThe Top paying major is: " << majors[maxSalaryIndex] <<" at " << maxSalary << endl;
}
