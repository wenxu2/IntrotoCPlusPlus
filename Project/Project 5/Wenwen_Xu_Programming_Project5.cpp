/* File Name: Wenwen_xu_ProgramProject5.cpp
 * Author: Wenwen Xu
 * Email Address: wx2@students.uwf.edu
 * Assignment Number: 5
 * Description: This project checks if the first string contains the second string.
 * Last Changed: 24 July 2018
 */
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctype.h>
using namespace std;

void getInputFile(string input_filename, string output_filename);
/*
 * Get input file and output file and store them to different array
 */

void toLowerCase(char string[], int size);
/*
 * take an char array and convert to lower case
 */

string toUpperCase(char string[],int size1,int size2, int position);
/*
 * take an char array and convert to upper case
 */

int isStringContained(char str1[], int size1, char str2[], int size2);
/*
 * check if array contains certain array
 */

int main()
{
    /*
     * ask the user to enter the name for inout and output
     */
    string input_filename;
    string output_filename;
    cout << "Please enter the input filename: ";
    cin >> input_filename;
    
    cout << "Please enter the output filename: ";
    cin >> output_filename;
    
    /*
     * call getInputFile
     */
    getInputFile(input_filename,output_filename);
    
    return 0;
}

void getInputFile(string input_filename, string output_filename)
{
   
    string original_string_1;
    string original_string_2;
    
    /*
     * open both of the files
     */
    ifstream file(input_filename);
    ofstream outputfile;
    outputfile.open(output_filename);

    int i = 0;
    
    if(file.is_open())
    {
        while(!file.eof())
        {
            if(i == 0)
            {
                file >> original_string_1;
            }
            if(i == 1)
            {
                file >> original_string_2;
            }
            i++;

        }
        file.close();
    }else
    {
        cout << "FIle does not exist!" << endl;
    }
    
   
    /*
     * assign the size
     */
    int size1 = original_string_1.length();
    int size2 = original_string_2.length();
   
    char str1[size1];
    char str2[size2];
    
    size1 = original_string_1.length();
    size2 = original_string_2.length();
    
    /*
     * print the original strings
     */
    cout<<"The original srtings are: \n" <<original_string_1 << "\n" << original_string_2<<endl;
    
    /*
     * assign both string to arraies
     */
    strcpy(str1, original_string_1.c_str());
    strcpy(str2, original_string_2.c_str());
    
    /*
     * convert both words in lower case
     */
    toLowerCase(str2, size2);
    toLowerCase(str1, size1);
    
    /*
     * call isStringContained() and also write to the file
     */
    if(isStringContained(str1,size1,str2,size2) >= 0)
    {
        cout << original_string_2 <<" is a substring of " << original_string_1 <<endl;
        
        cout << "The new string is : " << toUpperCase(str1,size1,size2,isStringContained(str1,size1,str2,size2)) << endl;
        outputfile << toUpperCase(str1,size1,size2,isStringContained(str1,size1,str2,size2));
        outputfile.close();
        
        cout << "Content has been written to the file " << output_filename << endl;
        
    }
    else
    {
        cout << "Could not find the substring."<<endl;
    }
   
}

void toLowerCase(char string[], int size)
{

    for(int i = 0; i < size; i++)
    {
        string[i] = tolower(string[i]);
       
    }
    cout << "\n";
}

string toUpperCase(char string1[],int size1,int size2, int position)
{

    for(int i = 0; i < size2; i++)
    {
        string1[i+position] = toupper(string1[i+position]);
        
    }

    string print = string1;
    
    
    return print;
}

int isStringContained(char str1[], int size1, char str2[], int size2)
{
    
    for(int i = 0; i < size1; i++)
    {
        if(str1[i] == str2[0])
        {
            for(int j = 1; j < size2; j++)
            {
                if(str1[i+j] == str2[j])
                {
                    if(j == (size2-1))
                    {
                        return i;
                    }
                    
                }
                else{
                    break;
                }
            }
            
        }
    }
    
    return -1;
}
