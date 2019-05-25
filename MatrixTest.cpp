/*
    This file contains certain tests to ensure correct functionality of the Matrix class (both the Matrix.h and Matrix.cpp files).
    The comments above each section of code will describe what the code is meant to test, and the correct behavior that should be
    exhibited by the program.
 
    Code Author: Jose Sanchez Rodriguez
*/

#include <iostream>
#include "Matrix.h"

int main()
{
/*
    The code should create two different Matrix objects ('x' and 'y').
    The both objects should be instantiated it's 2D vector with 2 rows and 4 columns (2 x 4 matrices).
    Furthermore, they should be filled with zeros.
 */
    Matrix x(2, 4);
    Matrix y(2, 4);
    
/*
    The code should print out both of the matrices (x and y, respectively), separated by two blank lines.
 */
    
    x.printMatrix();
    cout << endl << endl;
    y.printMatrix();
    cout << endl << endl;
    
/*
    (Keep in mind that we begin counting rows and columns at 0 for the next piece of code)
    The code should set the value in matrix 'x', row 1, column 3, to 3.
    It should also set the value in matrix 'y', row 1, column 2, to 5.
*/
    x.setValue(0, 2, 5);
    y.setValue(0, 1, 3);
    
/*
    The code should simply print both matrices again to ensure the correct updates were made by the code above.
 */
    
    x.printMatrix();
    cout << endl << endl;
    y.printMatrix();
    cout << endl << endl;
    
/*
    The code should create a new Matrix object 'z'. Since we are not passing it parameter, it should create an empty matrix,
    since that is what the default values are in the constructor.
    After creating the object, it should sum the 'x' and 'y' objects together, resulting in a new object which is then assigned to 'z'.
    Thus, the '+' overload is being tested to ensure that the matrices of each object to the left and to the right of it are summed together.
 */
    Matrix z;
    z = x + y;

/*
    The code should now print both our 'x' and 'y'(first and second) matrices, as well as their sum which should now be stored in 'z'.
 */
    cout << "First Matrix: " << endl << endl;
    
    x.printMatrix();
    
    cout << endl << endl << "   +" << endl << endl;
    
    cout << "Second Matrix: " << endl << endl;
    
    y.printMatrix();
    
    cout << endl << endl << "   =" << endl << endl;
    
    z.printMatrix();
    
/*
    The code creates a new Matrix object, 'w', with 2 rows and 4 columns. It then stores the values 7, 9, -2, and 2 inside of it.
    Then it creates another Matrix object, 'diffWandZ', that stores the difference between matrices w and z.
    It then prints out the computation and it's result, as the code above.
 */
    
    Matrix w(2, 4);
    
    w.setValue(1, 0, 7);
    w.setValue(0, 3, 9);
    w.setValue(0, 1, -2);
    w.setValue(0, 2, 2);
    
    Matrix diffWandZ = w - z;
    
    cout << endl << endl << "Matrix w: " << endl << endl;
    
    w.printMatrix();
    
    cout << endl << endl << "   -" << endl << endl;
    
    cout << "Matrix z: " << endl << endl;
    
    z.printMatrix();
    
    cout << endl << endl << "   =" << endl << endl;
    
    diffWandZ.printMatrix();
    
    return 0;
}

