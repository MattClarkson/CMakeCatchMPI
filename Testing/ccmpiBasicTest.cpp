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

TEST_CASE( "Send String", "[MPI]" ) {

  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  // This demo requires at least 2 processes.
  REQUIRE(size >= 2);

  const std::string peace = "I come in peace!";
  if (rank == 0) {
    const int error = MPI_Ssend((void*) peace.c_str(), peace.size() + 1, MPI_CHAR, 1, 42, MPI_COMM_WORLD);
    // Here, we guarantee that Rank 1 has received the message.
    REQUIRE(error ==  MPI_SUCCESS);
    std::cout << "Sent message:" << peace << std::endl;
  }
  if (rank == 1) {
    char buffer[256];
    int const error = MPI_Recv(buffer, 256, MPI_CHAR, 0, 42, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    REQUIRE(error ==  MPI_SUCCESS);
    CHECK(std::string(buffer) == peace);
    std::cout << "Received message:" << peace << std::endl;
  }
}
