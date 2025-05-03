#include "sbem_window_tm_bridge.h"
/*=== Constructors ===*/
SbemWindowTmBridge::SbemWindowTmBridge(){}
SbemWindowTmBridge::SbemWindowTmBridge(std::string objectName) : SbemObject(objectName) {}
SbemWindowTmBridge::SbemWindowTmBridge(std::string objectName, std::vector<std::string> propertyStrings) : SbemObject(objectName, propertyStrings) {}
// Constants
const std::string SbemWindowTmBridge::OBJECT_NAME = "WINDOW-TM-BRIDGE";
/*=== Getters ===*/

/*=== Setters ===*/

/*=== The rest ===*/
std::string SbemWindowTmBridge::toString() {
	return "\"" + name + "\" = " + OBJECT_NAME + "\n" + propertiesString() + "\n" + OBJECT_END;
}