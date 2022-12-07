#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#define N 20
#define Max 100
#define Min 1
#include "Question1.h"
int doFindMaxSubMatrix (int* mat  , int cols , int rows ,  int miniMatCols , int miniMatRows ,  int* topLine , int* LeftRow)
{
	int max=0;
	int current;
	for(int i =0; i< cols ; i++)
	{
		for (int j=0; j<rows ; j++)
		{
			current =0;
			for (int p =i ; p<(i+miniMatCols) ; p++) // loop for the mini matrix ,start with the i until the finish line
			{
				for (int k= j ; k<(j+miniMatRows) ;k++) // loop for the mini matrix ,start with the j until the finish line
				{
					current = current + *(mat +miniMatCols*p+k);
				}
				
			}
			if (current >max)
			{
				max = current;
				*topLine = i; //put value in the pointer
				*LeftRow =j; //put value in the pointer
			}
			
		}
	}
	return max;
}
void biggestMatrixSum()// the main fuction
{
	int max;
	int ROWS =N;
	int COLS =N;
	int miniRoWs , miniCOLS;
	int topLine , leftRow;
	printf("the ROWS of the matrix are %d and the COLS of the matrix %d  \n" , ROWS ,COLS);
	getValuesFromUser(N,N ,&COLS , &ROWS);
	int mat [ROWS][COLS];
	initMatrixRandom((int*)mat ,COLS , ROWS );
	printMatrix((int*)mat ,COLS , ROWS);
	getValuesFromUser(COLS,ROWS ,&miniCOLS , &miniRoWs);
	max=doFindMaxSubMatrix ((int*)mat, COLS, ROWS ,  miniCOLS , miniRoWs  ,  &topLine , &leftRow);
	printf("%d \n",max);
	PrintMatInThisSpace((int*)mat ,topLine , leftRow , (topLine+miniCOLS) , (leftRow+miniRoWs));
	
	
	
}
void PrintMatInThisSpace(int* mat,int colsStart , int rowsStart , int colsEnd , int rowsEnd) //function for print the Max mini matrix
{
	int cols  = colsEnd-colsStart;
	for (int i =colsStart; i< colsEnd; i++ )
	{
		for (int j =rowsStart ; j< rowsEnd ; j++)
		{
			printf("%d ", *(mat +cols*i+j));
		}
		printf("\n");
	}
}
void initMatrixRandom( int* mat ,int cols , int rows)//function for put randim numbers in the matrix
{
	int num;
	for (int i =0; i< cols; i++ )
	{
		for (int j =0; j< rows ; j++)
		{
			num = Min+(rand()%(Max-Min+1));
			*(mat +cols *i+j) = num;	
		}
	}
}
void getValuesFromUser (int Maxcols , int Maxrows , int* cols , int* rows) //function for get values from the user for the matrix and the mini matrix
{
	int c,r;
	int correct =0;
	while (correct ==0) //if the value is not correct/in the standers ,return
	{
		printf("Enter your Value for cols in the MATRIX , please pay attention that the value must be 1- %d  \n" ,Maxcols);
		scanf("%d",&c );
		printf("Enter your Value for rowss in the MATRIX , please pay attention that the value must be 1- %d  \n" ,Maxrows);
		scanf("%d",&r );
		if (c>1 && c<=Maxcols && r>1 && c<=Maxrows )
			correct=1;
	}
	
	*cols=c;
	*rows=r;	

	
}
void printMatrix(int* mat ,int cols , int rows)
{
	for (int i =0; i< cols; i++ )
	{
		for (int j =0; j< rows ; j++)
		{
			printf(" %d",*(mat+cols*i+j));
		}
		printf("\n");
	}	
}

