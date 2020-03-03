#include "algebralib.h"
#include <iostream>
#include <string>

int main()
{
   try
   {
      // Initialize a matrix with the number of rows and columns. All values will be set to zero
      Matrix matA(3, 2);
      Matrix matB(2, 3);

      // Set elements of the matrix individually
      matA(0, 0) = 00;
      matA(0, 1) = 01;
      matA(1, 0) = 10;
      matA(1, 1) = 11;
      matB(0, 0) = 33;
      matB(0, 1) = 34;
      matB(1, 0) = 43;
      matB(1, 1) = 44;

      // Retrieve elements
      double a01 = matA(0, 1);
      double b22 = matB(1, 1);

      // Multiplication and division of matrixes
      Matrix matC = matA * matB;

      int val = 10;

      // Multiplication and division of a matrix and a scholar
      Matrix matD = matB * val;

      // Transpose
      Matrix matE = matD.transpose();

      //Printing out matrix
      std::cout << std::endl;
      matD.print();
      std::cout << std::endl;
      std::cout << std::endl;
      matE.print();
      std::cout << std::endl;
      std::cout << std::endl;
   }
   catch (std::string e)
   {
      std::cout << e << std::endl;
   }

   std::cout << "Example run completed successfully!" << std::endl;
   return 0;
}