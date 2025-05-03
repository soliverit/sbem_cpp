#include "sbem_building_data.h"
/*=== Constructors ===*/
SbemBuildingData::SbemBuildingData(){}
SbemBuildingData::SbemBuildingData(std::string objectName) : SbemObject(objectName) {}
SbemBuildingData::SbemBuildingData(std::string objectName, std::vector<std::string> propertyStrings) : SbemObject(objectName, propertyStrings) {}
// Constants
const std::string SbemBuildingData::OBJECT_NAME = "BUILDING-DATA";
/*=== Getters ===*/

/*=== Setters ===*/

/*=== The rest ===*/
std::string SbemBuildingData::toString() {
	return "\"" + name + "\" = " + OBJECT_NAME + "\n" + propertiesString() + "\n" + OBJECT_END;
}