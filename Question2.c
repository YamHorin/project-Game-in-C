#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include "Question2.h"
 #define COLOR 3
 #define ROWS 10
 #define COLS 10
 
int expandColor(int* mat  , int cols , int rows  , int colorNumber ,  int turn  , int StartLine , int StartRow ) //function for put the color in matrix in the (number) turn
{
	int numOfBlocks =0;
	int finishLine  = StartLine +(turn *2)+1; // calculate the frame for the turn number
	int finishRow  = StartRow +(turn *2)+1;// calculate the frame for the turn number
 
	for (int i =StartRow ; i<finishRow ; i++)
	{
		for (int j =StartLine; j<finishLine ;j++)
		{
			if (*(mat+cols*i+j)==0)
			{
				numOfBlocks++;
				*(mat+cols*i+j)=colorNumber;
			}
				
		}
	}
	printMatrix2(mat ,cols , rows); //after the turn ,print the matrix
	return numOfBlocks;
}
void colorGame()
{
	int mat [ROWS][COLS];
	allzeromat((int*) mat  , COLS , ROWS );
	printf("ROWS = %d \n", ROWS);
	printf("COLS  = %d \n", COLS);
	printf("COLOR = %d \n", COLOR);
	printMatrix2((int*) mat  , COLS , ROWS);
	int matColor[COLOR][2];
	MakePointStartForColors((int*) mat  , COLS , ROWS , COLOR ,(int*) matColor );
	printf("start places for color: \n");
	printf("line | place \n");
	printMatrix2((int*) matColor  , 2, COLOR);
	printf("\n \n");
	printMatrix2((int*) mat  , COLS , ROWS);
	colorTheBoard((int*)mat  , COLS , ROWS, (int*)matColor , COLOR);
	
}
void MakePointStartForColors(int* mat , int colsBigMat , int rowsBigMat , int colorNumber ,int* matColor ) //put the values in the points before the game 
{
	
	for (int w =0; w< colorNumber ; w++)
	{
	
		int i,j;
		int isOk=0;
		do{
		j = 1+(rand()%(rowsBigMat-1 +0+1));
		i  = 1+(rand()%(colsBigMat-1 +0+1));
		if (*(mat+colsBigMat*i+j)==0)
		{
			*(mat+colsBigMat*i+j)=(w+1);
			*(matColor +colorNumber *w +0) = i; // int* StartLine
			*(matColor +colorNumber *w +1) = j; // int* StartRow
			isOk=1;
		}
		}while(isOk==0); //check if the point is not belong to someone else
	}
}
int IsTheGameOver(int* mat  , int cols , int rows ) //function check if the game is over
{
	for (int i =0; i< cols; i++ )
	{
		for (int j =0; j< rows ; j++)
		{
			if (*(mat+cols*i+j)==0)
				return 0;
		}
	}
	return 1;
}
void allzeromat(int* mat  , int cols , int rows ) //put in all the spots in the matrix 0
{
	for (int i =0; i< cols; i++ )
	{
		for (int j =0; j< rows ; j++)
		{
			*(mat+cols*i+j)=0;
		}
	}
}
void colorTheBoard(int* mat  , int cols , int rows  , int* matColor , int numberOfColors) // function for the game 
{
	int colorScore[COLOR];
	AllZeroArr(colorScore ,numberOfColors);
	int isTheGameOver=0;
	int turn=1;
	do
	{
		isTheGameOver = IsTheGameOver(mat  , cols , rows );
		printf("turn number  %d \n",turn);
		for (int i =0; i< numberOfColors ; i++)
		{
			
			if (*(matColor +numberOfColors *i +0)>0) //every round , the frame gets bigger
				*(matColor +numberOfColors *i +0) =*(matColor +numberOfColors *i +0)-1;
			if (*(matColor +numberOfColors *i +1)>0) //every round , the frame gets bigger
				*(matColor +numberOfColors *i +1) =*(matColor +numberOfColors *i +1)-1;
			
			int numberBlocks = expandColor(mat  , cols , rows  , i+1 ,  turn  , *(matColor +numberOfColors *i +1), *(matColor +numberOfColors *i +0));
			colorScore[i]+=numberBlocks;
			printf("color number %d got %d blocks! \n" , i+1 ,numberBlocks );
		}
		
		turn++;	
		
	}while (isTheGameOver==0);
	printMatrix2(mat ,cols , rows);
	WhoIsTheWinner(colorScore ,numberOfColors);
}

void printMatrix2(int* mat ,int rows , int cols ) //the name is because printMatrix is in Q1
{
	for (int i =0; i< cols; i++ )
	{
		for (int j =0; j< rows ; j++)
		{
			printf(" %d  ",*(mat+cols*i+j));
		}
		printf("\n");
	}	
}
void AllZeroArr(int* arr ,int size) //in the start all the color gets 0 porints
{
	for (int i =0; i< size ;i++)
	{
		*(arr+i) = 0;
	}
}
void WhoIsTheWinner(int* arr ,int size)
{
	int WinColor=0;
	int max  = 0;
	for (int i =0; i< size ;i++)
	{
		if(*(arr+i)>max)
		{
			WinColor=i;
			max  =*(arr+i);
		}
	}
	printf("The Winner is Color number : %d with %d block!! \n\n", WinColor+1 , max);
}
