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
