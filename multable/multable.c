#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
    int *p_mulTable, i, j;

    int arraySize = 10;

    //prevents the segfault caused by accessing nonexistent arg
    if( argc > 1 )
    {
        //a little wasteful with the atoi calls, but oh well... 
        if( atoi(*(argv + 1)) < 10 && atoi(*(argv + 1)) > 0 )
        {
            arraySize = atoi(*(argv + 1));
        }
    }
    
    p_mulTable = (int *)malloc(sizeof(int) * (arraySize*arraySize));

    int * p_tableIterator = p_mulTable;

    for(i = 1; i <= arraySize; i++)
    {
        for(j = 1; j <= arraySize; j++) 
        {
            * p_tableIterator = j*i;
            printf("%d\t", j * i); 
            p_tableIterator++;            
        }
        printf("\n");
    }

    return 0;
}
