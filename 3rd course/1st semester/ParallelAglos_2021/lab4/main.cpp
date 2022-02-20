#include <iostream>
#include "mpi.h"

/*
 0: send K numbers to K proc
 
 i: if N = 1 -> recv number and print it
 i: if N = 0 -> nothing
 
 */

int main(int argc, char* argv[]){
  int size, rank, K, N, color, key;;
  MPI_Init(&argc, &argv);
  MPI_Status Status;
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  srand(time(NULL) + rank);
  
  if (size < 2 || argc != 2) {
    if (rank == 0)
      std::cout << "This application is meant to be run with at least 2 MPI processes and 1 comand line argument.\n";
    MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
  }
  
  K = std::stoi(argv[1]);
  int sendbuf[K];
  int valuesN[size] = {0};
  
  if (rank == 0) {
    // generate K numbers
    for (int i = 0; i < K; i++)
      sendbuf[i] = i;
    
    // generate N's
    int counter = K;
    valuesN[0] = 1;
    for (int i = 1; i < size; i++) {
      if (counter <= 0)
        break;
      if (size-i==counter) {
        for (int j=i; j < size; j++)
          valuesN[j] = 1;
        counter = 0;
      }
      if ((rand()%2) && (counter > 0)) {
        valuesN[i] = 1;
        counter--;
      }
    }
    for (int i = 0; i < size; i++) {
      MPI_Send(&valuesN, size, MPI_INT, i, 0, MPI_COMM_WORLD);
      std::cout << valuesN[i] << " ";
    }
    std::cout << "\n";
  } else {
    MPI_Recv(&valuesN, size, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &Status);
  }
  
  N = valuesN[rank];
  
  if (N == 1) {
    color = 0;
    key = rank;
  } else {
    color = MPI_UNDEFINED;
    key = rank;
  }
  
  MPI_Comm new_comm;
  MPI_Comm_split(MPI_COMM_WORLD, color, key, &new_comm);
  
  if (new_comm != MPI_COMM_NULL) {
    MPI_Bcast(&sendbuf, K, MPI_INT, 0, new_comm);
    int new_rank;
    MPI_Comm_rank(new_comm, &new_rank);
    if (rank != 0)
      std::cout << "[Process " << rank << "] recieved " << sendbuf[new_rank-1] << "\n";
  }
  
  MPI_Finalize();
  return EXIT_SUCCESS;
}
