#pragma once
/*
	Includes
*/
// Native

// Project
#include "sbem_object.h"
/*
	SBEM compliance

	The object that tells SBEM what it's calculating and what regs to use. 

		EPC-TYPE = EPC England	// EPC type or BRUKL 
		ENG-HERITAGE = NO		// England-only
		BR-STAGE = As built		// Part L2[B]
		AIR-CON-INSTALLED = No	// Self explanatory

	Scottish might also include Section 63 parameters.

		S63-STAGE = Prescriptive		// Can't remember actual values. That's probably one, though
*/
class SbemCompliance : public SbemObject {
public:
	/*=== Constructors ===*/
	/* Default */
	SbemCompliance();
	/* Create blank COMPLIANCE */
	SbemCompliance(std::string objectName);
	/* Create full COMPLIANCE */
	SbemCompliance(std::string objectName, std::vector<std::string> propertyStrings);
	/*=== Static methods===*/
	/* SBEM object name COMPLIANCE */
	static const std::string OBJECT_NAME;
	/*=== Instance methods ===*/
	/* Convert to an .inp object. See example */
	std::string toString();
};