#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char * argv[])
{
    int i;
    printf("kek\n");
/*
    int kekTable[100];

    kekTable[0] = 5;

    printf("num: %d\n", kekTable[0]);



    int * p_mulTable;

    p_mulTable = (int *) malloc (sizeof(int) * 100); // allocate 100 ints worsecase

    int * p_ptr = p_mulTable;
    
    for (i = 0; i < 10; i++) {
        *p_ptr = 0;
        p_ptr++;
        printf("In the table: %d\n", p_ptr);
    }
*/


    int *d_array;
    d_array = (int *)malloc(sizeof(int) * 100);//100 for now 10x10
    
    
    int * ptrToAccess2d = d_array;


    for(i = 0; i < 10; i++){//10 to test
        * ptrToAccess2d = i;
        printf("numnum: %d\n", *ptrToAccess2d);
        ptrToAccess2d++;

    }

    int * ptrToAccess2dNew = d_array;
    for(i = 0; i < 10; i++){//10 to test
        printf("numnum2: %d\n", *ptrToAccess2dNew+i);
    }              


//    free(p_mulTable);
    free(d_array);

    return 0;
}
