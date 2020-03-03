#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "algebralib.h"
#include <string>

/**
 * A C++ Unit test class for Matrix.
 * Using the Unit testing framework provided by Catch2
 */

TEST_CASE("Matrix Creation and Values Setting")
{
   SECTION("Creating a matrix, sets its elements, then gets the elements and checks for correctness.")
   {
      Matrix matA(2, 2);
      matA(0, 0) = 3;
      matA(0, 1) = 2;
      matA(1, 0) = 5;
      matA(1, 1) = 4;

      REQUIRE(matA(0, 0) == 3);
      REQUIRE(matA(0, 1) == 2);
      REQUIRE(matA(1, 0) == 5);
      REQUIRE(matA(1, 1) == 4);
   }
}
TEST_CASE("Matrix Creation and Values Setting- Out-of-bounds cases")
{
   //Tests the handling of out-of-bounds index errors in Matrix accesses.
   //Note that the assertions indicate the exact wording of the exception messages.
   SECTION("Setting row elements out of bounds")
   {
      Matrix matB(4, 3);

      try
      {
         matB(4, 2) = 10; //row 4 is out of bounds
      }
      catch (std::string e)
      {
         REQUIRE(e == "Exception Encountered: Accessing Index out of bounds");
      }
   }

   SECTION("Setting column elements out of bounds")
   {
      Matrix matC(4, 3);

      try
      {
         matC(2, 4) = 10; //column 4 is out of bounds
      }
      catch (std::string e)
      {
         REQUIRE(e == "Exception Encountered: Accessing Index out of bounds");
      }
   }

   SECTION("Retreiving row elements out of bounds")
   {
      Matrix matD(2, 2);

      try
      {
         double d14 = matD(4, 1); //row 4 is out of bounds
      }
      catch (std::string e)
      {
         REQUIRE(e == "Exception Encountered: Accessing Index out of bounds");
      }
   }

   SECTION("Retreiving column elements out of bounds")
   {
      Matrix matE(3, 3);

      try
      {
         double e23 = matE(2, 3); //column 3 is out of bounds
      }
      catch (std::string e)
      {
         REQUIRE(e == "Exception Encountered: Accessing Index out of bounds");
      }
   }
}

TEST_CASE("Testing Assignment")
{
   Matrix matF(2, 2);
   matF(0, 0) = 3;
   matF(0, 1) = 2;
   matF(1, 0) = 5;
   matF(1, 1) = 4;

   SECTION("Illegal Assignment")
   {
      Matrix matG(3, 2);
      try
      {
         matG = matF;
      }
      catch (std::string e)
      {
         REQUIRE(e == "Exception Encountered: Matrix can't be substituted");
      }
   }

   SECTION("Valid Assignment")
   {
      Matrix matH(2, 2);

      matH = matF;

      REQUIRE(matH.equals(matF));
   }

   SECTION("Size different")
   {
      Matrix matI(2, 2);
      Matrix matJ(2, 3);
      Matrix matK(3, 2);

      REQUIRE(matI.equals(matJ) == false);
      REQUIRE(matI.equals(matK) == false);
   }
}

TEST_CASE("Matrix Multiplication with another matrix")
{
   //Initializing Matrix m1
   Matrix m1(4, 3);
   m1(0, 0) = 3;
   m1(0, 1) = 2;
   m1(0, 2) = 5;
   m1(1, 0) = 2;
   m1(1, 1) = 4;
   m1(1, 2) = 3;
   m1(2, 0) = 6;
   m1(2, 1) = 5;
   m1(2, 2) = 1;
   m1(3, 0) = 1;
   m1(3, 1) = 6;
   m1(3, 2) = 4;

   //Initializing Matrix m4
   Matrix m4(3, 2);
   m4(0, 0) = 2;
   m4(0, 1) = 3;
   m4(1, 0) = 4;
   m4(1, 1) = 2;
   m4(2, 0) = 3;
   m4(2, 1) = 4;

   //Initializing Matrix m5
   Matrix m5(4, 2);
   m5(0, 0) = 29;
   m5(0, 1) = 33;
   m5(1, 0) = 29;
   m5(1, 1) = 26;
   m5(2, 0) = 35;
   m5(2, 1) = 32;
   m5(3, 0) = 38;
   m5(3, 1) = 31;

   SECTION("Matrix 1 column and Matrix 2 row different")
   {
      try
      {
         Matrix res1 = m1 * m5;
      }
      catch (std::string e)
      {
         REQUIRE(e == "Exception Encountered: Matrix can't be producted since Column of first matrix should be equal to row of second matrix");
      }
   }
   SECTION("Valid Matrix multiplication")
   {
      Matrix res2 = m1 * m4;
      REQUIRE(res2.equals(m5));
   }
}

TEST_CASE("Matrix Multiplication with Scalar and Equality checker modules")
{
   Matrix matL(2, 3);
   matL(0, 0) = 3;
   matL(0, 1) = 2;
   matL(0, 2) = 8;
   matL(1, 0) = 5;
   matL(1, 1) = 4;
   matL(1, 2) = 9;

   Matrix matM = matL * 10;

   SECTION("Multiply with scalar")
   {

      Matrix matN(2, 3);
      matN(0, 0) = 30;
      matN(0, 1) = 20;
      matN(0, 2) = 80;
      matN(1, 0) = 50;
      matN(1, 1) = 40;
      matN(1, 2) = 90;

      REQUIRE(matM.equals(matN));
   }

   SECTION("Testing equality checking module")
   {

      Matrix matO(3, 2);
      matO(0, 0) = 30;
      matO(0, 1) = 22;
      matO(0, 2) = 80;
      matO(1, 0) = 50;
      matO(1, 1) = 40;
      matO(1, 2) = 90;

      REQUIRE(matM.equals(matO) == false);
   }
}
TEST_CASE("Matrix Transpose")
{
   SECTION("Transpose")
   {
      Matrix matP(2, 3);
      matP(0, 0) = 3;
      matP(0, 1) = 2;
      matP(0, 2) = 8;
      matP(1, 0) = 5;
      matP(1, 1) = 4;
      matP(1, 2) = 9;

      Matrix matQ = matP.transpose();

      Matrix matR(3, 2);
      matR(0, 0) = 3;
      matR(0, 1) = 5;
      matR(1, 0) = 2;
      matR(1, 1) = 4;
      matR(2, 0) = 8;
      matR(2, 1) = 9;

      REQUIRE(matR.equals(matQ));
   }
}