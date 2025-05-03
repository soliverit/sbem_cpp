#include "sbem_epc.h"
/*=== Constructors ===*/
SbemEpc::SbemEpc(){}
SbemEpc::SbemEpc(std::string objectName) : SbemObject(objectName) {}
SbemEpc::SbemEpc(std::string objectName, std::vector<std::string> propertyStrings) : SbemObject(objectName, propertyStrings) {}
// Constants
const std::string SbemEpc::OBJECT_NAME = "EPC";
/*=== Getters ===*/

/*=== Setters ===*/

/*=== The rest ===*/
std::string SbemEpc::toString() {
	return "\"" + name + "\" = " + OBJECT_NAME + "\n" + propertiesString() + "\n" + OBJECT_END;
}