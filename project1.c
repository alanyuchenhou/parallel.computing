/* project1.c */
#include <stdio.h>
#include <mpi.h> 
#include <assert.h>
#include <sys/time.h>

long convertTime (struct timeval time) {
  return time.tv_sec*1000000 + time.tv_usec;
}

int main(int argc,char *argv[]) {
  int rank,p;
  const int source = 7;
  const int destination = 0;
  const long sizeLimit = 100000;
  const int testCount = 1000;
  char message[sizeLimit];
  long totalTime = 0;
  struct timeval t1,t2;
  MPI_Init(&argc,&argv);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  MPI_Comm_size(MPI_COMM_WORLD,&p);
  assert(p>=8);
  for (int size = 1; size < sizeLimit; size *= 2) {
    for (int i = 0; i < testCount; i++) {
      int tag = size;
      if (rank == source) {
	MPI_Barrier (MPI_COMM_WORLD);
	MPI_Send(&message, size, MPI_CHAR, destination, tag, MPI_COMM_WORLD);
      }
      else if (rank == destination) {
	MPI_Status status;
	MPI_Barrier (MPI_COMM_WORLD);
	gettimeofday(&t1,NULL);
	MPI_Recv(&message, size, MPI_CHAR, source, tag, MPI_COMM_WORLD, &status);
	gettimeofday(&t2,NULL);
	totalTime += (convertTime(t2) - convertTime(t1));
      }
      else {
	MPI_Barrier (MPI_COMM_WORLD);
      }
    }
    if (rank == destination) {
      printf("%8d %8ld \n", size, totalTime/testCount);
    }
  }
  MPI_Finalize();
}
