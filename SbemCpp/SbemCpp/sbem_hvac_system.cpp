#include "sbem_hvac_system.h"

/*=== CONSTANTS ===*/
#pragma once
#include <string>
// HVAC types
const std::string SbemHvacSystem::NO_HEATING_OR_COOLING = "No Heating or Cooling";
const std::string SbemHvacSystem::CENTRAL_WATER_RADIATORS = "Central heating using water: radiators";
const std::string SbemHvacSystem::CENTRAL_WATER_CONVECTORS = "Central heating using water: convectors";
const std::string SbemHvacSystem::CENTRAL_WATER_FLOOR_HEATING = "Central heating using water: floor heating";
const std::string SbemHvacSystem::CENTRAL_AIR_DISTRIBUTION = "Central heating using air distribution";
const std::string SbemHvacSystem::ROOM_HEATER_FANNED = "Other local room heater - fanned";
const std::string SbemHvacSystem::RADIANT_HEATER_UNFLUED = "Unflued radiant heater";
const std::string SbemHvacSystem::RADIANT_HEATER_FLUED = "Flued radiant heater";
const std::string SbemHvacSystem::RADIANT_HEATERS_MULTIBURNER = "Multiburner radiant heaters";
const std::string SbemHvacSystem::AIR_HEATER_FLUED_FORCED = "Flued forced-convection air heaters";
const std::string SbemHvacSystem::AIR_HEATER_UNFLUED_FORCED = "Unflued forced-convection air heaters";
const std::string SbemHvacSystem::VAV_SINGLE_DUCT = "Single-duct VAV";
const std::string SbemHvacSystem::VAV_DUAL_DUCT = "Dual-duct VAV";
const std::string SbemHvacSystem::CABINET_INDOOR_PACKAGED = "Indoor packaged cabinet (VAV)";
const std::string SbemHvacSystem::FAN_COIL_SYSTEMS = "Fan coil systems";
const std::string SbemHvacSystem::INDUCTION_SYSTEM = "Induction system";
const std::string SbemHvacSystem::VOLUME_FIXED_AIR = "Constant volume system (fixed fresh air rate)";
const std::string SbemHvacSystem::VOLUME_VARIABLE_AIR = "Constant volume system (variable fresh air rate)";
const std::string SbemHvacSystem::MULTIZONE_HOT_COLD = "Multizone (hot deck/cold deck)";
const std::string SbemHvacSystem::TERMINAL_REHEAT = "Terminal reheat (constant volume)";
const std::string SbemHvacSystem::DUAL_DUCT_CONSTANT = "Dual duct (constant volume)";
const std::string SbemHvacSystem::CHILLED_DISP_VENT = "Chilled ceilings or passive chilled beams and displacement ventilation";
const std::string SbemHvacSystem::CHILLED_BEAMS_ACTIVE = "Active chilled beams";
const std::string SbemHvacSystem::WATER_LOOP_HEAT_PUMP = "Water loop heat pump";
const std::string SbemHvacSystem::VARIABLE_REFRIGERANT_FLOW = "Variable refrigerant flow";
const std::string SbemHvacSystem::SPLIT_SYSTEM = "Split or multi-split system";
const std::string SbemHvacSystem::SPLIT_SYSTEM_VENT = "Split or multi-split system with ventilation";
const std::string SbemHvacSystem::SINGLE_ROOM_COOLING = "Single room cooling system";
const std::string SbemHvacSystem::ROOM_HEATER_UNFANNED = "Other local room heater - unfanned";
const std::string SbemHvacSystem::CHILLED_MIX_VENT = "Chilled ceilings or passive chilled beams and mixing ventilation";
// Heat Source 
const std::string SbemHvacSystem::LTHW_BOILER = "LTHW boiler";
const std::string SbemHvacSystem::MTHW_BOILER = "MTHW boiler";
const std::string SbemHvacSystem::HTHW_BOILER = "HTHW boiler";
const std::string SbemHvacSystem::AIR_HEATER = "Air heater";
const std::string SbemHvacSystem::UNFLUED_GAS_WARM_AIR_HEATER = "Unflued gas warm air heater";
const std::string SbemHvacSystem::UNITARY_RADIANT_HEATER = "Unitary radiant heater";
const std::string SbemHvacSystem::RADIANT_HEATER = "Radiant heater";
const std::string SbemHvacSystem::UNFLUED_RADIANT_HEATER = "Unflued radiant heater";
const std::string SbemHvacSystem::DIRECT_OR_STORAGE_ELECTRIC_HEATER = "Direct or storage electric heater";
const std::string SbemHvacSystem::HEAT_PUMP_GAS_OIL_AIR_SOURCE = "Heat pump (gas/oil): air source";
const std::string SbemHvacSystem::HEAT_PUMP_GAS_OIL_GROUND_OR_WATER_SOURCE = "Heat pump (gas/oil): ground or water source";
const std::string SbemHvacSystem::ROOM_HEATER = "Room heater";
const std::string SbemHvacSystem::DISTRICT_HEATING = "District heating";
const std::string SbemHvacSystem::CHP = "CHP";
const std::string SbemHvacSystem::DIRECT_GAS_FIRING = "Direct gas firing";
const std::string SbemHvacSystem::HEAT_PUMP_ELECTRIC_AIR_SOURCE = "Heat pump (electric): air source";
const std::string SbemHvacSystem::HEAT_PUMP_ELECTRIC_GROUND_OR_WATER_SOURCE = "Heat pump (electric): ground or water source";

/*=== Constructors ===*/
SbemHvacSystem::SbemHvacSystem() : _area(0){}
SbemHvacSystem::SbemHvacSystem(const std::string& objectName) : SbemObject(objectName), _area(0.0) {}
SbemHvacSystem::SbemHvacSystem(std::string objectName, std::vector<std::string> propertyStrings) : SbemObject(objectName, propertyStrings), _area(0){}
/*=== Static methods ===*/
SbemHvacSystem SbemHvacSystem::createBasic(std::string name) {
	SbemHvacSystem hvac = SbemHvacSystem(name);
	hvac.addStringProperty("TYPE", "Flued forced-convection air heaters");
	hvac.addStringProperty("HEAT-SOURCE", "Air heater");
	hvac.addStringProperty("CHP", "NO");
	hvac.addStringProperty("FUEL-TYPE", "Natural Gas");
	hvac.addStringProperty("HEAT-REC-SYSTEM", "No heat recovery");
	hvac.addNumericProperty("HEAT-REC-SEFF", 0);
	hvac.addStringProperty("HEAT-REC-VAR-EFF", "NO");
	hvac.addNumericProperty("HEAT-SSEFF", 0.65f);
	hvac.addNumericProperty("AUX-ENERGY-CORR", 0);
	hvac.addNumericProperty("AUX-ENERGY/KWH", 0.02f);
	hvac.addStringProperty("VARIABLE-SPEED-PUMP", "NO");
	hvac.addNumericProperty("HEAT-GEN-SEFF", 0.75f);
	hvac.addNumericProperty("METERING", 1);
	hvac.addStringProperty("SFP-CHECK", "NO");
	return hvac;
}
/*=== Static members ===*/
const std::string SbemHvacSystem::OBJECT_NAME = "HVAC-SYSTEM";
/*=== Getters ===*/

float SbemHvacSystem::area() { return _area; }
/*=== Setters ===*/
void SbemHvacSystem::addZone(SbemZone zone) {
	zones.push(std::make_shared<SbemZone>(zone));
	_area += zone.area();
}

std::string SbemHvacSystem::toString(){
	std::string object	= "\n\"" + name + "\" = " + OBJECT_NAME + "\n" + propertiesString() + "\n" + SbemObject::OBJECT_END;

	for (size_t zoneID = 0; zoneID < zones.size(); zoneID++)
		object += "\n" + zones.objects[zoneID]->toString();
	return object;
}
HvacSystemType SbemHvacSystem::hvacSystemType() {
	return HvacSystemType::DICTIONARY[getStringProperty("TYPE")->getValue()];
}
//=== Has things methods === //

//-> Has things
bool SbemHvacSystem::hasCooling() {
	return hvacSystemType().hasCooling();
}
bool SbemHvacSystem::hasHeating() {
	return getStringProperty("TYPE")->getValue() != NO_HEATING_OR_COOLING;
}
bool SbemHvacSystem::hasMechanicalVentiliation() {
	return hasStringProperty("SFP-CHECK") && getStringProperty("SFP-CHECK")->getValue() == "YES";
}
bool SbemHvacSystem::hasMechanicalVentilationAndCooling() {
	return true;
}
/*=== The rest ===*/ 