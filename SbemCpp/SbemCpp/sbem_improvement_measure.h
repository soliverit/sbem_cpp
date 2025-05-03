#pragma once
/*===
	Includes
===*/
// Native

// Project
#include "sbem_object.h"
/*
	SBEM Improvement measure

	Never seen it populated but since it exists, here's the object.
*/
class SbemImprovementMeasure : public SbemObject {
public:
	/*=== Constructors ===*/
	/* Default */
	SbemImprovementMeasure();
	/* Create blank IMPROVEMENT-MEASURE */
	SbemImprovementMeasure(const std::string& objectName);
	/* Create complete IMPROVEMENT-MEASURE */
	SbemImprovementMeasure(std::string objectName, std::vector<std::string> propertyStrings);
	/*=== Static methods===*/
	/* SBEM object name IMPROVEMENT-MEASURE */
	static const std::string OBJECT_NAME;
	/*=== Instance methods ===*/
	/* Convert to an .inp object. */
	std::string toString();
};