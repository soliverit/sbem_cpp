#pragma once
/*===
	Includes
===*/
// Native
#include <string>
// Projects
struct SbemError {
	/*=== Constructors ===*/
	SbemError();
	SbemError(int errorCode, std::string errorMessage);
	// Static'ish (not sure what you'd call enums. Worry later)
	enum ErrorCodes {
		CONTENT_FILE_NOT_EXISTS,
		CONTENT_CORRUPT,
		SBEM_OBJECT_MISSING
	};
	/*=== Instance members ===*/
	int code;
	std::string message;
	std::string toString();
	
};