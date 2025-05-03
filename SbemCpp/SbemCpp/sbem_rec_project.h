#pragma once
/*===
	Includes
===*/
// Native

// Project
#include "sbem_object.h"
/*
	SBEM Rec project

	14 years working with SBEM. Not once has this had a value. But since it exists...
*/
class SbemRecProject : public SbemObject {
public:
	/*=== Constructors ===*/
	/* Default */
	SbemRecProject();
	/* Create blank REC-PROJECT */
	SbemRecProject(std::string objectName);
	/* Create complete REC-PROJECT (literally not a thing. Never has properties) */
	SbemRecProject(std::string objectName, std::vector<std::string> propertyStrings);
	/*=== Static methods===*/
	/* SBEM object name REC-PROJECT */
	static const std::string OBJECT_NAME;
	/*=== Instance methods ===*/
	/* Convert to an .inp object */
	std::string toString();
};