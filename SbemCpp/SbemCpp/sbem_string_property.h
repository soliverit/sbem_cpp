#pragma once
/*===
	Incnludes
===*/
// Native
#include <string>
// Project
#include "sbem_property.h"
/*
	SBEM string property

	String and enum properties. As far as we're concerned, Strings can have any value. Though,
	values can have implicit rules in other uses. E.g, C-NAME must have the assessor's name.

	Enumerated properties a whitelist of values found in sbem.csv. As far as SbemModel is
	concerned, enums can technically have any value. However, it's expected that models
	will be validated by SbemValidator before sending to SBEM.
*/
class SbemStringProperty : public SbemProperty{
public:
	/*=== Constructors ===*/
	/* Default */
	SbemStringProperty();
	/* Actually populating the property */
	SbemStringProperty(const std::string& key, std::string stringValue);

	/*=== Getters ===*/
	/* Get the property's name */
	std::string getValue();
	std::string getQuotelessValue();
	/*=== Setters ===*/
	/* Get the property's value (string, possibly enum that looks like a string or unsigned int) */
	void setValue(std::string newValue);
	/*=== The rest ===*/
	/* Convert from into its PROPERTY-NAME = VALUE string */
	std::string toString();
protected:
	/* Property's value. Protected to force a common setter process */
	std::string value;
};

/*=== Getters ===*/ 

/*=== Setters ===*/

/*=== The rest ===*/
