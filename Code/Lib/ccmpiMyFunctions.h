/*=============================================================================

  CMAKECATCHMPI: A software package to demo MPI with CMake, CTest and Catch.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef ccmpiMyFunctions_h
#define ccmpiMyFunctions_h

#include "ccmpiWin32ExportHeader.h"

/**
* \file ccmpiMyFunctions.h
* \brief Various Utilities.
* \ingroup utilities
*/
namespace ccmpi
{

/**
* \brief My first function, adds two integers.
*/
CMAKECATCHMPI_WINEXPORT int MyFirstAddFunction(int a, int b);

} // end namespace

#endif
