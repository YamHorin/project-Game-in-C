#ifndef _Q1_
#define _Q1_

int doFindMaxSubMatrix (int* mat  , int cols , int rows ,  int miniMatCols , int miniMatRows ,  int* topLine , int* LeftRow);
void biggestMatrixSum();
void initMatrixRandom( int* mat ,int cols , int rows);
void printMatrix(int* mat ,int cols , int rows);
void getValuesFromUser (int Maxcols , int Maxrows , int* cols , int* rows);
void PrintMatInThisSpace(int* mat,int colsStart , int rowsStart , int colsEnd , int rowsEnd);


#endif

