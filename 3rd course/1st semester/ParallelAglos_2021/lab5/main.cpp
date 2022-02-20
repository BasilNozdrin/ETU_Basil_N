#include <iostream>
#include "mpi.h"

int main(int argc, char* argv[]){
  MPI_Init(&argc, &argv);
  int size;
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  if (size != 8 && size != 12) {
    std::cout << "This application is meant to be run with "
              << "at 8 or 12 MPI processes.\n";
    MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
  }
  /** ----------------- SET NUMBER ---------------------------------------- */
  int number = rank;
  /** ----------------- SETUP CARTESIAN TOPOLOGY -------------------------- */
  int dimension_number = 3,
      dims[dimension_number] = {2, 2, size/4},
      periods[dimension_number] = {false, false, false},
      reorder = false;
  MPI_Comm cartesian_communicator;
  MPI_Cart_create(
    MPI_COMM_WORLD,
    dimension_number,
    dims,
    periods,
    reorder,
    &cartesian_communicator
  );
  /** ----------------- CHECK COORDS -------------------------------------- */
//   int my_coords[dimension_number];
//   MPI_Cart_coords(
//     cartesian_communicator,
//     rank,
//     dimension_number,
//     my_coords
//   );
//   std::cout << "[MPI process " << rank << "] Has coords "
//             << my_coords[0] << " "
//             << my_coords[1] << " "
//             << my_coords[2] << "\n";
  /** ----------------- BREAK CARTESIAN INTO MATRICES --------------------- */
  int remain_dims1[dimension_number] = {false, true, true};
  MPI_Comm matrix_communicator;
  MPI_Cart_sub(
    cartesian_communicator,
    remain_dims1,
    &matrix_communicator
  );
  /** ----------------- GET NEW RANK FOR COORD CHECK ---------------------- */
  int subgrid_rank;
  MPI_Comm_rank(matrix_communicator, &subgrid_rank);
  /** ----------------- CHECK COORDS -------------------------------------- */
//   int matrix_coords[2];
//   MPI_Cart_coords(
//     matrix_communicator,
//     subgrid_rank,
//     2,
//     matrix_coords);
//   std::cout << "[MPI process " << rank << "] Has matrix rank "
//             << subgrid_rank << " and coords "
//             << matrix_coords[0] << " "
//             << matrix_coords[1] << "\n";
  /** ----------------- BREAK MATRICES INTO COLUMNS ----------------------- */
  int remain_dims2[2] = {true, false};
  MPI_Comm column_communicator;
  MPI_Cart_sub(
    matrix_communicator,
    remain_dims2,
    &column_communicator
  );  
  /** ----------------- GET NEW RANK FOR REDUCE --------------------------- */
  MPI_Comm_rank(column_communicator, &subgrid_rank);
  /** ----------------- CHECK COORDS -------------------------------------- */
//   int column_coords[1];
//   MPI_Cart_coords(
//     column_communicator,
//     subgrid_rank,
//     1,
//     column_coords);
//   std::cout << "[MPI process " << rank << "] Has subgrid_rank "
//             << subgrid_rank << " and coords "
//             << column_coords[0] << "\n";
  /** ----------------- CALLING REDUCE ------------------------------------ */
  int reduction_result;
  int root_rank = 0;
  MPI_Reduce(
    &number,
    &reduction_result,
    1,
    MPI_INT,
    MPI_PROD,
    root_rank,
    column_communicator
  );
  if (subgrid_rank == root_rank)
    std::cout << "[MPI process " << rank << "] Prod = "
              << reduction_result << "\n";
  /** --------------------------------------------------------------------- */
  MPI_Finalize();
  return EXIT_SUCCESS;
}
