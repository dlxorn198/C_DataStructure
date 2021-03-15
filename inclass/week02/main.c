#include "selsort.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_SIZE 101

int main(void){

    int i,n;
    int list[100];
    printf("Enter the number of numbers to generate: ");

    scanf("%d",&n);

    if( (n<1) || (n > MAX_SIZE) ) {
        printf("improper value\n");
        
        return 0;
    }

    for(i=0;i<n;i++){
        list[i]=rand()%1000;
        printf("%d ",list[i]);
    }

    sort(list,n);

    printf("\nSorted array: \n");
    for(i=0;i<n;i++){
        printf("%d ",list[i]);
    }

    printf("\n");

    return 0;
}