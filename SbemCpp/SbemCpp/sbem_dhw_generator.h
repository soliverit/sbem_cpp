#pragma once
/*===
	Includes
===*/
// Native

// Project
#include "sbem_object.h"
/*
	SBEM glass

	Domestic hot water system.

		ISBEM-ID = 11
		HEAT-GEN-TYPE = Instantaneous hot water only
		DHW-GEN-SEFF = 0.5
		FUEL-TYPE = Grid Supplied Electricity
		STORE-SYSTEM = NO
		SHOWERS-SERVED-REF = { "Default" }
		SHOWERS-SERVED-NUM = { 1 }
*/
class SbemDhwGenerator : public SbemObject {
public:
	/*=== Constructors ===*/
	/* Default */
	SbemDhwGenerator();
	/* Create blank DHW-GENERATOR */
	SbemDhwGenerator(std::string objectName);
	/* Create complete DHW-GENERATOR */
	SbemDhwGenerator(std::string objectName, std::vector<std::string> propertyStrings);
	/*=== Static methods  ===*/
	static SbemDhwGenerator createBasic(std::string name);
	/*=== Static members ===*/
	/* SBEM object name DHW-GENERATOR */
	static const std::string OBJECT_NAME;
	/*=== Instance methods ===*/
	/* Convert to an .inp object. See example */
	std::string toString();
};