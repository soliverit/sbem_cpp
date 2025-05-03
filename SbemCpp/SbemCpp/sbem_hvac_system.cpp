#include "sbem_hvac_system.h"

/*=== Constructors ===*/
SbemHvacSystem::SbemHvacSystem() : area(0){}
SbemHvacSystem::SbemHvacSystem(const std::string& objectName) : SbemObject(objectName), area(0.0) {}
SbemHvacSystem::SbemHvacSystem(std::string objectName, std::vector<std::string> propertyStrings) : SbemObject(objectName, propertyStrings), area(0){}
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
	hvac.addNumericProperty("HEAT-SSEFF", 0.65);
	hvac.addNumericProperty("AUX-ENERGY-CORR", 0);
	hvac.addNumericProperty("AUX-ENERGY/KWH", 0.02);
	hvac.addStringProperty("VARIABLE-SPEED-PUMP", "NO");
	hvac.addNumericProperty("HEAT-GEN-SEFF", 0.75);
	hvac.addNumericProperty("METERING", 1);
	hvac.addStringProperty("SFP-CHECK", "NO");
	return hvac;
}
/*=== Static members ===*/
const std::string SbemHvacSystem::OBJECT_NAME = "HVAC-SYSTEM";
/*=== Getters ===*/
float SbemHvacSystem::getArea() { return area; }
/*=== Setters ===*/
void SbemHvacSystem::addZone(SbemZone zone) {
	zones.push(std::make_shared<SbemZone>(zone));
	area += zone.getArea();
}

std::string SbemHvacSystem::toString(){
	std::string object	= "\n\"" + name + "\" = " + OBJECT_NAME + "\n" + propertiesString() + "\n" + SbemObject::OBJECT_END;

	for (size_t zoneID = 0; zoneID < zones.size(); zoneID++)
		object += "\n" + zones.objects[zoneID]->toString();
	return object;
}
/*=== The rest ===*/ 