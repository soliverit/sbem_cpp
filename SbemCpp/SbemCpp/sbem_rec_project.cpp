#include "sbem_rec_project.h"
/*=== Constructors ===*/
SbemRecProject::SbemRecProject(){}
SbemRecProject::SbemRecProject(std::string objectName) : SbemObject(objectName) {}
SbemRecProject::SbemRecProject(std::string objectName, std::vector<std::string> propertyStrings) : SbemObject(objectName, propertyStrings) {}
// Constants
const std::string SbemRecProject::OBJECT_NAME = "REC-PROJECT";
/*=== Getters ===*/

/*=== Setters ===*/

/*=== The rest ===*/
std::string SbemRecProject::toString() {
	return "\"" + name + "\" = " + OBJECT_NAME + "\n" + propertiesString() + "\n" + OBJECT_END;
}