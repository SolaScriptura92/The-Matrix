//
//  Matrix.h
//  MatrixApp
//
//  Created by Jose on 5/22/19.
//  Copyright © 2019 Jose'sProjects. All rights reserved.
//

#ifndef Matrix_h
#define Matrix_h

#include <vector>
#include <iostream>
using namespace std;

class Matrix
{
private:
    vector<vector<int>> matrix;
    
    
public:
    Matrix(int rows = 0, int columns = 0);
    void printMatrix();
    
};


#endif /* Matrix_h */
