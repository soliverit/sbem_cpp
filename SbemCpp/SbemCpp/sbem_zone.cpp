#include "sbem_zone.h"
#include "iostream"
/*=== Constructors ===*/
SbemZone::SbemZone(){}
SbemZone::SbemZone(std::string objectName) : SbemObject(objectName) {}
SbemZone::SbemZone(std::string objectName, std::vector<std::string> propertyStrings) : SbemObject(objectName, propertyStrings) {
	activity = SbemActivityData::DICTIONARY[int(getNumericProperty("ACTIVITY")->getValue())];
	// Some zones represent multiple zones: 
	std::cout << "\n-->";
	std::cout << hasNumericProperty("MULTIPLIER");
	std::cout << "\n";
	if (!hasNumericProperty("MULTIPLIER")){
		std::cout << "Multiplier: ";
		std::cout << getNumericProperty("MULTIPLIER");
		std::cout << "\n=====";
		_area = getNumericProperty("AREA")->getValue() * getNumericProperty("MULTIPLIER)")->getValue();
	}else
		_area = getNumericProperty("AREA")->getValue();

}
// Constants
const std::string SbemZone::OBJECT_NAME = "ZONE";
/*=== Getters ===*/
float SbemZone::area() {return _area;}
float SbemZone::windowArea() {
	wallArea();
	return _windowArea;
}
float SbemZone::wallArea() {
	if(_gotWallArea)
		return _wallArea;
	for(size_t wallID = 0; wallID < walls.size(); wallID++){
		_wallArea			+= walls.objects[wallID]->area();
		_wallSurfaceArea	+= walls.objects[wallID]->surfaceArea();
		_windowArea			+= walls.objects[wallID]->windowArea();
	}
	_gotWallArea	= true;
	return _wallArea;
}
float SbemZone::wallSurfaceArea() {
	return wallArea() - _windowArea;
}
/*=== Setters ===*/

/*=== The rest ===*/
std::string SbemZone::toString() {
	std::string object = "\"" + name + "\" = " + OBJECT_NAME + "\n" + propertiesString() + "\n" + OBJECT_END;
	for (size_t wallID = 0; wallID < walls.size(); wallID++) {
		object += "\n" + walls.objects[wallID]->toString();
	}
	return object;
}