#include "sbem_construction.h"
/*=== Constructors ===*/
SbemConstruction::SbemConstruction(){}
SbemConstruction::SbemConstruction(std::string objectName) : SbemObject(objectName) {}
SbemConstruction::SbemConstruction(std::string objectName, std::vector<std::string> propertyStrings) : SbemObject(objectName, propertyStrings) {}
/*=== Static methods ===*/
SbemConstruction SbemConstruction::createBasic(std::string name) {
	SbemConstruction construction = SbemConstruction(name);
	construction.addStringProperty("TYPE", "U_VALUE");
	construction.addStringProperty("U-VALUE-CORR", "NO");
	construction.addStringProperty("METAL-CLADDING", "NO");
	construction.addStringProperty("CM", "{ 4.93, 4.93 }");
	construction.addNumericProperty("U-VALUE", 1);
	return construction;
}


/*=== Static members ===*/ 
const std::string SbemConstruction::OBJECT_NAME = "CONSTRUCTION";
/*=== Getters ===*/

/*=== Setters ===*/

/*=== The rest ===*/
std::string SbemConstruction::toString() {
	return "\"" + name + "\" = " + OBJECT_NAME + "\n" + propertiesString() + "\n" + OBJECT_END;
}