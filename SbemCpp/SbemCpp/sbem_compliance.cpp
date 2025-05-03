#include "sbem_compliance.h"
/*=== Constructors ===*/
SbemCompliance::SbemCompliance(){}
SbemCompliance::SbemCompliance(std::string objectName) : SbemObject(objectName) {}
SbemCompliance::SbemCompliance(std::string objectName, std::vector<std::string> propertyStrings) : SbemObject(objectName, propertyStrings){}
// Constants
const std::string SbemCompliance::OBJECT_NAME = "COMPLIANCE";
/*=== Getters ===*/

/*=== Setters ===*/

/*=== The rest ===*/
std::string SbemCompliance::toString() {
	return "\"" + name + "\" = " + OBJECT_NAME + "\n" + propertiesString() + "\n" + OBJECT_END;
}