#pragma once
/*===
	Includes
===*/
// Native

// Project
#include "sbem_object.h"
#include "sbem_object_set.h"
#include "sbem_zone.h"
/*
	SBEM HVAC system

	Heating, ventilation, and air conditioning system.

		TYPE = Flued forced-convection air heaters
		HEAT-SOURCE = Air heater
		CHP = NO
		FUEL-TYPE = Natural Gas
		HEAT-REC-SYSTEM = No heat recovery
		HEAT-REC-SEFF = 0
		HEAT-REC-VAR-EFF = NO
		HEAT-SSEFF = 0.65
		AUX-ENERGY-CORR = 0
		AUX-ENERGY/KWH = 0.02
		VARIABLE-SPEED-PUMP = NO
		HEAT-GEN-SEFF = 0.75
		METERING = 1
		SFP-CHECK = NO

*/
class SbemHvacSystem : public SbemObject {
	
public:
	/*=== Constructors ===*/
	/* Default */
	SbemHvacSystem();
	/* Create blank HVAC-SYSTEM */
	SbemHvacSystem(const std::string& objectName);
	/* Create complete HVAC-SYSTEM */
	SbemHvacSystem(std::string objectName, std::vector<std::string> propertyStrings);

	/*=== Static methods===*/
	/* Create a basic instance */
	static SbemHvacSystem createBasic(std::string name);
	/*=== Static members ===*/
	/* SBEM object name HVAC-SYSTEM */
	static const std::string OBJECT_NAME;
	/*=== Instance members ===*/
	/* Zones whose heating, cooling and ventilation is served by this system */
	SbemObjectSet<SbemZone> zones;
	/*=== Getters ===*/
	/* 
		Get area
		
		Gets the protected area property. The property is updated by the 
		addZone and removeZone methods. Which increase or decrease the area,
		respectively.
	*/
	float getArea();
	/*=== The rest ===*/
	/*
		Associate a ZONE with this HVAC-SYSTEM.
		
		Add the SbemZone to the zones collection and increase the HVAC-SYSTEM area
		by the zone's AREA property.
	*/
	void addZone(SbemZone zone);
	/* Convert to an .inp object. See example */
	std::string toString();
protected:
	/*=== Instance members ===*/
	/* Total area served by system. Managed by addZone and removeZone */
	float area;
	
};