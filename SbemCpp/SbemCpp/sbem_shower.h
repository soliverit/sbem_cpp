#pragma once
/*===
	Includes
===*/
// Native

// Project
#include "sbem_object.h"
#include "sbem_dhw_generator.h"
/*
	SBEM Shower

	It's a shower!
*/
class SbemShower : public SbemObject {
public:
	/*=== Constructors ===*/
	/* Default */
	SbemShower();
	/* Create a blank SHOWER */
	SbemShower(std::string objectName);
	/* Create a complete SHOWER (minus pointer to DHW) */
	SbemShower(std::string objectName, std::vector<std::string> propertyStrings);
	/*=== Static methods===*/
	/* SBEM object name SHOWER */
	static const std::string OBJECT_NAME;
	/*=== Instance methods ===*/
	/* Convert to an .inp object */
	std::string toString();
protected:
	/* DHW generator that provides the hot water if shower isn't instantaneous point of use */
	std::shared_ptr<SbemDhwGenerator> dhw;
};