#pragma once
/*===
	Includes
===*/
// Native

// Project
#include "sbem_object.h"
/*
	SBEM Combined heating and power generator

	Combined heating and power system.
*/
class SbemCchpGenerator : public SbemObject {
	/*=== Constructors ===*/
	/* Default */
	SbemCchpGenerator();
	/* Create blank CCHP-GENERATOR */
	SbemCchpGenerator(std::string objectName);
	/* Create complete CCHP-GENERATOR*/
	SbemCchpGenerator(std::string objectName, std::vector<std::string> propertyStrings);
public:
	/*=== Static methods===*/
	/* SBEM object name CCHP-GENERATOR */
	static const std::string OBJECT_NAME;
	/* Convert to an .inp object */
	std::string toString();
};