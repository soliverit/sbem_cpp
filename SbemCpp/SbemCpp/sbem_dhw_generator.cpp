#include "sbem_dhw_generator.h"
/*=== Constructors ===*/
SbemDhwGenerator::SbemDhwGenerator(){}
SbemDhwGenerator::SbemDhwGenerator(std::string objectName) : SbemObject(objectName) {}
SbemDhwGenerator::SbemDhwGenerator(std::string objectName, std::vector<std::string> propertyStrings) : SbemObject(objectName, propertyStrings) {}
// Constants
const std::string SbemDhwGenerator::OBJECT_NAME = "DHW-GENERATOR";
/*=== Getters ===*/

/*=== Setters ===*/

/*=== The rest ===*/
std::string SbemDhwGenerator::toString() {
	return "\"" + name + "\" = " + OBJECT_NAME + "\n" + propertiesString() + "\n" + OBJECT_END;
}