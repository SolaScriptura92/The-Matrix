/*
 
 This file contains the main program. It is a matrix calculator as well as a matrix operation quiz app. Features and challenges will be added as I continue in my studies of linear algebra and the uses of matrices in it.
 
 Code Author: Jose Sanchez Rodriguez
 
 */

#include <iostream>
#include "Matrix.h"

void displayMainMenu();
void displayMatrixOpsMenu();
void takeAdditionQuiz();
void takeMultiplicationQuiz();
void calculator();


int main()
{
    cout << "Hello, and welcome to my matrix calculator and quiz app!" << endl;
    displayMainMenu();
    cout << "\nThank you for using my program! :)" << endl << endl;
    
    return 0;
}



void displayMainMenu()
{
    string choice;
    
    cout << "\nPlease choose from the following options: " << endl << endl;
    cout << "1. Matrix operations quiz" << endl;
    cout << "2. Matrix calculator" << endl;
    cout << "3. Quit program" << endl << endl;
    cout << "Your choice -> ";
    getline(cin, choice);
    
    while(choice != "1" && choice != "2" && choice != "3")
    {
        cout << "\n\nInvalid option! Please choose from the options listed:" << endl << endl;
        cout << "1. Matrix operations quiz" << endl;
        cout << "2. Matrix calculator (coming soon!)" << endl << endl;
        cout << "Your choice -> ";
        getline(cin, choice);
    }
    
    if(choice == "1")
        displayMatrixOpsMenu();
    
    else if(choice == "2")
        calculator();
            
    else
        return;
}

void displayMatrixOpsMenu()
{
    string choice;
    
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
        takeAdditionQuiz();
    }
    
    else //must have been option 2 (multiplication)
    {
        takeMultiplicationQuiz();
    }
}

void takeAdditionQuiz()
{
    srand((unsigned)(time(0))); //create seed for random number to produce a size for the matrices on the quiz.
    int correct = 0;
    int numQuestions = 0;
    string keepGoing = "y";
    int randomRowSize, randomColumnSize;
    vector<int> nums;
    Matrix sum;
    string choice;
    
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
        
        cout << "\nWould you like to try another question? ('y' or 'Y' for yes or 'n' or 'N' for no)" << endl;
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
    
    cout << "\nPlease choose from the following options: " << endl << endl;
    cout << "1. Return to main menu" << endl;
    cout << "2. Quit program" << endl << endl;
    cout << "Your choice -> ";
    getline(cin, choice);
    
    while(choice != "1" && choice != "2")
    {
        cout << "\n\nInvalid option! Please choose from the following options::" << endl << endl;
        cout << "1. Return to main menu" << endl;
        cout << "2. Quit program" << endl << endl;
        cout << "Your choice -> ";
        getline(cin, choice);
    }
    
    if(choice == "1")
        displayMainMenu();
}

void takeMultiplicationQuiz()
{
    srand((unsigned)(time(0))); //create seed for random number to produce a size for the matrices on the quiz.
    int correct = 0;
    int numQuestions = 0;
    string keepGoing = "y";
    int randomRowSizeA, randomColumnSizeA, randomColumnSizeB;
    vector<int> nums;
    Matrix sum;
    string choice;
    
    while (keepGoing == "y")
    {
        randomRowSizeA = rand() % 3 + 2; //generate a random number between 2 and 6 inclusively.
        randomColumnSizeA = rand() % 3 + 2;
        randomColumnSizeB = rand() % 3 + 2;
        
        Matrix a(randomRowSizeA, randomColumnSizeA);
        Matrix b(randomColumnSizeA, randomColumnSizeB);
        a.randomFill();
        b.randomFill();
        sum = a * b;
        Matrix answer(randomRowSizeA, randomColumnSizeB);
        
        cout << endl << numQuestions + 1 << "." << endl << endl;
        a.printMatrix();
        cout << endl << "*" << endl << endl;
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
        
        cout << "\nWould you like to try another question? ('y' or 'Y' for yes or 'n' or 'N' for no)" << endl;
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
    
    cout << "\nPlease choose from the following options: " << endl << endl;
    cout << "1. Return to main menu" << endl;
    cout << "2. Quit program" << endl << endl;
    cout << "Your choice -> ";
    getline(cin, choice);
    
    while(choice != "1" && choice != "2")
    {
        cout << "\n\nInvalid option! Please choose from the following options::" << endl << endl;
        cout << "1. Return to main menu" << endl;
        cout << "2. Quit program" << endl << endl;
        cout << "Your choice -> ";
        getline(cin, choice);
    }
    
    if(choice == "1")
        displayMainMenu();
}

void calculator()
{
    string choice;
    string keepGoing = "y";
    
    while(keepGoing == "y")
    {
        
        cout << "\nPlease choose the matrix operation you would like to perform:\n" << endl;
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
            int rows, columns;
            string input;
            
            cout << "\nPlease enter the amount of rows in the matrices you will be adding -> ";
            getline(cin, input);
            
            while(input.find_first_not_of( "0123456789" ) != string::npos || (input.length() >= 2 && input[0] == '0'))
            {
                cout << "\nWhoops! Looks like you entered an invalid number." << endl;
                cout << "Please choose a number greater than or equal to zero." << endl;
                cout << "Enter the amount of rows in the matrices you will be adding -> ";
                getline(cin, input);
            }
            
            rows = stoi(input);
            
            cout << "\nPlease enter the amount of columns in the matrices you will be adding -> ";
            getline(cin, input);
            
            while(input.find_first_not_of( "0123456789" ) != string::npos || (input.length() >= 2 && input[0] == '0'))
            {
                cout << "\nWhoops! Looks like you entered an invalid number." << endl;
                cout << "Please choose a number greater than or equal to zero." << endl;
                cout << "Enter the amount of columns in the matrices you will be adding -> ";
                getline(cin, input);
            }
            
            columns = stoi(input);
            
            Matrix a(rows, columns);
            Matrix b(rows, columns);
            Matrix sum(rows, columns);
            
            cout << "\nFor the first matrix: \n" << endl;
            a.getUserMatrix();
            cout << "\n\n";
            cout << "For the second matrix: \n" << endl;
            b.getUserMatrix();
            cout << "\n\n";
            
            sum = a + b;
            
            a.printMatrix();
            cout << "\n+\n\n";
            b.printMatrix();
            cout << "\n=\n\n";
            sum.printMatrix();
            
        }
        
        else
        {
            int rowsA, columnsA, columnsB;
            string input;
            
            cout << "\nPlease enter the amount of rows in the first matrix you will be multiplying -> ";
            getline(cin, input);
            
            while(input.find_first_not_of( "0123456789" ) != string::npos || (input.length() >= 2 && input[0] == '0'))
            {
                cout << "\nWhoops! Looks like you entered an invalid number." << endl;
                cout << "Please choose a number greater than or equal to zero." << endl;
                cout << "Enter the amount of rows in the first matrix you will be adding -> ";
                getline(cin, input);
            }
            
            rowsA = stoi(input);
            
            cout << "\nPlease enter the amount of columns in the first matrix you will be multiplying -> ";
            getline(cin, input);
            
            while(input.find_first_not_of( "0123456789" ) != string::npos || (input.length() >= 2 && input[0] == '0'))
            {
                cout << "\nWhoops! Looks like you entered an invalid number." << endl;
                cout << "Please choose a number greater than or equal to zero." << endl;
                cout << "Enter the amount of columns in the first you will be multiplying -> ";
                getline(cin, input);
            }
            
            columnsA = stoi(input);
            
            cout << "\nPlease enter the amount of columns in the second matrix you will be multiplying -> ";
            getline(cin, input);
            
            while(input.find_first_not_of( "0123456789" ) != string::npos || (input.length() >= 2 && input[0] == '0'))
            {
                cout << "\nWhoops! Looks like you entered an invalid number." << endl;
                cout << "Please choose a number greater than or equal to zero." << endl;
                cout << "Enter the amount of columns in the second matrix you will be multiplying -> ";
                getline(cin, input);
            }
            
            columnsB = stoi(input);
            
            Matrix a(rowsA, columnsA);
            Matrix b(columnsA, columnsB);
            Matrix product(rowsA, columnsB);
            
            cout << "\nFor the first matrix: \n" << endl;
            a.getUserMatrix();
            cout << "\n\n";
            cout << "For the second matrix: \n" << endl;
            b.getUserMatrix();
            cout << "\n\n";
            
            product = a * b;
            
            a.printMatrix();
            cout << "\n*\n\n";
            b.printMatrix();
            cout << "\n=\n\n";
            product.printMatrix();
            
        }
        
        cout << "\nWould you like to perform another calculation? ('y' or 'Y' for yes or 'n' or 'N' for no)" << endl;
        cout << "Your choice -> ";
        getline(cin, keepGoing);
        keepGoing[0] = tolower(keepGoing[0]);
        
        while(keepGoing != "y" && keepGoing != "n")
        {
            cout << "\n\nInvalid option! Please choose from the options listed:" << endl << endl;
            cout << "Would you like to perform another calculation? ('y' or 'Y' for yes or 'n' or 'N' for no)" << endl;
            cout << "Your choice -> ";
            getline(cin, keepGoing);
            keepGoing[0] = tolower(keepGoing[0]);
        }
        
        if(keepGoing == "n")
        {
            cout << "\nWhat would you like to do now?" << endl << endl;
            cout << "1. Return to main menu" << endl;
            cout << "2. Quit program" << endl << endl;
            cout << "Your choice -> ";
            getline(cin, choice);
            
            while(choice != "1" && choice != "2")
            {
                cout << "\n\nInvalid option! Please choose from the following options::" << endl << endl;
                cout << "1. Return to main menu" << endl;
                cout << "2. Quit program" << endl << endl;
                cout << "Your choice -> ";
                getline(cin, choice);
            }
            
            if(choice == "1")
                displayMainMenu();
        }
    }
}
