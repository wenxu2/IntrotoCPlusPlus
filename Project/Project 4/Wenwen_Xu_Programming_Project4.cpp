/* File Name: Wenwen_xu_ProgramProject4.cpp
 * Author: Wenwen Xu
 * Email Address: wx2@students.uwf.edu
 * Assignment Number: 4
 * Description: This program read file and display the average, lowest, and highest salary
 * Last Changed: 3 July 2018
 */
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void calculate();
/*
 * this function ask the user to enter the filename, read the file and calculate average, lowest,
 * and highest salary.
 */

void bubblesort(double array[], int i);
/*
 * this function takes in an array, and store them to ascending
 *  order using bubble sort.
 */

void print(double array[], int size);
/*
 * this functiont takes in an array and the size of the array
 * and print array
 */

int main()
{
   
    calculate();
    
    return 0;
}

void calculate()
{
    double salary[21];
    double number = 0;
    int i = 0;
    int j = 0;
    double average;
    double highest;
    double lowest;
    double total = 0;
    string filename;
    
    /*
     *ask the user to enter the file name
     */
     cout << "Enter the salary file name : \n";
     cin >> filename;
     ifstream file (filename);

    /*
     * open the file that user entered and store the numbers in the array
     * close the file after the if() loop.
     */
    if(file.is_open()){
        
        while(!file.eof())
        {
            if(i == 0)
            {
                file >> number;
            }
            else if((i > 0) && (i <= number))
            {
                file >> salary[j];
                j++;
            }
            
            i++;
        }
        
        //close the file
        file.close();
        
    }else{
        cout << "File does not exist." <<endl;
    }
    

    /*
     * set lowest and highest salary equal to be the first salary
     */
    lowest = salary[0];
    highest = salary[0];
    
    for(int a = 0; a < j; a++)
    {
        total = total + salary[a];
        
        //find lowest number
        if(lowest > salary[a])
        {
            lowest = salary[a];
        }
        //find highest number
        if(highest < salary[a])
        {
            highest = salary[a];
        }
    }
    
    /*
     *calculate and find average
     */
    average = total / number;
    
    /*
     * print the output
     */
     std::cout << std::fixed;
     std::cout << std::setprecision(2);
     std::cout << "The average salary is " << average << "." << endl;
     std::cout << "The lowest salary is " << lowest << "." <<endl;
     std::cout << "The highest salary is " << highest << "." <<endl;
    
    /*
     * Extra Credit
     */
     cout << "Extra Credit (Print the array using the bubble sort): \n";
     bubblesort(salary, j);
    
}

void bubblesort(double array[], int n)
{
        
    bool sorted = true;
    int j = 0;
    int temp;

    /*
     * sorting the array
     */
    while (sorted) {
        
        sorted = false;
        j++;
        
        for (int i = 0; i < n - j; i++) {
            
            /*
             * if current number is bigger than the next number
             * set temp equal current number
             * set current number equal to the next number
             * set the next number equal to temp
             */
            if (array[i] > array[i + 1]) {

                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                sorted = true;
            }
        }
    }
    
    /*
     * call print() to print the sorted array
     */
    print(array, n);
    
}

void print(double array[], int size)
{
    /*
     * print the array
     */
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << endl;
    }
}
