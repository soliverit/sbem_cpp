#pragma once
/*===
	Includes
===*/
// Native

// Project
#include "sbem_object.h"
/*
	SBEM Door thermal bridge

	Thermal bridge object for doors. No idea why it exists for SBEM but since
	it does...
*/
class SbemDoorTmBridge : public SbemObject { 
public:
	/*=== Constructors ===*/
	/* Default */
	SbemDoorTmBridge();
	/* Create blank DOOR-TM-BRIDGE */
	SbemDoorTmBridge(std::string objectName);
	/* Create complete DOOR-TM-BIRDGE s*/
	SbemDoorTmBridge(std::string objectName, std::vector<std::string> propertyStrings);
	/*=== Static methods===*/
	/* SBEM object name DOOR-TM-BRIDGE*/
	static const std::string OBJECT_NAME;
	/*=== Instance methods ===*/
	/* Convert to an .inp object */
	std::string toString();
};