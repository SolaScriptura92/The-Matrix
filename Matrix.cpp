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
