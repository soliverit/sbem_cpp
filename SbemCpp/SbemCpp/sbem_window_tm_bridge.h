#pragma once
/*===
	Includes
===*/
// Native

// Project
#include "sbem_object.h"
/*
	SBEM window thermal bridge

	Thermal bridge object for windows. No idea why it exists for SBEM, but since
	it does...
*/
class SbemWindowTmBridge : public SbemObject{
public:
	/*=== Constructors ===*/
	/* Default */
	SbemWindowTmBridge();
	/* Create blank WINDOW-TM-BRIDGE */
	SbemWindowTmBridge(std::string objectName);
	/* Create complete WINDOW-TM-BRIDGE */
	SbemWindowTmBridge(std::string objectName, std::vector<std::string> propertyStrings);
	/*=== Static methods===*/
	/* SBEM object name WINDOW-TM-BRIDGE */
	static const std::string OBJECT_NAME;
	/*=== Instance methods ===*/
	/* Convert to an .inp object */
	std::string toString();
};