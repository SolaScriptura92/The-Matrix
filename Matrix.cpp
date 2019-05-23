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
