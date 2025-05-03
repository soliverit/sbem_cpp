#include "sbem_wall.h"
/*=== Constructors ===*/
SbemWall::SbemWall(){}
SbemWall::SbemWall(const std::string& objectName) : SbemObject(objectName) {}
SbemWall::SbemWall(std::string objectName, std::vector<std::string> propertyStrings) : SbemObject(objectName, propertyStrings) {}
/*=== Static methods ===*/
SbemWall SbemWall::createBasic(std::string name) {
	SbemWall wall = SbemWall(name);
	wall.addNumericProperty("MULTIPLIER", 1);
	wall.addStringProperty("TYPE", "Conditioned adjoining space");
	wall.addStringProperty("TYPE-ENV", "Wall");
	wall.addNumericProperty("LENGTH", 1.5);
	wall.addNumericProperty("PITCH", 90);
	wall.addNumericProperty("AREA", 3.75);
	wall.addStringProperty("ORIENTATION", "South");
	wall.addStringProperty("CONSTRUCTION", "INT WALL-Conditioned adjoining space");
	return wall;
}
// Constants
const std::string SbemWall::OBJECT_NAME = "WALL";
/*=== Instance methods ===*/
void SbemWall::setConstruction(std::shared_ptr<SbemConstruction> cons){construction = cons;}
/*=== Getters ===*/
float SbemWall::getArea() { 
	// Some walls represent multiple walls. Pointless but we need to handle it anyway.
	if (hasNumericProperty("MULTIPLIER"))
		return getNumericProperty("AREA")->getValue();
	else
		return getNumericProperty("AREA")->getValue() * getNumericProperty("MULTIPLIER)")->getValue();
;}
/*=== Setters ===*/
void SbemWall::addDoor(SbemDoor door) { doors.push(std::make_shared<SbemDoor>(door)); }
void SbemWall::addWindow(SbemWindow window) { windows.push(std::make_shared<SbemWindow>(window)); }
/*=== The rest ===*/
std::string SbemWall::toString() {
	setStringProperty("CONSTRUCTION", "\"" + construction->name + "\"");
	std::string object	= "\"" + name + "\" = " + OBJECT_NAME + "\n" + propertiesString() + "\n" + OBJECT_END;
	for (size_t doorID = 0; doorID < doors.size(); doorID++)
		object += "\n" + doors.objects[doorID]->toString();
	for (size_t windowID = 0; windowID < windows.size(); windowID++)
		object += "\n" + windows.objects[windowID]->toString();
	return object;
}