#ifndef _Q2_
#define _Q2_

int expandColor(int* mat  , int cols , int rows  , int colorNumber ,  int turn  , int StartLine , int StartRow );
void colorGame();
void colorTheBoard(int* mat  , int cols , int rows  , int* matColor , int numberOfColors);
void printMatrix2(int* mat ,int rows , int cols );
void MakePointStartForColors(int* mat , int colsBigMat , int rowsBigMat , int colorNumber ,int* matColor );
void allzeromat(int* mat  , int cols , int rows );
int IsTheGameOver(int* mat  , int cols , int rows );
void AllZeroArr(int* arr ,int size);
void WhoIsTheWinner(int* arr ,int size);


#endif
