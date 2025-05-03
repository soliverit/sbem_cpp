#include "sbem_improvement_measure.h"

/*=== Constructors ===*/
SbemImprovementMeasure::SbemImprovementMeasure(){}
SbemImprovementMeasure::SbemImprovementMeasure(const std::string& objectName) : SbemObject(objectName){}
SbemImprovementMeasure::SbemImprovementMeasure(std::string objectName, std::vector<std::string> propertyStrings) : SbemObject(objectName, propertyStrings) {}
/*=== Static members ===*/
const std::string SbemImprovementMeasure::OBJECT_NAME = "HVAC-SYSTEM";
/*=== Instance methods ===*/
std::string SbemImprovementMeasure::toString() {
	return "\"" + name + "\" = " + OBJECT_NAME + "\n" + propertiesString() + "\n" + OBJECT_END;
}