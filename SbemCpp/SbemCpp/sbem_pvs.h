#pragma once
/*===
	Includes
===*/
// Native

// Project
#include "sbem_object.h"
/*
	SBEM Photovoltaic system

	Solar panels.
*/
class SbemPvs : public SbemObject {
public:
	/*=== Constructors ===*/
	/* Default */
	SbemPvs();
	/* Create blank PVS */
	SbemPvs(std::string objectName);
	/* Create complete PVS */
	SbemPvs(std::string objectName, std::vector<std::string> propertyStrings);
	/*=== Static methods===*/
	/* SBEM object name PVS */
	static const std::string OBJECT_NAME;
	/*=== Instance methods ===*/
	/* Convert to an .inp object */
	std::string toString();
};