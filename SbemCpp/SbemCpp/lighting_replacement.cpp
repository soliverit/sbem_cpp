#include "lighting_replacement.h"
/*=== Constructors ===*/
LightingReplacement::LightingReplacement() {}
LightingReplacement::LightingReplacement(float lampUnitCost) : unitCost(lampUnitCost){}

// Constants

/*=== Getters ===*/
void LightingReplacement::apply()  {
	SbemModel sbemModel = *model;
	for (size_t hvacID = 0; hvacID < sbemModel.hvacs.size(); hvacID++) {
		SbemHvacSystem hvac = *sbemModel.hvacs.objects[hvacID];
		for (size_t zoneID = 0; zoneID < hvac.zones.size(); zoneID++) {
			SbemZone zone = *hvac.zones.objects[zoneID];
			if (zone.getStringProperty("LIGHT-TYPE")->getValue() == "Tungsten or Halogen"){
				zone.setStringProperty("LIGHT-TYPE", "LED");
				modifiedZones.push_back(hvac.zones.objects[zoneID]);
			}
		}
	}
}
float LightingReplacement::cost() {
	float totalCost = 0;
	for (size_t zoneID = 0; zoneID < modifiedZones.size(); zoneID++) {
		SbemZone zone	= *modifiedZones[zoneID];
		totalCost = unitCost * zone.getArea();
	}
	return totalCost;
}
/*=== Setters ===*/

/*=== The rest ===*/
