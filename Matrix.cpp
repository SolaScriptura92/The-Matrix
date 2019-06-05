/*
 Matrix.cpp
 MatrixApp
 This is the defined body of the Matrix class. It works in conjunction with the Matrix.h file to fully define the class.
 It contains the function definitions.
 */

#include <stdio.h>
#include "Matrix.h"

Matrix::Matrix(int rows, int columns)
{
    vector<int> vect(columns,0);
    
    for(int i = 0; i < rows; i++)
        matrix.push_back(vect);
}

void Matrix::printMatrix()
{
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        
        cout << endl;
    }
}

int Matrix::getNumRows()
{
    return matrix.size();
}

int Matrix::getNumColumns()
{
    return matrix[0].size();
}

int Matrix::getValue(int row, int column)
{
    return matrix[row][column];
}

void Matrix::setValue(int row, int column, int value)
{
    matrix[row][column] = value;
}

Matrix Matrix::operator+(Matrix &a) //this function (overloaded '+' operator) adds two matrices together
{
    Matrix sumMatrix(a.getNumRows(), a.getNumColumns());
    
    for(int i = 0; i < a.getNumRows(); i++)
    {
        for(int j = 0; j < a.getNumColumns(); j++)
        {
            sumMatrix.matrix[i][j] = this->getValue(i, j) + a.getValue(i, j);
        }
    }
    
    return sumMatrix;
}

Matrix Matrix::operator-(Matrix &a) //this function substracts to the right of it from the matrix to the left of it.
{
    
    Matrix differenceMatrix(a.getNumRows(), a.getNumColumns());
    
    for(int i = 0; i < a.getNumRows(); i++)
    {
        for(int j = 0; j < a.getNumColumns(); j++)
        {
            differenceMatrix.matrix[i][j] = this->getValue(i, j) - a.getValue(i, j);
        }
    }
    
    return differenceMatrix;
}

Matrix Matrix::operator*(Matrix &a)
{
    Matrix emptyMatrix;
    
    if(this->getNumColumns() == a.getNumRows())
    {
        Matrix productMatrix(this->getNumRows(), a.getNumColumns());
        
        int sum = 0;

        for(int k = 0; k < this->getNumRows(); k++) //changes rows to next row...
        {
            for(int l = 0; l < a.getNumColumns(); l++) //changes to next column.
            {
                for(int m = 0; m < a.getNumRows(); m++)
                {
                    sum += this->getValue(k, m) * a.getValue(m, l);
                }
                        
                productMatrix.matrix[k][l] = sum;
                sum = 0;
            }
        }
        
        return productMatrix;
    }
    
    else
    {
        Matrix emptyMatrix;
        return emptyMatrix;
    }
}

Matrix Matrix::transpose()
{
    
    Matrix transposedMatrix(getNumColumns(), getNumRows());
    
    for(int i = 0; i < getNumRows(); i++)
    {
        for(int j = 0; j < getNumColumns(); j++)
        {
            transposedMatrix.matrix[j][i] = matrix[i][j];
        }
    }
    
    return transposedMatrix;
}

bool Matrix::isRowEchelonForm()
{
    vector<int> leadingEntryColumnNumbers;
    bool containsAllZeros = true;
    vector<int> rowsWithAllZeros;
    vector<int> rowsWithSomeNonZero;
    
    for(int i = 0; i < this->getNumRows(); i++) //changes row
    {
        for(int j = 0; j < this->getNumColumns(); j++) //changes column
        {
            if(this->matrix[i][j] != 0) //spotted first nonzero
            {
                
                if(this->matrix[i][j] != 1) //leading entry is not one
                {
                    return false;
                }
                
                else
                {
                    containsAllZeros = false;
                    leadingEntryColumnNumbers.push_back(j);
                    break;
                }
            }
        }
        
        if(containsAllZeros)
        {
            rowsWithAllZeros.push_back(i);
        }
        
        else
        {
            rowsWithSomeNonZero.push_back(i);
            containsAllZeros = true;
        }
    }
    
    //at this point, the first condition will have been checked for already, and the info is there to check the other two.
    
    for(int k = 0; k < leadingEntryColumnNumbers.size() - 1; k++) //checks second condition (i.e., each leading entry is in a
    {                                                             //to the right of the previous row.
        if(leadingEntryColumnNumbers[k + 1] <= leadingEntryColumnNumbers[k])
        {
            return false;
        }
    }
    
    if(!rowsWithAllZeros.empty()) //checks to make sure rows with all zero elements are below rows that have a non zero element.
    {
        for(int m = 0; m < rowsWithAllZeros.size(); m++)
        {
            if(rowsWithAllZeros[m] < rowsWithSomeNonZero[rowsWithSomeNonZero.size() - 1])
            {
                return false;
            }
        }
    }
    
    return true;
}

bool Matrix::isReducedRowEchelonForm()
{
    if(this->isRowEchelonForm()) //must be in row echelon form for the possibility of it being in reduced row echelon form.
    {
        vector<int> leadingEntryIndices;
        int numZeros = 0;
        
        for(int i = 0; i < this->getNumRows(); i++)
        {
            for(int j = 0; j < this->getNumColumns(); j++)
            {
                if(this->getValue(i, j) != 0)
                {
                    leadingEntryIndices.push_back(j); //stores the column number leading non zero appears in.
                }
            }
        }
        
        //Now check columns to make sure they are the only non zero in their respective column.
        
        for(int r = 0; r < leadingEntryIndices.size(); r++)
        {
            for(int s = 0; s < this->getNumRows(); s++)
            {
                if(this->getValue(s, leadingEntryIndices[r]) == 0)
                {
                    numZeros++;
                }
            }
            
            if(numZeros != this->getNumRows() - 1)
            {
                return false;
            }
    
            numZeros = 0;
        }
        
        return true;
    }
    
    else
    {
        return false;
    }
}

void Matrix::randomFill()
{
    
    for(int i = 0; i < this->getNumRows(); i++)
    {
        for(int j = 0; j < this->getNumColumns(); j++)
        {
            this->setValue(i, j, rand() % 10); //rand() % 10 produces random numbers between 0 and 9, inclusively.
        }
    }
}

void Matrix::getUserMatrix()
{
    string row;
    vector<int> nums;
    
    for(int i = 0; i < this->getNumRows(); i++) //get each row from the user.
    {
        cout << "Please enter row " << i + 1 << " -> "; //program crashes here.
        getline(cin, row);
        
        while(!this->isValidRow(row, this->getNumColumns(), nums))
        {
            cout << "\nWhoop! Looks like the row you entered is not valid." << endl;
            cout << "Please ensure that the row has as many numbers as the matrix has columns." << endl;
            cout << "Extra spaces in between numbers are ignored." << endl << endl;
            cout << "Please enter row " << i + 1 << " -> ";
            getline(cin, row);
            nums.clear();
        }
        
        for(int j = 0; j < nums.size(); j++)
        {
            this->setValue(i, j, nums[j]);
        }
        
        nums.clear();
    }
}

bool Matrix::isValidRow(string row, int columns, vector<int> &numbers)
{
    /*things to check for:
        1. each string must contain only digits, negative signs, and spaces.
        2. negative sign must be right before a valid digit (non zero)
        3. the numbers in the string must be equal to the number of columns in the matrix.
        4. make sure small input edge cases are covered.
     */
    
    //The algorithm appends a space at the end to the string to make for easier edge case processing.
    row += " ";
    
    if(row.find_first_not_of("0123456789- ") != string::npos && row != "") //if there exists a non-valid character in the string and it's not equal to the empty string.
    {
        return false;
    }
    
    else //from here we know all characters are valid. Check 1. is satisfied. Now check condition 2 (valid placement of negative sign)
    {
        if(row[row.length() - 1] == '-') //if the last character is a negative sign, it is invalid because not followed by a number
        {
            return false;
        }
        
        else //if it is not, then check for valid placement in the rest of the string.
        {
            //since correct negative sign placement can only exist when at least two or more characters are in the string, deal with
            //the cases in which the string is empty or only one character is present (the latter case is handled by the 'if' statement above
            
            if(row.length() == 1) //empty string represents an empty matrix. Or if the length is one, at this point we know it is  simply a digit.
                return true;
        
            else //check for valid negative string placement in strings with at least two characters.
            {
                for(int i = 0; i < row.length() - 2; i++) //check up to second to last character in the string
                {
                    if(row[i] == '-' && (row[i + 1] == '0' || row[i + 1] == '-' || row[i + 1] == ' ')) //if a negative sign is followed by a space, '0', or another negative sign
                    {
                        return false;
                    }
                }
            }
        }
        
        //at this point, checks 1, 2, and 4 have been successfully made. Now check for #3.
        //now step through the string and gather numbers as substrings along the way. keep in mind that there may be leading space, trailing space, and space in between numbers.
        //BE SURE TO ACCOUNT FOR THE INVALID ENTERING OF A NUMBER THAT IS NOT ZERO BUT BEGINS WITH A ZERO!
        //Since we know negative signs are in the correct place, -3234-15 would count at the two numbers -3234 and -15 rather than being rejected as invalid.
        //So we assume the user forget to enter a space in between.
        
        string num = "";
        bool startedNum = false;
        
        for(int x = 0; x < row.length(); x++)
        {
            if((isdigit(row[x]) || row[x] == '-') && !startedNum) //if you're just starting a new number
            {
                num += row[x];
                startedNum = true;
            }
            
            else if(startedNum == true) //if you have already started a number
            {
                if(row[x] == ' ' || row[x] == '-') //then the number ends. Push back the current number stored.
                {
                    //since we already made sure '-' is not followed by a zero. make sure that if a number has more than two digits, and begins with a zero, you return false.
                    if((num.length() >= 2 && num[0] == '0') || (num[num.length() - 1] == '-' && x == row.length() - 1))
                        return false;
                    
                    else
                        numbers.push_back(stoi(num));
                    
                    num = "";
                    
                    if(row[x] == ' ' || (row[x] == '-' && x == row.size() - 1))
                        startedNum = false;
                    
                    else
                    {
                        startedNum = true;
                        num += row[x];
                    }
                }
                
                else
                    num += row[x];
            }
        }
        
        if(numbers.size() != columns)
            return false;
        
        else
            return true;
    }
}

bool Matrix::isEqual(Matrix &x)
{
    for(int i = 0; i < this->getNumRows(); i++)
    {
        for(int j = 0; j < this->getNumColumns(); j++)
        {
            if(this->getValue(i, j) != x.getValue(i, j))
                return false;
        }
    }
    
    return true;
}
