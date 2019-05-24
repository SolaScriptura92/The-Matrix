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
    Matrix x(1, 4);
    
    x.printMatrix();
    
    cout << "columns: " << x.getNumColumns() << endl;
    cout << "rows: " << x.getNumRows() << endl;
    
    return 0;
}
