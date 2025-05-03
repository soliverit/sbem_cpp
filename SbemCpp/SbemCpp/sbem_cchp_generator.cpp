#include "sbem_cchp_generator.h"

/*=== Constructors ===*/
SbemCchpGenerator::SbemCchpGenerator(){}
SbemCchpGenerator::SbemCchpGenerator(std::string objectName) : SbemObject(objectName){}
SbemCchpGenerator::SbemCchpGenerator(std::string objectName, std::vector<std::string> propertyStrings) : SbemObject(objectName, propertyStrings) {}
// Constants
const std::string SbemCchpGenerator::OBJECT_NAME = "CCHP-GENERATOR";
/*=== Instance methods ===*/
std::string SbemCchpGenerator::toString() {
	return "\"" + name + "\" = " + OBJECT_NAME + "\n" + propertiesString() + "\n" + OBJECT_END;
}