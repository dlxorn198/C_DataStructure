#include <stdio.h>
#include <time.h>
#include "selsort.h"
#define MAX_SIZE 10001

void main (void) {
    int i,n, step=10;
    int a[MAX_SIZE];
    double duration;
    printf(" n repetitions time\n");
    for (n=0; n<=10000; n+= step) {
        long repetitions = 0;
        clock_t start = clock();
        do {
            repetitions++;
            for (i=0;i<n;i++) a[i] = n-i;
            sort(a,n);
        } while(clock() - start < 10000);
        duration = ((double) (clock() - start)) / CLOCKS_PER_SEC;
        duration /= repetitions;
        printf("%6d %9ld %f\n", n, repetitions, duration);
        if(n==100) step = 100;
        if(n==1000) step = 1000;
    }
}
