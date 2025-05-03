#include "sbem_glass.h"
/*=== Constructors ===*/
SbemGlass::SbemGlass(){}
SbemGlass::SbemGlass(std::string objectName) : SbemObject(objectName) {}
SbemGlass::SbemGlass(std::string objectName, std::vector<std::string> propertyStrings) : SbemObject(objectName, propertyStrings) {}
/*=== Static methods ===*/
SbemGlass SbemGlass::createBasic(std::string name) {
	SbemGlass glass = SbemGlass(name);
	glass.addStringProperty("U-VALUE-CORR", "NO");
	glass.addNumericProperty("TOT-SOL-TRANS", 0.8);
	glass.addNumericProperty("LIG-SOL-TRANS", 0.8);
	glass.addNumericProperty("U-VALUE", 3);
	return glass;
}
// Constants
const std::string SbemGlass::OBJECT_NAME = "GLASS";
/*=== Getters ===*/

/*=== Setters ===*/

/*=== The rest ===*/
std::string SbemGlass::toString() {
	return "\"" + name + "\" = " + OBJECT_NAME + "\n" + propertiesString() + "\n" + OBJECT_END;
}