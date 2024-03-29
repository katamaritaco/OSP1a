#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "p1a2.h"

/* This is an array of 10 POINTERS to KeyboardElements
 */

KEPtr keypad[10];
char * letters[10] = { "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ", "" };

void PrintFunction(char);

int main(int argc, char * argv[])
{
	if (argc <= 1)
		{
			printf("Usage: p1a2 string1 [stringN]\n");
			exit(1);
		}

// YOUR CODE HERE
    int i, j;

    //iterate through all arguments
    //for (i = 0; i < argc - 1; i++)
    //{
    //    printf("letters: %s\n", *(letters + i)); //iterate through the array for the lulz
    //}


    
    //allocate the KEPtrs
    //Just allocate room for all ten, rather than checking to see if a number
    //was pressed and then allocating accordingly, because of spec definition.
    for (i = 0; i < 10; i++)//magic 10 from keypad size
    {
        KEPtr letterPtr = (KEPtr) malloc (sizeof(struct KeyboardElement));
        //for tests
        //letterPtr->counter = i;
        letterPtr->counter = 0;
        letterPtr->letters = letters[i];
        //end tests
        keypad[i] = letterPtr;
    }

    //tests
    //for (i = 0; i < 10; i++)
    //{
    //    printf("keypad: %d counter: %d letters: %s\n", i, keypad[i]->counter, keypad[i]->letters);
    //}
    //end tests


    
    //go through every argument
    for (i = 1; i < argc; i++)
    {
        char * argumentString = argv[i];
        //printf("str kek: %s\n", argumentString);


        //go through all letters in the arg
        //assumption now that we will always have even num or chars in arg
        int numberTapped, timesTapped;
        char * charToPrint = (char *) malloc (sizeof(strlen(argumentString)));
        int hasDashForFirstLetter = 0;
        charToPrint[strlen(argumentString)-1] = '\0';//null temrinated
        for(j = 0; j < strlen(argumentString); j++)
        {
            if(j % 2 == 0)//check if first char in a series
            {
                hasDashForFirstLetter = 0;
                numberTapped = argumentString[j] - '0';//convert to ascii, sub offset
                //printf("number tapped: %d\n", numberTapped);
                if(numberTapped < 2 || numberTapped > 9)
                {
                    charToPrint[j] = '-';//invalid key pressed!
                    hasDashForFirstLetter = 1;
                } else
                {
                    charToPrint[j] = numberTapped + '0';
                }
                if(j == strlen(argumentString)-1)//covers case of odd baddies
                {
                    PrintWrapper(PrintFunction, '-');
                    //break out of arg
                    goto basedGOTO;
                }
            } 
            else if(j % 2 == 1)//second char in series
            {
                timesTapped = argumentString[j] - '0';//converts to ascii, then sub offset

                if(timesTapped >= 1 && timesTapped <= 4 && charToPrint[j-1] != '-' && hasDashForFirstLetter == 0)//4 because of PQRS/WXYZ
                {
                    charToPrint[j] = timesTapped + '0';
                    //time to print...
                    PrintWrapper(PrintFunction, keypad[numberTapped-1]->letters[timesTapped-1]);
                } else
                {
                    charToPrint[j] = '-';//invalid times tapped!
                    PrintWrapper(PrintFunction, '-');//???
                    //break out of arg
                    goto basedGOTO;
                }



            }
        }
        basedGOTO: 

        PrintWrapper(PrintFunction, '\n');

        //now populate the keypad counter...
        for(j = 0; j < strlen(charToPrint); j++)
        {
            int expectedNumber;
            expectedNumber = charToPrint[j] - '0';
            if(j % 2 == 0)
            {
                if(expectedNumber >= 2 && expectedNumber <= 9)
                {
                    keypad[expectedNumber]->counter = (keypad[expectedNumber]->counter)++;
                }
            }
        }

        //freecharToPrint
    }
   // printf("\nlol\n\n");

    


    //print out good values for number of times pressed
    for(i = 2; i < 10; i++)
    {
        char num;
        num = i + '0';
        PrintWrapper(PrintFunction, num);
        PrintWrapper(PrintFunction, '\t');
        PrintWrapper(PrintFunction, keypad[i]->counter + '0');
        PrintWrapper(PrintFunction, '\n');
    }




 	return 0;
}

void PrintFunction(char c)
{
	printf("%c", c);
}









