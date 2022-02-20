#include <iostream>
#include "mpi.h"

int main(int argc, char* argv[]){
  if (argc != 2) {
    std::cout << "argc = " << argc << std::endl;
    MPI_Status Status;
    MPI_Init(&argc, &argv);
    MPI_Finalize();
    return 5;
  }
  int size, rank, rand_index;
  char rand_char;
  size_t msg_size = strlen(argv[1]);
  char *sendbuf = new char[msg_size];
  char *recvbuf = new char[msg_size];
  MPI_Status Status;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  srand(time(NULL) + rank);
  if ( rank == 0 ) {
    sendbuf = argv[1];
    if (rank+1 < size) {
      std::cout << sendbuf << "\t---->\t";
      MPI_Send(sendbuf, msg_size, MPI_CHAR, rank+1, 0, MPI_COMM_WORLD);
      MPI_Recv(recvbuf, msg_size, MPI_CHAR, size-1, MPI_ANY_TAG, MPI_COMM_WORLD, &Status);
      std::cout << recvbuf << "\n";
    } else {
      std::cout << sendbuf << "\t---->\t" << sendbuf << "\n";
    }
  } else {
    MPI_Recv(recvbuf, msg_size, MPI_CHAR, rank-1, MPI_ANY_TAG, MPI_COMM_WORLD, &Status);
    for (int i = 0; i < msg_size; i++) {
        sendbuf[i] = recvbuf[i];
    }
    rand_index = rand()%msg_size;
    rand_char = 32 + rand()%94;
    sendbuf[rand_index] = rand_char;
    if (rank + 1 < size) {
      MPI_Send(sendbuf, msg_size, MPI_CHAR, rank+1, 0, MPI_COMM_WORLD);
    } else {
      MPI_Send(sendbuf, msg_size, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    }
  }
  MPI_Finalize();
  return 0;
}
