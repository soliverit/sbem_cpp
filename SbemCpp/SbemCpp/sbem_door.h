#pragma once
/*===
	Includes
===*/
// Native

// Project
#include "sbem_construction.h"
#include "sbem_object.h"
#include "sbem_door_tm_bridge.h"
/*
	SBEM Door

	It's a door!

		MULTIPLIER = 1
		TYPE = Vehicle Access Doors
		AREA = 18.78
		CONSTRUCTION = "VA"
*/
class SbemDoor : public SbemObject {
public:
	/*=== Constructors ===*/
	SbemDoor();
	SbemDoor(std::string objectName);
	SbemDoor(std::string objectName, std::vector<std::string> propertyStrings);
	/*=== Static methods===*/
	static SbemDoor createBasic(std::string name);
	/*=== Static members ===*/
	static const std::string OBJECT_NAME;
	/*=== Instance methods ===*/
	// Add a DOOR-TM-BRIDGE object
	void setThermalBridge(SbemDoorTmBridge thermalBridge);
	// Check for a DOOR-TM-BRIDGE
	bool hasThermalBridge();
	// Attach the SbemConstruction object
	void setConstruction(std::shared_ptr<SbemConstruction> cons);
	/* Convert to an .inp object */
	std::string toString();
	/*=== Getters ===*/
	/* Convert to an .inp object. See example */
	float getArea();
protected:
	std::shared_ptr<SbemConstruction> construction;
	/*=== Instance members ===*/
	/* Door has a thermal bridge? */
	bool				addedThermalBridge;
	/* The door's thermal bridge if it has one */
	SbemDoorTmBridge	tmBridge;
};