#pragma once
/*===
	Incnludes
===*/
// Native
#include <sstream>
#include <iomanip>
// Project
#include "sbem_property.h"
/*
	SBEM float property

	A property for numeric values.

	Property also includes integers which were previously stored in SbemIntProperty. The
	toString() now writes things that look like integers as integers. SBEM doesn't care
	unless if a float looks like an integer as long as integers look like integers.
*/
class SbemNumericProperty : public SbemProperty {
public:
	/*=== Constructors ===*/
	/* Default */
	SbemNumericProperty();
	/* Actually populating the property */
	SbemNumericProperty(const std::string& key, float value);
	/*=== Getters ===*/
	float getValue();
	/*=== Setters ===*/
	void setValue(float newValue);
	/*=== The rest ===*/
	std::string toString();
protected:
	/* The value: protected to force a common setter process*/
	float value;
};
