/*===
	Includes
===*/
// Native
#include "sbem_door.h"
// Project

/*=== Constructors ===*/
SbemDoor::SbemDoor(){}
SbemDoor::SbemDoor(std::string objectName) : SbemObject(objectName) {}
SbemDoor::SbemDoor(std::string objectName, std::vector<std::string> propertyStrings) : SbemObject(objectName, propertyStrings) {}
/*=== Static methods ===*/
SbemDoor SbemDoor::createBasic(std::string name) {
	SbemDoor door = SbemDoor(name);
	door.addNumericProperty("MULTIPLIER", 1);
	door.addNumericProperty("AREA", 1);
	door.addStringProperty("TYPE", "Vehicle Access Door");
	door.addStringProperty("CONSTRUCTION", "DOOR-CONSTRUCTION");
	return door;
}
/*=== Static members ===*/
const std::string SbemDoor::OBJECT_NAME = "DOOR";
/*=== Getters ===*/
float SbemDoor::getArea() {
	// Some windows represent multiple windows. It's stupid in the context of SBEM but since it's there we need to deal with it. 
	if (hasNumericProperty("MULTIPLIER"))
		return getNumericProperty("AREA")->getValue();
	else
		return getNumericProperty("AREA")->getValue() * getNumericProperty("MULTIPLIER)")->getValue();
}
/*=== Setters ===*/
void SbemDoor::setThermalBridge(SbemDoorTmBridge thermalBridge) {
	tmBridge			= thermalBridge;
	addedThermalBridge	= true;

}
/*=== The rest ===*/
bool SbemDoor::hasThermalBridge() { return addedThermalBridge; }
void SbemDoor::setConstruction(std::shared_ptr<SbemConstruction> cons) { construction = cons; }
std::string SbemDoor::toString() {
	return "\"" + name + "\" = " + OBJECT_NAME + "\n" + propertiesString() + "\n" + OBJECT_END;
}