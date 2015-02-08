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

    KEPtr testKEPtr = (KEPtr) malloc (sizeof(KEPtr));//(sizeof(struct KeyboardElement));//(sizeof(KEPtr));
    testKEPtr->counter = 17;
    testKEPtr->letters = "topeka";
    keypad[0] = testKEPtr;


    printf("end: %d %s\n", keypad[0]->counter, keypad[0]->letters);

    printf("size of KEPtr: %lu size of struct: %lu\n", sizeof(KEPtr), sizeof(struct KeyboardElement));

 	return 0;
}

void PrintFunction(char c)
{
	printf("%c", c);
}
