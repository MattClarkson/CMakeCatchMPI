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

TEST_CASE( "Broadcast Test", "[MPI]" ) {
  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  std::string const peace = "I come in peace!";
  std::string message = "";
  int error;
  if (rank == 0) {
    message = peace;
    error = MPI_Bcast((void*) peace.c_str(), peace.size() + 1, MPI_CHAR, 0, MPI_COMM_WORLD);
    std::cout << "Rank = " << rank << ", send message:" << message;
  } else {
    char buffer[256];
    error = MPI_Bcast(buffer, 256, MPI_CHAR, 0, MPI_COMM_WORLD);
    message = std::string(buffer);
    std::cout << "Rank = " << rank << ", received message:" << message;
  }
  for (int i(0); i < size; ++i) {
    if (rank == i) {
      std::cout << "Current rank is " << rank << std::endl;
      REQUIRE(error == MPI_SUCCESS);
      CHECK(message == peace);
    }
    MPI_Barrier(MPI_COMM_WORLD);
  }
}
