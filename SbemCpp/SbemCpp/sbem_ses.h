#pragma once
/*===
	Includes
===*/
// Native

// Project
#include "sbem_object.h"
/*
	SBEM Solar energy system

	Solar hot water system.
*/
class SbemSes : public SbemObject {
public:
	/*=== Constructors ===*/
	/* Default SES */
	SbemSes();
	/* Create blank SES */
	SbemSes(std::string objectName);
	/* Create complete SES */
	SbemSes(std::string objectName, std::vector<std::string> propertyStrings);
	/*=== Static methods===*/
	/* SBEM object name SES */
	static const std::string OBJECT_NAME;
	/*=== Instance methods ===*/
	/* Convert to an .inp object */
	std::string toString();
};