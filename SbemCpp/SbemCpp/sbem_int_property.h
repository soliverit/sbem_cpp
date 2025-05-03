#pragma once
/*===
	Incnludes
===*/
// Native

// Project
#include "sbem_property.h"
/*
	SBEM integer property

	DEPRECATED: A property for integer values. Originally intended to keep
	formatting of properties like ACTIVITY as integers because they're referenced
	by SBEM. Class has been merged with SbemNumericProperty which now converts trims
	decimal values off numbers that look like integers.

	For properties like ACTIVITY, the parent SbemObject should have an appropriate getter.
*/
class SbemIntProperty : public SbemProperty{
public:
	/*=== Constructors ===*/
	/* Default constructor */
	SbemIntProperty();
	/* Actually populating the property */
	SbemIntProperty(const std::string& key, unsigned int value);
	/*=== Getters ===*/
	/* Get Value: Return the value of the property*/
	unsigned int getValue();
	/*=== Setters ===*/
	/* Set the property value*/
	void setValue(unsigned int newValue);

protected:
	/*=== Instance members ===*/
	/* The value: protected to enforce a common setter process. */
	unsigned int value;
};