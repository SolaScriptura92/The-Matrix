//
//  main.cpp
//  MatrixApp
//
//  Created by Jose on 5/22/19.
//  Copyright © 2019 Jose'sProjects. All rights reserved.
//

#include <iostream>
#include "Matrix.h"

int main()
{
    Matrix x(2, 4); //1 row, 4 columns
    Matrix y(2, 4); //1 row, 4 columns
    
    y.setValue(0, 1, 3); // set row 0 (which is 1 in compsci), column 1 to 3
    x.setValue(0, 2, 5); // set row 0, column 2 (really 3) to 5.
    
    Matrix z;
    z = x + y; //make the new object created above (z) equal to the sum of the matrices
    
    cout << "First Matrix: " << endl << endl;
    
    x.printMatrix();
    
    cout << endl << endl << "+" << endl << endl;
    
    cout << "Second Matrix: " << endl << endl;
    
    y.printMatrix();
    
    cout << endl << endl << "=" << endl << endl;
    
    z.printMatrix();
    
    return 0;
}
