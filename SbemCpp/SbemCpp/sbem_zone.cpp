#include "sbem_zone.h"
#include "iostream"
/*=== Constructors ===*/
SbemZone::SbemZone(){}
SbemZone::SbemZone(std::string objectName) : SbemObject(objectName) {
	activity	= SbemActivityData::DICTIONARY[int(getNumericProperty("ACTIVITY")->getValue())];
}
SbemZone::SbemZone(std::string objectName, std::vector<std::string> propertyStrings) : SbemObject(objectName, propertyStrings) {
	for(size_t i = 0; i < numericPropertyKeys.size(); i++)
		std::cout << "\n" << numericPropertyKeys[i];
	std::cout<< numericPropertyKeys.size();
	std::cout<< numericProperties["ACTIVITY"].getValue();
	std::cout << "\n-\n";
	activity = SbemActivityData::DICTIONARY[int(getNumericProperty("ACTIVITY")->getValue())];
}
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