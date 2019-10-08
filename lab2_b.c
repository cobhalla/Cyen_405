#include <stdio.h>
#include <time.h>
#include <mpi.h>
int main(int argc, char *argv[]){
	double  start,end;
	int rank, size;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
        start = MPI_Wtime();
	printf("Hello, Cobhalla from #%d of %d!\n", rank, size);
	end = MPI_Wtime();
	double t = end-start;
	printf("Time elapsed is %f secs.\n",t);
	MPI_Finalize();
	return 0;
}
