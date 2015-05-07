/**
	* Version: 0.0.1
	* Author: Hannu Harju
	*/

/**
	*
	* Give Lotto numbers 7 * 1..39 
	*/
	
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NRO 38
#define AMOUNT_OF_NUMBERS 7
#define AMOUNT_OF_LINES 1

static char Lotto[AMOUNT_OF_NUMBERS];

char Add_Lotto_number_to_table( int New_number)
{
	unsigned char count = 0;
	while((Lotto[count]) && (count < AMOUNT_OF_NUMBERS))
	{
		if(New_number == Lotto[count]) {
		 	return 1;
		 }
		 count++;
	}
	
	Lotto[count] = New_number;
	return 0;
}

int main(int argc, char *argv[]) {
	time_t t;
	
	unsigned char i, numbers_OK = 0;
	unsigned int new_number, lines;
	
	lines = AMOUNT_OF_LINES;
	
	printf(" Give %d Lotto lines, each include %d number from 1..%d :\n", \
		AMOUNT_OF_NUMBERS, MAX_NRO+1);
		
	/* Initialize random number generator */
	srand((unsigned) time(&t));
	/* Initialize Lotto table */
	for(i = 0; i < AMOUNT_OF_NUMBERS; i++){
		Lotto[i] = 0;
	}
	
	/* Fill Lotto line */
	do{
		/* Generate random number */	
		new_number = 1 + rand() % MAX_NRO;
//		printf(" Number %02d ", new_number );
		
		/* Check if same allready in Lotto line */
		if(Add_Lotto_number_to_table(new_number)){
//			printf("  ---> Repeat \n");
			continue;
		} else {
//			printf("  ---> OK \n");
			numbers_OK++;
		}
	}while(numbers_OK < AMOUNT_OF_NUMBERS);
	
	/* Print Lotto line */
	printf(" Lotto line is: ");
	for(i = 0; i < AMOUNT_OF_NUMBERS; i++){
		printf(" %d", Lotto[i]);
	}
	printf("\n");

	return 0;
}

/* End of file */