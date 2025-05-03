#include "sbem_door_tm_bridge.h"
/*=== Constructors ===*/
SbemDoorTmBridge::SbemDoorTmBridge(){}
SbemDoorTmBridge::SbemDoorTmBridge(std::string objectName) : SbemObject(objectName) {}
SbemDoorTmBridge::SbemDoorTmBridge(std::string objectName, std::vector<std::string> propertyStrings) : SbemObject(objectName, propertyStrings) {}
// Constants
const std::string SbemDoorTmBridge::OBJECT_NAME = "DOOR-TM-BRIDGE";
/*=== Getters ===*/

/*=== Setters ===*/

/*=== The rest ===*/
std::string SbemDoorTmBridge::toString() {
	return "\"" + name + "\" = " + OBJECT_NAME + "\n" + propertiesString() + "\n" + OBJECT_END;
}