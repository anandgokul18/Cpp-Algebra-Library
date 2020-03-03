//--------------------------------------------------//
// File Name: matrix.cpp                            //
// Function: Matrix calculation                     //
//--------------------------------------------------//

//------------------------------------------//
//              Including Headers      	  //
//------------------------------------------//
#include "matrix.h"
#include <string>
#include <iostream>

//------------------------------------------//
//              Namespace                   //
//------------------------------------------//
using namespace std;

/**
 * Initializing Matrix Elements
 * 
 * @param row row dimensions of the matrix created
 * @param col column dimensions of the matrix created
 * @return a Matrix object having dimensions of rowxcolumn each element initialized to 0 
*/
Matrix::Matrix(unsigned int row, unsigned int col) : m_row(row), m_col(col)
{
   // Generate Row elements
   val = new double *[m_row];

   for (unsigned int i = 0; i < m_row; i++)
   {
      // Generate Column Elements
      val[i] = new double[m_col];
   }

   // Initialize elements to 0
   for (unsigned int i = 0; i < m_row; i++)
   {
      for (unsigned int j = 0; j < m_col; j++)
      {
         val[i][j] = 0;
      }
   }
}

// Initialize matrix elements with objects
Matrix::Matrix(const Matrix &mat) : m_row(mat.m_row), m_col(mat.m_col)
{
   // Column object creation
   val = new double *[m_row];

   for (unsigned int i = 0; i < m_row; i++)
   {
      // Row object creation
      val[i] = new double[m_col];
   }

   // Initializing
   for (unsigned int i = 0; i < m_row; i++)
   {
      for (unsigned int j = 0; j < m_col; j++)
      {
         val[i][j] = mat.val[i][j];
      }
   }
}

// Destructor
Matrix::~Matrix()
{
   // Delete object
   for (unsigned int i = 0; i < m_row; i++)
   {
      delete[] val[i];
   }

   delete[] val;
}

/**
 * Get matrix elements
 * 
 * @param row the row-id of the element in the Matrix object
 * @param col the column-id of the element in the Matrix object
 * @return The element located at the provided index. Returned as double datatype
 * @throws A string which tells the error details
 */
double &Matrix::operator()(unsigned int row, unsigned int col)
{
   if (row >= m_row || col > m_col)
   {
      string err = "Exception Encountered: Accessing Index out of bounds";
      throw err;
   }
   return val[row][col];
}

/**
 * Assignment Operator
 * 
 * @param mat Provide another matrix on the right hand side of the =
 * @return a new matrix object which contains values similar to the original matrix
 * @throws A string which tells the error details
 */
Matrix &Matrix::operator=(const Matrix &mat)
{
   // When the number of rows and columns is not equal between matrices
   if (m_row != mat.m_row || m_col != mat.m_col)
   {
      string err = "Exception Encountered: Matrix can't be substituted";
      throw err;
   }

   for (unsigned int i = 0; i < m_row; i++)
   {
      for (unsigned int j = 0; j < m_col; j++)
      {
         val[i][j] = mat.val[i][j];
      }
   }

   return *this;
}

/**
 * Matrix multiplication
 * 
 * @param mat Another matrix object which should be multiplied with the current Matrix object
 * @return A new Matrix object containing the result of Matrix multiplication
 * @throws A string which tells the error details
 */
Matrix Matrix::operator*(const Matrix &mat) const
{
   // Handling case when no. of cols of matrix 1 doesn't match number of rows of matrix 2
   if (m_col != mat.m_row)
   {
      string err = "Exception Encountered: Matrix can't be producted since Column of first matrix should be equal to row of second matrix";
      throw err;
   }

   // Generating Solution
   Matrix matAns(m_row, mat.m_col);

   // Matrix Multiplication Operation
   for (unsigned int i = 0; i < m_row; i++)
   {
      for (unsigned int j = 0; j < mat.m_col; j++)
      {
         for (unsigned int k = 0; k < m_col; k++)
         {
            matAns.val[i][j] += val[i][k] * mat.val[k][j];
         }
      }
   }

   return matAns;
}

/**
 * Scalar multiplication
 * 
 * @param in_val double value which should be multiplied with the current Matrix object
 * @return A new Matrix object containing the result of scalar multiplication
 */
Matrix Matrix::operator*(const double &in_val) const
{
   // Result matrix creation
   Matrix matAns(m_row, m_col);

   for (unsigned int i = 0; i < m_row; i++)
   {
      for (unsigned int j = 0; j < m_col; j++)
      {
         matAns.val[i][j] = val[i][j] * in_val;
      }
   }

   return matAns;
}

/**
 * Matrix Transpose
 * 
 * @return A new Matrix object containing the result of transpose
 */
Matrix Matrix::transpose() const
{
   // Result Matrix
   Matrix matAns(m_col, m_row);

   for (unsigned int i = 0; i < m_row; i++)
   {
      for (unsigned int j = 0; j < m_col; j++)
      {
         matAns.val[j][i] = val[i][j];
      }
   }

   return matAns;
}

/**
 * Checking two matrices for equality element wise
 * 
 * @param mat Another matrix whose values should be compared to current Matrix object's values
 * @return A boolean which tells whether equal or not
 */
bool Matrix::equals(const Matrix &mat) const
{
   if (m_row != mat.m_row)
   {
      return false;
   }
   if (m_col != mat.m_col)
   {
      return false;
   }
   for (unsigned int i = 0; i < m_row; i++)
   {
      for (unsigned int j = 0; j < m_col; j++)
      {
         if (val[i][j] == mat.val[i][j])
         {
            ;
         }
         else
         {
            return false;
         }
      }
   }
   return true;
}

/**
 * Printing the Matrix
 * 
 * @return Prints the values to console
 */
void Matrix::print() const
{

   for (unsigned int i = 0; i < m_row; i++)
   {
      for (unsigned int j = 0; j < m_col; j++)
      {
         cout << val[i][j] << " ";
      }

      cout << endl;
   }
}