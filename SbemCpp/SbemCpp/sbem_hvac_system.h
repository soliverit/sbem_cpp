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
	// Heat Sources
	static const std::string LTHW_BOILER;
	static const std::string MTHW_BOILER;
	static const std::string HTHW_BOILER;
	static const std::string AIR_HEATER;
	static const std::string UNFLUED_GAS_WARM_AIR_HEATER;
	static const std::string UNITARY_RADIANT_HEATER;
	static const std::string RADIANT_HEATER;
	static const std::string UNFLUED_RADIANT_HEATER;
	static const std::string DIRECT_OR_STORAGE_ELECTRIC_HEATER;
	static const std::string HEAT_PUMP_GAS_OIL_AIR_SOURCE;
	static const std::string HEAT_PUMP_GAS_OIL_GROUND_OR_WATER_SOURCE;
	static const std::string ROOM_HEATER;
	static const std::string DISTRICT_HEATING;
	static const std::string CHP;
	static const std::string DIRECT_GAS_FIRING;
	static const std::string HEAT_PUMP_ELECTRIC_AIR_SOURCE;
	static const std::string HEAT_PUMP_ELECTRIC_GROUND_OR_WATER_SOURCE;
	// HVAC Types
	static const std::string NO_HEATING_OR_COOLING;
	static const std::string CENTRAL_WATER_RADIATORS;
	static const std::string CENTRAL_WATER_CONVECTORS;
	static const std::string CENTRAL_WATER_FLOOR_HEATING;
	static const std::string CENTRAL_AIR_DISTRIBUTION;
	static const std::string ROOM_HEATER_FANNED;
	static const std::string RADIANT_HEATER_UNFLUED;
	static const std::string RADIANT_HEATER_FLUED;
	static const std::string RADIANT_HEATERS_MULTIBURNER;
	static const std::string AIR_HEATER_FLUED_FORCED;
	static const std::string AIR_HEATER_UNFLUED_FORCED;
	static const std::string VAV_SINGLE_DUCT;
	static const std::string VAV_DUAL_DUCT;
	static const std::string CABINET_INDOOR_PACKAGED;
	static const std::string FAN_COIL_SYSTEMS;
	static const std::string INDUCTION_SYSTEM;
	static const std::string VOLUME_FIXED_AIR;
	static const std::string VOLUME_VARIABLE_AIR;
	static const std::string MULTIZONE_HOT_COLD;
	static const std::string TERMINAL_REHEAT;
	static const std::string DUAL_DUCT_CONSTANT;
	static const std::string CHILLED_DISP_VENT;
	static const std::string CHILLED_BEAMS_ACTIVE;
	static const std::string WATER_LOOP_HEAT_PUMP;
	static const std::string VARIABLE_REFRIGERANT_FLOW;
	static const std::string SPLIT_SYSTEM;
	static const std::string SPLIT_SYSTEM_VENT;
	static const std::string SINGLE_ROOM_COOLING;
	static const std::string ROOM_HEATER_UNFANNED;
	static const std::string CHILLED_MIX_VENT;
	
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
	float area();
	//-> Has things
	bool hasCooling();
	bool hasHeating();
	bool hasMechanicalVentiliation();
	bool hasMechanicalVentilationAndCooling();

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
	float _area;
	
};