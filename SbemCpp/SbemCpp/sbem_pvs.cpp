#include "sbem_pvs.h"
/*=== Constructors ===*/
SbemPvs::SbemPvs(){}
SbemPvs::SbemPvs(std::string objectName) : SbemObject(objectName) {}
SbemPvs::SbemPvs(std::string objectName, std::vector<std::string> propertyStrings) : SbemObject(objectName, propertyStrings) {}
// Constants
const std::string SbemPvs::OBJECT_NAME = "PVS";
/*=== Getters ===*/

/*=== Setters ===*/

/*=== The rest ===*/
std::string SbemPvs::toString() {
	return "\"" + name + "\" = " + OBJECT_NAME + "\n" + propertiesString() + "\n" + OBJECT_END;
}