#pragma once
/*===
	Includes
===*/
// Native

// Project
#include "sbem_object.h"
/*
	SBEM glass

	Window thermal properties.

		U-VALUE = 2.664
		TOT-SOL-TRANS = 0.7
		LIG-SOL-TRANS = 0.7
		U-VALUE-CORR = NO
*/
class SbemGlass : public SbemObject {
public:
	/*=== Constructors ===*/
	/* Default */
	SbemGlass();
	/* Create blank GLASS */
	SbemGlass(std::string objectName);
	/* Create complete GLASS */
	SbemGlass(std::string objectName, std::vector<std::string> propertyStrings);
	/*=== Static methods===*/
	/* Create a basic instance */
	static SbemGlass createBasic(std::string name);
	/*=== Static members ===*/
	/* SBEM object name GLASS */
	static const std::string OBJECT_NAME;
	/*=== Instance methods ===*/
	/* Convert to an .inp object. See example */
	std::string toString();
};
