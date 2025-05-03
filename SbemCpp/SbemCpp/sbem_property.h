#pragma once
/*===
	Incnludes
===*/
// Native
#include <string>
// Project
/*
	SBEM property
*/
class SbemProperty {
public:
	/*=== Constructors ===*/
	SbemProperty();
	/* Actually set the key: All properties have keys, not all values are a common type. */
	SbemProperty(const std::string& key);
	/*=== Getters ===*/
	/* Get the property's name. E.g ACTIVITY-NAME */
	std::string getName();
	/*=== Setters ===*/

	/*=== The rest ===*/
protected:
	/*=== Instance members ===*/
	std::string name;
};