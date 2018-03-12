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

TEST_CASE( "Asynchronous Send String", "[MPI]" ) {

  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  // This demo requires at least 2 processes.
  REQUIRE(size >= 2);

  std::string peace = "I come in peace!";
  if (rank == 0) {
    MPI_Request request;
    int error = MPI_Isend((void*) peace.c_str(), peace.size() + 1, MPI_CHAR, 1, 42, MPI_COMM_WORLD, &request);
    REQUIRE(error ==  MPI_SUCCESS);

    // We do not guarantee that Rank 1 has received the message yet
    // We can carry on, and ANY WORK WE DO NOW WILL OVERLAP WITH THE
    // COMMUNICATION
    // BUT, we can't safely change the string.

    // Do some expensive work here
    for (int i=0; i<1000; i++) {}; // BUSYNESS FOR EXAMPLE

    MPI_Status status;
    error = MPI_Wait(&request, &status);
    REQUIRE(error ==  MPI_SUCCESS);

    // Here, we run code that requires the message to have been
    // successfully sent.
  }
  if (rank == 1) {
    char buffer[256];
    int const error = MPI_Recv(buffer, 256, MPI_CHAR, 0, 42, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    REQUIRE(error ==  MPI_SUCCESS);
    CHECK(std::string(buffer) == peace);
  }
}
