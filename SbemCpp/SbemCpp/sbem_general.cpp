#include "sbem_general.h"
/*=== Constructors ===*/
SbemGeneral::SbemGeneral(){}
SbemGeneral::SbemGeneral(std::string objectName) : SbemObject(objectName) {}
SbemGeneral::SbemGeneral(std::string objectName, std::vector<std::string> propertyStrings) : SbemObject(objectName, propertyStrings) {}
// Constants
const std::string SbemGeneral::OBJECT_NAME = "GENERAL";
/*=== Getters ===*/

/*=== Setters ===*/

/*=== The rest ===*/
std::string SbemGeneral::toString() {
	return "\"" + name + "\" = " + OBJECT_NAME + "\n" + propertiesString() + "\n" + OBJECT_END;
}