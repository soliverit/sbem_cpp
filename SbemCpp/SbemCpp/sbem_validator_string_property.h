#pragma once
/*===
	Incnludes
===*/
// Native
#include <string>

// Project

/*
 SBEM validator string property
*/
struct SbemValidatorStringProperty{

};


/*=== Getters ===*/

/*=== Setters ===*/

/*=== The rest ===*/
/*
	Value is validated

	All string values are valid for String property so always returns true
*/
bool isThisValueValid(std::string value);