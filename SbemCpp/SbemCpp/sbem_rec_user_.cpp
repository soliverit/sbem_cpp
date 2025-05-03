#include "sbem_rec_user.h"
/*=== Constructors ===*/
SbemRecUser::SbemRecUser(){}
SbemRecUser::SbemRecUser(std::string objectName) : SbemObject(objectName) {}
SbemRecUser::SbemRecUser(std::string objectName, std::vector<std::string> propertyStrings) : SbemObject(objectName, propertyStrings) {}
// Constants
const std::string SbemRecUser::OBJECT_NAME = "REC-USER";
/*=== Getters ===*/

/*=== Setters ===*/

/*=== The rest ===*/
std::string SbemRecUser::toString() {
	return "\"" + name + "\" = " + OBJECT_NAME + "\n" + propertiesString() + "\n" + OBJECT_END;
}