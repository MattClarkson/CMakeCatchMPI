/*=============================================================================

  CMAKECATCHMPI: A software package to demo MPI with CMake, CTest and Catch.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "catch.hpp"
#include "ccmpiCatchMain.h"
#include "ccmpiMyFunctions.h"
#include <iostream>
#include <vector>
#include <mpi.h>

TEST_CASE( "Initialisation Test", "[MPI]" ) {
  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  std::cout << "Processor " << rank << " of " << size << " says hello\n";
  //REQUIRE(rank == 0); // depends on which process.
  //REQUIRE(size == 1); // depends on -n parameter to mpirun.
  REQUIRE(rank < size); // to illustrate a test case.
}
