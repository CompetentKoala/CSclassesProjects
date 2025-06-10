#include <iostream>
using namespace std;


//declare functions
void readInput(int * x, int * y);
void swapInt(int * x, int * y);


//main functionn
int main() {
    int x = 0;
    int y = 0;
    cout << "Welcome!\n" << endl;
    readInput(& x, & y);
    cout << "Before swap:" << endl;
    cout << "Integer 1 is: " << x << endl;
    cout << "Integer 2 is: " << y << endl;
    swapInt(& x, & y);
    cout << "\nAfter swap:" << endl;
    cout << "Integer 1 is: " << x << endl;
    cout << "Integer 2 is: " << y << endl;
}


//This function reads input from the user
void readInput(int * x, int * y) {
    cout << "Enter integer 1: ";
    cin >> * x;
    cout << "Enter integer 2: ";
    cin >> * y;
}


//this function swaps the values of x and y
void swapInt(int * x, int * y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
