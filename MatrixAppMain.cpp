/*
 
 This file contains the main program. It is a matrix calculator as well as a matrix operation quiz app. Features and challenges will be added as
 I continue in my studies of linear algebra and the uses of matrices in it.
 
 Code Author: Jose Sanchez Rodriguez
 
 */

#include <iostream>
#include "Matrix.h"

int main()
{
    string choice;
    
    cout << "Hello, and welcome to my matrix calculator and quiz app!" << endl;
    cout << "Please choose from the following options: " << endl << endl;
    cout << "1. Matrix operations quiz" << endl;
    cout << "2. Matrix calculator (coming soon!)" << endl << endl;
    cout << "Your choice -> ";
    getline(cin, choice);
    
    while(choice != "1" && choice != "2")
    {
        cout << "\n\nInvalid option! Please choose from the options listed:" << endl << endl;
        cout << "1. Matrix operations quiz" << endl;
        cout << "2. Matrix calculator (coming soon!)" << endl << endl;
        cout << "Your choice -> ";
        getline(cin, choice);
    }
    
    if(choice == "2")
        cout << "\nSorry, that feature has not been fully implemented yet. Check back soon!" << endl;
    
    else //option must have been 1.
    {
        cout << "\nWhich matrix operation would you like to be quizzed on?\n" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Multiplication" << endl << endl;
        cout << "Your choice -> ";
        getline(cin, choice);
        
        while(choice != "1" && choice != "2")
        {
            cout << "\n\nInvalid option! Please choose from the options listed:" << endl << endl;
            cout << "1. Addition" << endl;
            cout << "2. Multiplication" << endl << endl;
            cout << "Your choice -> ";
            getline(cin, choice);
        }
        
        if(choice == "1")
        {
            srand((unsigned)(time(0))); //create seed for random number to produce a size for the matrices on the quiz.
            int correct = 0;
            int numQuestions = 0;
            string keepGoing = "y";
            int randomRowSize, randomColumnSize;
            vector<int> nums;
            Matrix sum;
            
            while (keepGoing == "y")
            {
                randomRowSize = rand() % 3 + 2; //generate a random number between 2 and 6 inclusively.
                randomColumnSize = rand() % 3 + 2;
                
                Matrix a(randomRowSize, randomColumnSize);
                Matrix b(randomRowSize, randomColumnSize);
                a.randomFill();
                b.randomFill();
                sum = a + b;
                Matrix answer(randomRowSize, randomColumnSize);
                
                cout << endl << numQuestions + 1 << "." << endl << endl;
                a.printMatrix();
                cout << endl << "+" << endl << endl;
                b.printMatrix();
                cout << endl << "=" << endl << endl;

                cout << "Please enter your answer below:" << endl << endl;
                answer.getUserMatrix();
                
                if(!answer.isEqual(sum))
                {
                    cout << "\nNice try, but that is not the correct answer." << endl;
                    cout << "The correct answer was: " << endl << endl;
                    sum.printMatrix();
                }
                
                else
                {
                    cout << "\nGreat job! :D" << endl << endl;
                    correct++;
                }
                
                numQuestions++;
                
                cout << "Would you like to try another question? ('y' or 'Y' for yes or 'n' or 'N' for no)" << endl;
                cout << "Your choice -> ";
                getline(cin, keepGoing);
                keepGoing[0] = tolower(keepGoing[0]);
                
                while(keepGoing != "y" && keepGoing != "n")
                {
                    cout << "\n\nInvalid option! Please choose from the options listed:" << endl << endl;
                    cout << "Would you like to try another question? ('y' or 'Y' for yes or 'n' or 'N' for no)" << endl;
                    cout << "Your choice -> ";
                    getline(cin, keepGoing);
                    keepGoing[0] = tolower(keepGoing[0]);
                }
            }
    
            cout << "\nYour final score: " << (static_cast<double>(correct) / numQuestions) * 100 << "%" << endl;
        }
    }
    
    return 0;
}
