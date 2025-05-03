#pragma once
/*===
	Inlcudes
===*/
// Native
#include <string>

// Project
/*
	SBEM property error

	Errors for properties:

	PARSE:		Couldn't parse property string
	PROPERTY0:	Property key doesn't exist in validator
	INVALID:	String/numeric value is invalid
	KEYWORD:	Enum value is not validate
*/
struct SbemPropertyError {

	SbemPropertyError();
	SbemPropertyError(int errorCode, std::string errorMessage);
	// Static'ish (not sure what you'd call enums. Worry later)
	enum ErrorCodes {
		PARSE,
		KEY,
		INVALID,
		KEYWORD
	};
	/*=== Instance members ===*/
	int code;
	std::string message;
	std::string toString();
};