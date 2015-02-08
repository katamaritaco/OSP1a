#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "p1a2.h"

/* This is an array of 10 POINTERS to KeyboardElements
 */

KEPtr keypad[10];
char * letters[10] = { "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ", "" };


int main(int argc, char * argv[])
{
	if (argc <= 1)
		{
			printf("Usage: p1a2 string1 [stringN]\n");
			exit(1);
		}

// YOUR CODE HERE
    int i;

    //iterate through all arguments
    for (i = 0; i < argc - 1; i++)
    {
        printf("letters: %s\n", *(letters + i)); //iterate through the array for the lulz
    }
    
 	return 0;
}

void PrintFunction(char c)
{
	printf("%c", c);
}
