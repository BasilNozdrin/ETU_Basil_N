#include <iostream>
#include "mpi.h"

int main(int argc, char* argv[]){
  int size, rank, reciever;
  size_t msg_size = 1;
  int *sendbuf = new int[msg_size];
  int *recvbuf = new int[msg_size];
  MPI_Status Status;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  srand(time(NULL) + rank);
  if ( rank == 0 && rank+1 < size){
    reciever = rand()%size;
    *sendbuf = 9;
    std::cout << rank << " ---" << *sendbuf << "---> " << reciever << "\n";
    MPI_Send(sendbuf, msg_size, MPI_INT, reciever, 0, MPI_COMM_WORLD);
    MPI_Recv(recvbuf, msg_size, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &Status);
  } else {
    MPI_Recv(recvbuf, msg_size, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &Status);
    reciever = rand()%size;
    std::cout << rank << " ---" << *recvbuf << "---> " << reciever << "\n";
    MPI_Send(recvbuf, msg_size, MPI_INT, reciever, 0, MPI_COMM_WORLD);
  }
  MPI_Finalize();
  return 0;
}
