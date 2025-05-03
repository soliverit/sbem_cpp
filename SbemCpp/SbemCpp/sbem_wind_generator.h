#pragma once
/*===
	Includes
===*/
// Native

// Project
#include "sbem_object.h"
/*
	SBEM Window generator

	Wind turbines. Crazy, eh? Some building literally have personal window turbines.
*/
class SbemWindGenerator : public SbemObject {
public:
	/*=== Constructors ===*/
	/* Default */
	SbemWindGenerator();
	/* Create blank WIND-GENERATOR */
	SbemWindGenerator(std::string objectName);
	/* Create complete WIND-GENERATOR */
	SbemWindGenerator(std::string objectName, std::vector<std::string> propertyStrings);
	/*=== Static methods===*/
	/* SBEM object name WIND-GENERATOR */
	static const std::string OBJECT_NAME;
	/*=== Instance methods ===*/
	/* Convert to an .inp object */
	std::string toString();
};