#include "algebralib.h"
#include <iostream>

void calcMatrix();

int main()
{
   calcMatrix();
   return 0;
}

void calcMatrix()
{
   // Initialize a matrix with the number of rows and columns. All values will be set to zero
   Matrix matA(3, 2);
   std::cout << "-------matA---------" << std::endl;
   matA.print();
   Matrix matB(2, 3);
   std::cout << "-------matB--------" << std::endl;
   matB.print();

   // Set elements of the matrix individually
   matA(0, 0) = 00;
   matA(0, 1) = 01;
   matA(1, 0) = 10;
   matA(1, 1) = 11;
   matB(0, 0) = 33;
   matB(0, 1) = 34;
   matB(1, 0) = 43;
   matB(1, 1) = 44;
   std::cout << "-------matA---------" << std::endl;
   matA.print();
   std::cout << "-------matB--------" << std::endl;
   matB.print();

   // Retrieve elements
   double a01 = matA(0, 1);
   std::cout << "-------matA [01]---------" << std::endl;
   std::cout << a01 << std::endl;
   std::cout << "-------matB [22]---------" << std::endl;
   double b22 = matB(1, 1);
   std::cout << b22 << std::endl;

   // Multiplication and division of matrixes
   Matrix matC = matA * matB;
   std::cout << "-------matC---------" << std::endl;
   matC.print();

   int val = 10;

   // Multiplication and division of a matrix and a scholar
   Matrix matD = matB * val;
   std::cout << "-------matD--------" << std::endl;
   matD.print();

   // Transpose
   Matrix matE = matD.transpose();
   std::cout << "-------matE--------" << std::endl;
   matE.print();
}