#include "sbem_zone.h"
/*=== Constructors ===*/
SbemZone::SbemZone(){}
SbemZone::SbemZone(std::string objectName) : SbemObject(objectName) {}
SbemZone::SbemZone(std::string objectName, std::vector<std::string> propertyStrings) : SbemObject(objectName, propertyStrings) {}
// Constants
const std::string SbemZone::OBJECT_NAME = "ZONE";
/*=== Getters ===*/
float SbemZone::getArea() {
	// Some zones represent multiple zones: 
	if (hasNumericProperty("MULTIPLIER"))
		return getNumericProperty("AREA")->getValue();
	else
		return getNumericProperty("AREA")->getValue() * getNumericProperty("MULTIPLIER)")->getValue();
}
/*=== Setters ===*/

/*=== The rest ===*/
std::string SbemZone::toString() {
	std::string object = "\"" + name + "\" = " + OBJECT_NAME + "\n" + propertiesString() + "\n" + OBJECT_END;
	for (size_t wallID = 0; wallID < walls.size(); wallID++) {
		object += "\n" + walls.objects[wallID]->toString();
	}
	return object;
}