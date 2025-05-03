#pragma once
/*===
	Includes
===*/
// Native

// Project
#include "sbem_object.h"
#include "sbem_wall.h"
#include "sbem_activity_data.h"
/*
	SBEM Zone

	Activity spaces within the building/discrete space.

		ISBEM-ID = 78
		ACTIVITY = 1053
		ACTIVITY-NAME = Circulation area (corridors and stairways)
		MULTIPLIER = 1
		AREA = 3.59
		HEIGHT = 2.5
		VENT-ZONE-HVAC = ZONE
		Q-V-TYPE = Natural Supply
		F-CTRL-VENT-DEM = No demand-controlled ventilation
		HEAT-REC-SYSTEM = No heat recovery
		HEAT-REC-SEFF = 0
		HEAT-REC-VAR-EFF = NO
		HEPA-FILTER = NO
		VENT-MECH-EXH = NO
		DESTRAT-FAN = NO
		VENT-SFP = 1.5
		SFP-TU = 0.8
		Q50-INF = 15
		DHW-GENERATOR = "NO HWS"
		DHW-PIPE-LEN = 0
		LIGHT-CASE = UNKNOWN
		LIGHT-TYPE = Tungsten or Halogen
		LIGHT-DISPLAY-EFF = NO
		LIGHT-CONTROL = MANUAL
		LIGHT-DL-AUT-ZONE = YES
		LIGHT-OCC-SENS-T = NONE
		LIGHT-TIME-SWITCH = NO
		JNCT-ROOF-WALL-MC = 0.28
		JNCT-WALL-GRND-MC = 1.15
		JNCT-WALL-WALL-MC = 0.25
		JNCT-WALL-FLR-MC = 0
		JNCT-LINTEL-MC = 1.27
		JNCT-SILL-MC = 1.27
		JNCT-JAMB-MC = 1.27
		JNCT-ROOF-WALL = 0.12
		JNCT-WALL-GRND = 0.16
		JNCT-WALL-WALL = 0.09
		JNCT-WALL-FLR = 0.07
		JNCT-LINTEL = 0.3
		JNCT-SILL = 0.04
		JNCT-JAMB = 0.05
		JNCT-ACCR-DETAIL = { 0, 0, 0, 0, 0, 0, 0, 0, 0 }
		JNCT-ACCR-DETAIL-MC = { 0, 0, 0, 0, 0, 0, 0, 0, 0 }
		NIGHT-COOLING = NO
		CONSTANT-ILLUM = NO
*/
class SbemZone : public SbemObject {
public:
/*=== Constructors ===*/
	/* Default */
	SbemZone();
	/* Create blank ZONE */
	SbemZone(std::string objectName);
	/* Create complete ZONE */
	SbemZone(std::string objectName, std::vector<std::string> propertyStrings);
	/*=== Static methods===*/
	/* Create a basic instance */
	static SbemDoor createBasic(std::string name);
	/*=== Static members ===*/
	/* SBEM object name ZONE */
	static const std::string OBJECT_NAME;
	/*=== Instance methods ===*/
	/*
		Convert ZONE to String
		
		Zones have walls. In addition to creating this SbemZone's SBEM object, it calls all
		walls' toString() and appends them to its object.
	*/
	std::string toString();
	/*=== Instance members ===*/
	SbemActivityData activity;
	/* Zones always have walls. Store them here */
	SbemObjectSet<SbemWall> walls;
	/*=== Getters ===*/ 
	/* Get AREA * MULTIPLIER */
	float getArea();
};