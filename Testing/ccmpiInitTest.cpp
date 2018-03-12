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

// Inspired by MPHYG002 Lesson 6:
// http://rits.github-pages.ucl.ac.uk/research-computing-with-cpp/06MPI/

TEST_CASE( "Initialisation Test", "[MPI]" ) {
  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  CHECK(size > 0);
  CHECK(rank >= 0);
  std::cout << "Processor " << rank << " of " << size << " says hello\n";
}
