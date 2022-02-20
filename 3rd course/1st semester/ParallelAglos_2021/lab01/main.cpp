#include <stdio.h>
#include "mpi.h"

int main(int argc, char* argv[]){
  int size, rank, msg_size = atoi(argv[1]);
  double starttime, endtime;
  int *sendbuf = new int[msg_size];
  int *revcbuf = new int[msg_size];
  MPI_Status Status;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  if ( rank % 2 == 0 && rank+1 < size){
    starttime = MPI_Wtime();
    // ping
    MPI_Send(sendbuf, msg_size, MPI_INT, rank+1, 0, MPI_COMM_WORLD);
    // pong
    MPI_Recv(revcbuf, msg_size, MPI_INT, rank+1, MPI_ANY_TAG, MPI_COMM_WORLD, &Status);
    endtime   = MPI_Wtime();
    printf("Send and Recv [%d -> %d -> %d] took %f seconds\n", rank, rank+1, rank, endtime-starttime);
  } else {
    // pong
    MPI_Recv(revcbuf, msg_size, MPI_INT, rank-1, MPI_ANY_TAG, MPI_COMM_WORLD, &Status);
    // ping
    MPI_Send(sendbuf, msg_size, MPI_INT, rank-1, 0, MPI_COMM_WORLD);
  }
  MPI_Finalize();
  return 0;
}

