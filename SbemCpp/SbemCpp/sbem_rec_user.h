#pragma once
/*===
	Includes
===*/
// Native

// Project
#include "sbem_object.h"
/*
	SBEM Rec[ommendation] [from] User

	Contains information about standard recommendations, populated by the modeller. Typically,
	the IN-OUT property is used to determine whether a measure is valid for the building. For example,
	SBEM might say cavity wall insulation but the model might be for a subspace within a shopping centre
	which you obviously can't insulate in isolation.

		"Rec 13" = REC-USER
		   CATEGORY = ENVELOPE
		   CODE = EPC-E6
		   REC-TEXT = "Some loft spaces are poorly insulated - install/improve insulation. (reworded)"
		   REC-COMMENT = "No comments from assessor"
		   ENERGY-IMPACT = HIGH
		   CO2-IMPACT = HIGH
		   PAY-BACK = UNKNOWN
		   PAY-BACK-NUM = -1
		   CO2-SAVE-POUND = GOOD
		   REF-OBJECT-TYPE = WHOLE-BUILDING
		   USER-IN-OUT = OUT
		   ..
*/
class SbemRecUser : public SbemObject {

public:
	/*=== Constructors ===*/
	/* Default */
	SbemRecUser();
	/* Create blank REC-USER */
	SbemRecUser(std::string objectName);
	/* Create complete REC-USER */
	SbemRecUser(std::string objectName, std::vector<std::string> propertyStrings);
	/*=== Static methods===*/
	/* SBEM object name REC-USER */
	static const std::string OBJECT_NAME;
	/*=== Instance methods ===*/
	/* Convert to an .inp object. See example */
	std::string toString();
};