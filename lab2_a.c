#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define NP 10000000
int vecta[NP];

int main(int argc, char * argv[]){
    unsigned long int i, n = (unsigned long int)NP;
    clock_t start,end;
    double totsum = 0.0;
    srand(time(NULL));
    for (i=0; i<n; i++) vecta[i]=(rand() % 100 +1);
    start = clock();
    for (i=0; i<n; i++){
        totsum += (double)vecta[i];
    }
    end = clock();
    double t =(double) (end - start)/CLOCKS_PER_SEC;
    printf("Time elapsed is %f secs.\n",t); 
    printf("Total sum is %f.\n",totsum);
    return 0;
}
