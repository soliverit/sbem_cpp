#include "sbem_ses.h"
/*=== Constructors ===*/
SbemSes::SbemSes(){}
SbemSes::SbemSes(std::string objectName) : SbemObject(objectName) {}
SbemSes::SbemSes(std::string objectName, std::vector<std::string> propertyStrings) : SbemObject(objectName, propertyStrings) {}
// Constants
const std::string SbemSes::OBJECT_NAME = "SES";
/*=== Getters ===*/

/*=== Setters ===*/

/*=== The rest ===*/
std::string SbemSes::toString() {
	return "\"" + name + "\" = " + OBJECT_NAME + "\n" + propertiesString() + "\n" + OBJECT_END;
}