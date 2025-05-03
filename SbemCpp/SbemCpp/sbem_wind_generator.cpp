#include "sbem_wind_generator.h"
/*=== Constructors ===*/
SbemWindGenerator::SbemWindGenerator(){}
SbemWindGenerator::SbemWindGenerator(std::string objectName) : SbemObject(objectName) {}
SbemWindGenerator::SbemWindGenerator(std::string objectName, std::vector<std::string> propertyStrings) : SbemObject(objectName, propertyStrings) {}
// Constants
const std::string SbemWindGenerator::OBJECT_NAME = "WIND-GENERATOR";
/*=== Getters ===*/

/*=== Setters ===*/

/*=== The rest ===*/
std::string SbemWindGenerator::toString() {
	return "\"" + name + "\" = " + OBJECT_NAME + "\n" + propertiesString() + "\n" + OBJECT_END;
}