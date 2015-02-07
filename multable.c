#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char * argv[])
{
    int *p_mulTable, i, j;

    p_mulTable = (int *)malloc(sizeof(int) * 100);//deal with args still

    int * p_tableIterator = p_mulTable;

    for(i = 1; i <= 10; i++)//still assumption with args
    {
        for(j = 1; j <= 10; j++) 
        {
            * p_tableIterator = j*i;
            printf("%d\t", j * i); 
            p_tableIterator++;            
        }
        printf("\n");
    }

    return 0;
}
