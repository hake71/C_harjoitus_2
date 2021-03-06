/**
	* Version: 0.0.1
	* Author: Hannu Harju
	*/

/**
	*
	* Give Lotto numbers 1..n * 7 number in area 1..39 
	*/
	
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/* Defaul constant for Lotto lines */
#define MAX_NRO 38		// 39 - 1
#define AMOUNT_OF_NUMBERS 7
#define AMOUNT_OF_LINES 1
/* Lotto number table */
static char Lotto[AMOUNT_OF_NUMBERS];

/* 	Fucntion which check is New_number allready in 
	Lotto line
	If not, then add number to Lotto line */
char Add_Lotto_number_to_table( int New_number)
{
	unsigned char count = 0;
	/* Check previous Lotto numbers ... */ 
	while((Lotto[count]) && (count < AMOUNT_OF_NUMBERS))
	{
		/* Number is allready in Lotto line */
		if(New_number == Lotto[count]) {
		 	return 1;
		 }
		 /* Checked number count */
		 count++;
	}
	/* Add new number to Lotto line */
	Lotto[count] = New_number;
	
	return 0;
}

/**
	* Generate Lotto number lines
	* @arg 1 : Number of Lotto lines to generated
	* If no @arg 1, then generate 1 Lotto line
	*
	*/
	
int main(int argc, char *argv[]) {
	time_t t;
	
	unsigned char i, j, numbers_OK;
	unsigned int new_number, lines;

	/* default amount of Lotto lines */
	lines = AMOUNT_OF_LINES;
	/* If generated line amount as parameter */ 	
	if(argc > 1){
		/* ...Line amount is string, converter to int */
		lines = atoi(argv[1]);
		/* 	Case in problems in line amount parameter, 
			use default amount */
		if(lines < 1){
			lines = AMOUNT_OF_LINES;
		}
	}	
	/* Print parameters */
	printf(" Give %d Lotto lines, each include %d number from 1..%d :\n", \
		lines, AMOUNT_OF_NUMBERS, MAX_NRO+1);

	/* Initialize random number generator */
	srand((unsigned) time(&t));
		
	/* Generate 'lines' amount of Lotto lines */
	for(j = 0; j < lines; j++)
	{
		/* Amount of proper Lotto number */
		numbers_OK = 0;
		
		/* Initialize Lotto table */
		for(i = 0; i < AMOUNT_OF_NUMBERS; i++){
			Lotto[i] = 0;
		}
	
		/* Generate one Lotto line */
		do{
			/* Generate random number */	
			new_number = 1 + rand() % MAX_NRO;
		
			/* Check if new_number allready in Lotto line */
			if(!Add_Lotto_number_to_table(new_number)){
				/* Number was OK */
				numbers_OK++;
			}
		/* Remeat until AMOUNT_OF_NUMBERS proper Lotton number found */
		}while(numbers_OK < AMOUNT_OF_NUMBERS);
	
		/* Print Lotto line */
		printf(" Lotto line %2d is: ", j+1);
		for(i = 0; i < AMOUNT_OF_NUMBERS; i++){
			printf(" %2d", Lotto[i]);
		}
		printf("\n");
	} // for()
	return 0;
}

/* End of file */
