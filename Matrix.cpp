//
//  Matrix.cpp
//
//  Matrix.cpp
//  MatrixApp
//
//  Created by Jose on 5/22/19.
//  Copyright © 2019 Jose'sProjects. All rights reserved.
//

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

Matrix Matrix::operator+(Matrix &a) //this function will add two matrices
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
