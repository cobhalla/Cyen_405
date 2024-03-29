#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <mpi.h>
#define NP 10000000
int vecta[NP];

int main(int argc, char * argv[]){
    unsigned long int i, n = (unsigned long int)NP;
    double start,end,localt,tott;
    double totsum,locsum = 0.0;
    int rank,size;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    srand(time(NULL)+rank);
    for (i=0; i<n; i++) vecta[i]=(rand() % 100 +1);
    start = MPI_Wtime();
    for (i=0; i<n; i++){
        locsum += (double)vecta[i];
    }
    end = MPI_Wtime();
    localt = end-start;
    MPI_Reduce(&locsum,&totsum,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
    MPI_Reduce(&localt,&tott,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
    printf("Local sum on process#%2d is %f.\n",rank,locsum);
    MPI_Barrier(MPI_COMM_WORLD);
    if(rank==0){
        printf("Time elapsed is %f secs.\n",tott); 
        printf("Total sum is %f.\n",totsum);
    }
    MPI_Finalize();
    return 0;
}
