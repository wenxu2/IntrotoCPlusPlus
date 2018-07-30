/*
 * Project 1
 * Wenwen Xu
 * This program calculate the current loan amount for 4 years.
 */

#include <iostream>

using namespace std;

int main()
{
    
    double original;
    double current;
    int interest;
    double balance;
    double over;
    string year;
    
    
    /*
     * ask user input for original loan, current loan,
     * and the interest rate.
     */
    cout <<"Hello, welcome to Big Bank, Inc\n";
    cout <<"Please enter the original loan amount:\n";
    cin >> original;
    cout << "Please enter the current loan amount:\n";
    cin >> current;
    cout <<"Please enter the interest rate:\n";
    cin >> interest;
    cout << "\n";
    
    /*
     * calculate the balance after 4 years
     * according to user inout
     */
    for(int i = 0; i < 4; i++)
    {
        /*
         * Set the year
        */
        if(i == 0)
        {
            year = "one";
        }
        if(i == 1)
        {
            year = "two";
        }
        if(i == 2)
        {
            year = "three";
        }
        if(i == 3)
        {
            year = "four";
        }
        
        /*
         * calculate the balance for current year
         */
        balance = current + current * interest /100;
        
        cout << "For year " << year << ": ";
        cout << "the loan amount is " << balance << ".\n";
        
        /* if the current balance is over the original loan,
         * calculate the over amount
        */
        if(balance > original)
        {
            over = balance - original;
            cout << "The current is over the original loan amount by "<< over << ".\n\n";
        }
        else
        {
            cout <<"\n";
        }
        
        /*
         * The current will equal to the balance for the next year
         */
        current = balance;
    }
    
	return 0;
}
