#ifndef _MATRIX_H_
#define _MATRIX_H_

class Matrix
{
public:
   unsigned int m_row;
   unsigned int m_col;

   double **val; // Matrix element pointer

public:
   /**
   * Initializing Matrix Elements
   * 
   * @param row row dimensions of the matrix created
   * @param col column dimensions of the matrix created
   * @return a Matrix object having dimensions of rowxcolumn each element initialized to 0 
   */
   explicit Matrix(unsigned int, unsigned int); // Constructor from dimensions

   Matrix(const Matrix &); //Copy constructor
   virtual ~Matrix();      //Destructor

   /**
   * Get matrix elements
   * 
   * @param row the row-id of the element in the Matrix object
   * @param col the column-id of the element in the Matrix object
   * @return The element located at the provided index. Returned as double datatype
   * @throws A string which tells the error details
   */
   double &operator()(unsigned int row, unsigned int col);

   /**
   * Assignment Operator
   * 
   * @param mat Provide another matrix on the right hand side of the =
   * @return a new matrix object which contains values similar to the original matrix
   * @throws A string which tells the error details
   */
   Matrix &operator=(const Matrix &);

   /**
   * Matrix multiplication
   * 
   * @param mat Another matrix object which should be multiplied with the current Matrix object
   * @return A new Matrix object containing the result of Matrix multiplication
   * @throws A string which tells the error details
   */
   Matrix operator*(const Matrix &)const;

   /**
   * Scalar multiplication
   * 
   * @param in_val double value which should be multiplied with the current Matrix object
   * @return A new Matrix object containing the result of scalar multiplication
   */
   Matrix operator*(const double &)const;

   /**
   * Matrix Transpose
   * 
   * @return A new Matrix object containing the result of transpose
   */
   Matrix transpose() const;

   /**
   * Checking two matrices for equality element wise
   * 
   * @param mat Another matrix whose values should be compared to current Matrix object's values
   * @return A boolean which tells whether equal or not
   */
   bool equals(const Matrix &) const;

   /**
   * Printing the Matrix
   * 
   * @return Prints the values to console
   */
   void print() const;
};

#endif