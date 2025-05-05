#include "lighting_replacement.h"
/*=== Constructors ===*/
LightingReplacement::LightingReplacement() {}
LightingReplacement::LightingReplacement(float lampUnitCost) : unitCost(lampUnitCost){}

// Constants

/*=== Getters ===*/

/*=== Instance methods ===*/
/*
	Apply the retrofit.

	For each zone: If there's tungsten lamps, replace them with LEDs
*/
void LightingReplacement::apply()  {
	SbemModel sbemModel = *model;
	// With every HVAC-SYSTEM
	for (size_t hvacID = 0; hvacID < sbemModel.hvacs.size(); hvacID++) {
		SbemHvacSystem hvac = *sbemModel.hvacs.objects[hvacID];
		// With every ZONE
		for (size_t zoneID = 0; zoneID < hvac.zones.size(); zoneID++) {
			SbemZone zone = *hvac.zones.objects[zoneID];
			// Check for Tungsten, replace with LEDs
			if (zone.getStringProperty("LIGHT-TYPE")->getValue() == "Tungsten or Halogen"){
				zone.setStringProperty("LIGHT-TYPE", "LED");
				modifiedZones.push_back(hvac.zones.objects[zoneID]);
			}
		}
	}
}
float LightingReplacement::cost() {
	float totalCost = 0;
	// With every modified ZONE, get retrofit cost
	for (size_t zoneID = 0; zoneID < modifiedZones.size(); zoneID++) {
		SbemZone zone	= *modifiedZones[zoneID];
		totalCost = unitCost * zone.area();
	}
	// No further changes needs
	return totalCost;
}
/*=== Setters ===*/

/*=== The rest ===*/
