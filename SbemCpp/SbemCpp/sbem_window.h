#pragma once
/*===
	Includes
===*/
// Native

// Project
#include "sbem_glass.h"
#include "sbem_object.h"
#include "sbem_window_tm_bridge.h"
/*
	SBEM window

	It's a window!

		MULTIPLIER = 1
		AREA = 3.67
		DEV-PROJ-RATIO = 1
		FRAME-FACTOR = 0.1
		SHADING-POSITION = None (no shading)
		SHADING-FACTOR = 1
		ASPECT-RATIO = 1.6757
		GLASS = "SG METAL"
		BRISE-SOLEIL = NO
*/
class SbemWindow : public SbemObject {
public:
	/*=== Constructors ===*/
	/* Default */
	SbemWindow();
	/* Create blank WINDOW */
	SbemWindow(std::string objectName);
	/* Create complete WINDOW */
	SbemWindow(std::string objectName, std::vector<std::string> propertyStrings);
	/*=== Static methods===*/
	/* Create a basic instance */
	static SbemWindow createBasic(std::string name);
	/*=== Static members ===*/
	/* SBEM object name WINDOW */
	static const std::string OBJECT_NAME;
	/*=== Instance methods ===*/
	/* Some windows have thermal bridge obejcts. Add it here */
	void setThermalBridge(SbemWindowTmBridge thermalBridge);
	/* Some window shave thermal bridge objects. Check if this does here*/
	bool hasThermalBridge();
	/* Associate window with CONSTRUCTION */
	void setGlass(std::shared_ptr<SbemGlass> gls);
	/* Convert to an .inp object. See example */
	std::string toString();
	/*=== Getters ===*/
	/* Get the area: AREA * MULTIPLIER */
	float getArea();
protected:
	/*=== Instance members ===*/
	/* The GLASS that defines thermal properties */
	std::shared_ptr<SbemGlass> glass;
	/* Some windowns have theremal bridge objects. It's tracked here */
	bool				addedThermalBridge;
	/* Some window shave thermal bridge objects. It's stroed here */
	SbemWindowTmBridge	tmBridge;
};