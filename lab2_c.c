#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <mpi.h>
#define NP 10000000
int vecta[NP];

int main(int argc, char * argv[]){
    unsigned long int i, n = (unsigned long int)NP;
    double start,end;
    double totsum,locsum = 0.0;
    int rank,size;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    srand(time(NULL)+rank);
    for (i=0; i<n; i++) vecta[i]=(rand() % 100 +1);
    start = MPI_Wtime();
    for (i=0; i<n; i++){
        totsum += (double)vecta[i];
    }
    end = MPI_Wtime();
    locsum = end-start;
    MPI_Reduce(&locsum,&totsum,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
    printf("Local sum on process#%2d is %f.\n",rank,locsum);
    if(rank==0){
        double t = (end - start);
        printf("Time elapsed is %f secs.\n",t); 
        printf("Total sum is %f.\n",totsum);
    }
    MPI_Finalize();
    return 0;
}
