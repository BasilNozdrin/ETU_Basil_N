#include <iostream>
#include <mpi.h>
 
int main(int argc, char* argv[]) {
  // Initilialise MPI and check its completion
  MPI_Init(&argc, &argv);
  
  // Get my rank
  int my_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  
  int comm_size;
  MPI_Comm_size(MPI_COMM_WORLD, &comm_size);
  
  if(my_rank == 0) {
    
    
  }
  
//----------------------------------------------------------------------------
  MPI_Finalize();
  return EXIT_SUCCESS;
}
