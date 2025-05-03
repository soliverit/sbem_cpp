#include "sbem_property_error.h"

/*=== Constructors ===*/
SbemPropertyError::SbemPropertyError() : code(-1), message("default constructors are wild... or I don't get them. Either way") {}
SbemPropertyError::SbemPropertyError(int errorCode, std::string errorMessage) : code(errorCode), message(errorMessage) {}
/*=== Instance methods ===*/
std::string SbemPropertyError::toString() { return std::to_string(code) + "\t" + message; }