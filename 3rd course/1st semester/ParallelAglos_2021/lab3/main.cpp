#include <iostream>
#include "mpi.h"

int main(int argc, char* argv[]){
  int size, rank;
  MPI_Init(&argc, &argv);
  MPI_Status Status;
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  
  if (size < 2) {
    std::cout << "This application is meant to be run with at least 2 MPI processes.\n";
    MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
  }
  
  int sendbuf[size];
  int recvbuf[size];

  for (int i = 0; i < size; i++) {
    sendbuf[i] = rank * size + i;
  }
  
  MPI_Alltoall(&sendbuf, 1, MPI_INT, recvbuf, 1, MPI_INT, MPI_COMM_WORLD);
  
  std::cout << "[Process " << rank << "] recieved [" << recvbuf[0];
  for (int i = 1; i < size; i++)
    std::cout << ", " << recvbuf[i];
  std::cout << "]\n";
  
  MPI_Finalize();
  return 0;
}
