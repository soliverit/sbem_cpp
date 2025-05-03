#include "sbem_shower.h"
/*=== Constructors ===*/
SbemShower::SbemShower(){}
SbemShower::SbemShower(std::string objectName) : SbemObject(objectName) {}
SbemShower::SbemShower(std::string objectName, std::vector<std::string> propertyStrings) : SbemObject(objectName, propertyStrings) {}
// Constants
const std::string SbemShower::OBJECT_NAME = "SHOWER";
/*=== Getters ===*/

/*=== Setters ===*/

/*=== The rest ===*/
std::string SbemShower::toString() {
	return "\"" + name + "\" = " + OBJECT_NAME + "\n" + propertiesString() + "\n" + OBJECT_END;
}