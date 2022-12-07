#include "Question1.h"
#include "Question2.h"
#include <stdio.h>
#include <ctype.h>

int  main()
{

	char choice;
	int temp = 1;
	while (temp==1)
	{
	printf("Please choose one of the following options \n \v S/s - Biggest Matrix Sum \n\v C/c – Color Game \n\v E/e - Quit \n\v" );
		scanf(" %c", &choice);
		printf("/----------------------/\n");
		
		switch(tolower(choice))
	{
	case 's':
		printf(" 1 chosen\n");
		biggestMatrixSum();
		break;
	case 'c':
		printf(" 2 chosen\n");
		colorGame();
		break;
	case 'e':
		printf(" Bye-Bye Exit\n");
		temp = 0;
		break;
	default:
		printf("chois not found....\n");
	
	}
	}
	
}
