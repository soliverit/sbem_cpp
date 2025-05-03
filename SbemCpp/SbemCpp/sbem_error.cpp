#include "sbem_error.h"

/*=== Constructors ===*/
SbemError::SbemError() : code(-1), message("default constructors are wild... or I don't get them. Either way") {}
SbemError::SbemError(int errorCode, std::string errorMessage) : code(errorCode), message(errorMessage) {}
/*=== Instance methods ===*/
std::string SbemError::toString() { return std::to_string(code) + "\t" + message; }