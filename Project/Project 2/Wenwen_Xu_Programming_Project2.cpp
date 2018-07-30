/*
 * Project 2
 * Wenwen Xu
 * This program ask user to enter their plan and data bytes used for the month
 *      the program will calculate the price for the user.
 */

#include <iostream>

using namespace std;

int main()
{
    
    int megabytes; // must between 0 to 100,000
    char plan;
    float total;
    int save;
    bool userInput_correctLetter = false;
    bool userInput_correctMegabyte = false;
    bool letterExist = false;
    
    
    /*
     * constant prices from the project descriptions
     */
    
    char UserInput [6] = {'B', 'b', 'E', 'e','P', 'p'};
    
    
    int basic_plan = 35;
    int enhanced_plan = 75;
    int platinum_plan = 120;
    
    double basic_over = 0.02;
    double enhanced_over = 0.01;
    
    int basic_data = 5000;
    int enhanced_data = 10000;
    
    int megabytes_min = 0;
    int megabytes_max = 100000;
    
    
    
    /*
     * ask the user to enter the plan
     * also check if the user input is valid or not
     */
    while(!userInput_correctLetter)
    {
        cout << "Which plan does the customer use (B, E, or P)?\n";
        cin >> plan;
        
        for(int i = 0; i < sizeof(UserInput) ; i++)
        {
            if(plan == UserInput[i])
            {
               userInput_correctLetter = true;
                letterExist = true;
            }
            
        }

        if(!letterExist)
        {
            cout << "Enter only E, B, or P for the plan.\n";
        }

    }

    /*
     * ask user to enter the megabyes
     * also check if the user enter the correct megabytes
     */
    while(!userInput_correctMegabyte)
    {
        cout << "How many MB did the customer use last month?\n";
        cin >> megabytes;
        
        if((megabytes >= megabytes_min) && (megabytes <= megabytes_max))
        {
            userInput_correctMegabyte = true;
        }
        else
        {
            cout << "Enter a number from 0 through 100000 for MB used.\n";
        }
    
    }
    
    /*
     * print the cost for the user based on user input
     */
    if((plan == 'b') || (plan == 'B'))
    {
        total = basic_plan;
        
        if(megabytes > basic_data)
        {
            total = basic_plan + (megabytes - basic_data) * basic_over;
        }
        
        cout << "The charge are $"<< total << "." <<endl;
    }
    else if((plan == 'e') || (plan == 'E'))
    {
        total = enhanced_plan;
        
        if(megabytes > enhanced_data)
        {
            total = enhanced_plan + (megabytes - enhanced_data) * enhanced_over;
        }
        
        cout << "The charge are $"<< total << "."<<endl;
    }
    else if ((plan == 'p') || (plan == 'P'))
    {
        total = platinum_plan;
        cout << "The charge are $"<< total << endl;
    }
    
    /*
     * check to see if the user can save money by
     *  upgrading their plan.
     */
    
    if((plan == 'B') || (plan == 'b'))
    {
        if((total > enhanced_plan) && (total < platinum_plan))
        {
            save = total - enhanced_plan;
            cout << "By switching to plan E, you can save $" << save << "." << endl;
        }
        else if((total > platinum_plan))
        {
            save = total - platinum_plan;
            cout << "By switching to plan P, you can save $" << save << "." << endl;
        }
    }
    else if((plan == 'E') || (plan == 'e'))
        {
            if(total > platinum_plan)
            {
                save = total - platinum_plan;
                cout << "By switching to plan P, you can save $" << save << "." <<endl;
            }
        }
    

    return 0;
}
