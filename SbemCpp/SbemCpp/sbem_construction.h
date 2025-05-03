#pragma once
/*===
	Includes
===*/
// Native

// Project
#include "sbem_object.h"
/*
	SBEM construction

	Opaque surface thermal properties

		TYPE = U_VALUE
		U-VALUE = 1.5
		U-VALUE-CORR = NO
		CM = { 4.93, 4.93 }
		METAL-CLADDING = NO
*/
class SbemConstruction : public SbemObject {
public:
	/*=== Constructors ===*/
	/* Default */
	SbemConstruction();
	/* Create blank CONSTRUCTION */
	SbemConstruction(std::string objectName);
	/* Create complete CONSTRUCTION */
	SbemConstruction(std::string objectName, std::vector<std::string> propertyStrings);
	/*=== Static methods ===*/
	static SbemConstruction createBasic(std::string name);
	/* SBEM object name COMPLIANCE */
	static const std::string OBJECT_NAME;
	/*=== Instance methods ===*/
	/* Convert to an .inp object. See example */
	std::string toString();
};