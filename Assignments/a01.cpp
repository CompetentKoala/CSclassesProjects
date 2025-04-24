/******************************************************************************
# Author:           Cameron Kuykendall
# Lab:              a01
# Date:             April 1, 2025
# Description:      This program allows the user to input one or more items with
                    qualities such as the product's name and cost, then add them all together.
                    Once the user is done, it will ask for a tip amount. It gives a discount based
                    on the ticket amount(5% is above $35, and 10% if above $50). It then calculates
                    the final amount owed. It repeats this until the user enters option 2, when it will
                    exit the program.

# Input:            option – int – User selects to place an order or quit the program
                    itemName – string – The name of each item being ordered
                    itemCost – double – The cost of each item
                    moreItems – char – User decides whether to add another item (y/n)
                    tip – double – Tip amount entered by the user

    # Output:       Menu – string – The list of available options to the user
                    cost – double – Total cost of all items before tip
                    cost  – double – Total cost including tip
                    "You get a 10% discount!" or "You get a 5% discount!" – string – Discount message based on total
                    cost – double – The calculated discount amount
                    cost – double – The final amount after applying discoun
                    Exit message – string – Thank you message when the user quits

# Sources:          A01 A grade specifications
******************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void welcome();
void displayMenu();
void readOption(int &option);
void readInt(string prompt, int &num);
void readDouble(string prompt, double &num);
void placeOrder(double &cost);
double tipDiscount(double &tip, double &discount, double cost);

int main()
{
    // Declare Variables
    int option = 1;
    double cost = 0.0, tip = 0.0, discount = 0.0, total = 0.0;

    // Set output precision to 2 for entire program
    cout << fixed << setprecision(2);

    // Prints a welcome message to the user
    welcome();

    // Repeat until option 2 is selected
    do
    {
        // Prints a welcome message to the user
        displayMenu();

        // Reads and validates menu option (1 or 2)
        readOption(option);
        if (option == 1)
        {
            // Reset cost
            cost = 0;
            // Collects item names and costs; adds to total cost
            placeOrder(cost);
        }
        // Exit if 2 is ever selected
        if (option == 2)
        {
            return 0;
        }

        // Display Total before tip and discounts
        cout << "\nyour total is: $" << cost << endl;

        // Reads tip, calculates discount, returns updated cost
        cost = tipDiscount(tip, discount, cost);

        // Display Total with tip
        cout << "\nyour total is: $" << cost << endl;

        // If cost is above $50, give 10% discount, if above $35, give 5%
        if (cost > 50)
        {
            cout << "you get a 10% discount!" << endl;
        }
        else if (cost > 35)
        {
            cout << "you get a 5% discount!" << endl;
        }

        // Display discount
        cout << "Your discount is $" << discount << endl;

        // Display Total with tip and discount applied
        cout << "Your final total is: $" << cost - discount
             << "\n"
             << endl;
    } while (option != 2);

    // Exit Message
    cout << "Thank you for using my program!" << endl;

    return 0;
}
// Prints a welcome message to the user
void welcome()
{
    cout << "Welcome to my Food Cart Program!" << endl;
}
// Displays the main menu with options
void displayMenu()
{
    cout << "What would you like to do today?" << endl;
    cout << "Pick an option from below:" << endl;
    cout << "\t1. Place an order" << endl;
    cout << "\t2. Exit" << endl;
}
// Displays the main menu with options
void readOption(int &option)
{
    readInt(">>", option);
    while (option != 1 && option != 2)
    {
        cout << "Invalid Option! Please choose 1-2!" << endl;
        readInt(">>", option);
    }
}
// Reads and validates any positive integer
void readInt(string prompt, int &num)
{
    cout << prompt << " ";
    while ((!(cin >> num) || num < 0))
    {
        cout << "Invalid Option! Please choose 1-2!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << prompt << " ";
    }
}
// Reads and adds a valid double to the given variable
void readDouble(string prompt, double &num)
{
    double inputNum = 1;

    cout << prompt;
    while (!(cin >> inputNum) || inputNum < 0)
    {
        cout << "Invalid Input! Please provide the cost" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << prompt;
    }
    num += inputNum;
}
// Collects item names and costs; adds to total cost
void placeOrder(double &cost)
{
    string itemName = "";
    double itemCost = 0;
    char moreItems = 'y';

    while (moreItems == 'y')
    {
        cin.ignore();
        cout << "Enter the name of your item: ";
        getline(cin, itemName);
        readDouble("Enter the cost of your item $: ", cost);
        cout << "Do you want another item? (y/n): ";
        cin >> moreItems;
        moreItems = tolower(moreItems);
        while ((moreItems != 'y') && (moreItems != 'n'))
        {
            cout << "Invalid Option! Please choose y/n!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            cout << ">>";
            cin >> moreItems;
        }
    }
}
// Reads tip, calculates discount, returns updated cost
double tipDiscount(double &tip, double &discount, double cost)
{
    readDouble("\nEnter the amount of tip you want to add $: ", tip);
    cost += tip;
    if ((cost > 35) && (cost < 50))
    {
        discount = cost * .05;
    }
    else if (cost > 50)
    {
        discount = cost * .1;
    }
    else
    {
        discount = 0;
    }

    return cost;
}
