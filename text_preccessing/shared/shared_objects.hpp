#pragma once
#include "shared_objects_def.cpp"
// this is .cpp source file containing templates definitions
// shared_objects.hpp is already included in shared_objects.cpp
// this may bloat the application depending on compiler optimisation

// problem is that code cannot be compiled as templates arent known at templates definiton
// or declration.
// solution is to put template declaration, definition and initialisation in same file.
// they need to be in same compilation unit for it to compile as types are known.

// another solution may be to explicitly provide types so that it get compiled in types which
// get used during initilisation of template
// no need compile shared_objects_def.cpp as its already included in shared_objects.hpp

// "shared_objects_def.cpp" file contains templates definitions

