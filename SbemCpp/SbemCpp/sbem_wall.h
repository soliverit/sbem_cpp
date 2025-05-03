#pragma once
/*===
	Includes
===*/
// Native

// Project
#include "sbem_construction.h"
#include "sbem_object.h"
#include "sbem_object_set.h"
#include "sbem_door.h"
#include "sbem_window.h"
/*
	SBEM Wall

	Vertical surfaces.

		MULTIPLIER = 1
		TYPE = Underground
		TYPE-ENV = Floor or Ceiling
		PITCH = 0
		AREA = 2.88
		ORIENTATION = Horizontal
		CONSTRUCTION = "GF"
*/
class SbemWall : public SbemObject {
public:
	/*=== Constructors ===*/
	/* Default */
	SbemWall();
	/* Create blank WALL */
	SbemWall(const std::string& objectName);
	/* Create complete WALL */
	SbemWall(std::string objectName, std::vector<std::string> propertyStrings);
	/* Create a complete wall with an SbemConstruction */
	SbemWall(std::string objectName, std::vector<std::string> propertyStrings, std::shared_ptr<SbemConstruction> cons);
	/*=== Static methods===*/
	/* Create a basic instance */
	static SbemWall createBasic(std::string name);
	/*=== Static members ===*/
	/* SBEM object name WALL */
	static const std::string OBJECT_NAME;
	static const std::string EXTERIOR;
	static const std::string STRONGLY_VENTILATED_SPACES;
	static const std::string UNHEATED_ADJOINING_SPACE;
	static const std::string CONDITIONED_ADJOINING_SPACE;
	static const std::string UNDERGROUND;
	static const std::string SAME_SPACE;

	static const std::string WALL;
	static const std::string ROOF;
	static const std::string FLOOR_OR_CEILING;
	static const std::string DOOR;
	/*=== Instance methods ===*/
	/* Walls can have doors: Add a door to this wall */
	void addDoor(SbemDoor door);
	/* Walls can have windows: Add a window to this wall*/
	void addWindow(SbemWindow window);
	/* Walls have a construction, obviously. */
	void setConstruction(std::shared_ptr<SbemConstruction> cons);
	/* 
		Convert to SBEM object -
		
		Wall object structure includes nested SbemDoor(s) and SbemWindow(s). This method
		create the WALL object and appends all DOOR and WINDOW objects to it. 

		NOTE: can't be SbemObject method due to OBJECT_NAME reference 
	*/
	std::string toString();
	/*=== Instance members ===*/
	/* Doors embedded in this wall */
	SbemObjectSet<SbemDoor>		doors;
	/* Windows embedded in this wall */
	SbemObjectSet<SbemWindow>	windows;
	/*=== Getters ===*/
	/*
		Get the wall area

		WALL area is the sum of the AREA * MULTIPLIER - sum(doors.area) - sum(windows.area) 
	*/
	float getArea();
protected:
	std::shared_ptr<SbemConstruction> construction;
};