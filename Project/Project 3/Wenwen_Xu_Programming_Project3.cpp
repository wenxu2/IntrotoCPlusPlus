/* File Name: Wenwen_xu_ProgramProject3.cpp
 * Author: Wenwen Xu
 * Email Address: wx2@students.uwf.edu
 * Assignment Number: 3
 * Description: This program covnvert units
 * Last Changed: 20 June 2018
*/

#include <iostream>
using namespace std;

void choice();
/*
 * display the menu and
    ask the user to pick a choice from the menu
 */

void convert(int choice);
/*
 * convert the user input
 */

int main()
{
    bool calculate = false;
    char answer;
    
    /*
     * call choice function to display the menu
     */
    choice();
    
    /*
     * ask if the user want to continue
     */
    while(!calculate)
    {
        cout << "Do you wish to run again(y/n)?: ";
        cin >> answer;
        
        if(answer != 'n')
        {
            choice();
        }
        else if(answer == 'n')
        {
            calculate = true;
        }
    }
    
    return 0;
    
}


void choice()
{
    int userInput;
    
    /*
     * display the menu
     */
    cout << "Welcome to the super duper wizard converter!\n";
    cout << "1) KB --> MB\n";
    cout << "2) KB --> GB\n";
    cout << "3) MB --> KB\n";
    cout << "4) MB --> GB\n";
    cout << "5) GB --> MB\n";
    cout << "6) GB --> KB\n";
    cout << "7) Exit     \n";
    
    /*
     * ask the user to make a choice
     */
    cout << "Please enter an integer from 1 to 7> ";
    cin >> userInput;
    
    /*
     * if the user enter a invalid choce
        the program will ask the user to make a valid choice between 1 - 7
     */
    if((userInput < 1) || (userInput > 7))
    {
        cout << "Invalid choice, please enter a number from 1 - 7.\n";
        choice();
    }
    else
    {
        convert(userInput);
    }
    
    
}

void convert(int choice)
{
    double quantity;
    double KB;
    double MB;
    double GB;
    int unit = 1024;
    
    /*
     * if the user input does not equal to 7
     * else quit the program
     */
    if(choice != 7)
    {
        cout << "Please input the quantity to be converted: ";
        cin >> quantity;
    }
    
    /*
     * 1GB = 1024 MB
     * 1MB = 1024 KB
     * 1KB = 1024 bytes
     */
    
    switch (choice) {
        case 1: // 1) KB --> MB
            MB = quantity / unit;
            cout << quantity << " KB is " << MB << " MB.\n";
            break;
            
        case 2: // 2) KB --> GB
            GB = quantity / unit / unit;
            cout << quantity << " KB is " << GB << " GB.\n";
            break;
            
        case 3: // 3) MB --> KB
            KB = quantity * unit;
            cout << quantity << " MB is " << KB << " KB.\n";
            break;
            
        case 4: //4) MB --> GB
            GB = quantity / unit;
            cout << quantity << " MB is " << GB << " GB.\n";
            break;
            
        case 5: //5) GB --> MB
            MB = quantity * unit;
            cout << quantity << " GB is " << MB << " MB.\n";
            break;
            
        case 6: // 6) GB --> KB
            KB = quantity * unit * unit;
            cout << quantity << " GB is " << KB << " KB.\n";
            break;
            
        case 7: // 7) Exit
            cout << "Goodbye!\n";
            exit(0);
            break;
            
        default:
            //do nothing;
            break;
    }
    
    
}
