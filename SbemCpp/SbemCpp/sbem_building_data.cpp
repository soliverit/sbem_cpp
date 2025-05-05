#include "sbem_building_data.h"
/*
	SBEM building data

	Post-SBEM _epc.inp object with information about energy demand, consumption, and performance.

		ANALYSIS       = ACTUAL
		AREA        = 175.85
		AREA-EXT       = 733.6
		WEATHER     = MAN
		Q50-INF     = 15
		BUILDING-W/K      = 630.78
		BUILDING-W/M2K    = 0.859842
		BUILDING-ALPHA    = 28.718
		KWH/M2-HEAT    = 26.896
		KWH/M2-COOL    = 0
		KWH/M2-AUX     = 0
		KWH/M2-LIGHT      = 53.265
		KWH/M2-DHW     = 7.81473
		KWH/M2-EQUP    = 29.9843
		KWH/M2-NATGAS     = 0
		KWH/M2-LPG     = 0
		KWH/M2-BIOGAS     = 0
		KWH/M2-OIL     = 0
		KWH/M2-COAL    = 0
		KWH/M2-ANTHRACITE    = 0
		KWH/M2-SMOKELESS     = 0
		KWH/M2-DUELFUEL   = 0
		KWH/M2-BIOMASS    = 0
		KWH/M2-SUPELEC    = 87.9758
		KWH/M2-WASTEHEAT     = 0
		KWH/M2-DISTRICT-HEATING = 0
		KWH/M2-DISP    = 0
		KWH/M2-PVS     = 0
		KWH/M2-WIND    = 0
		KWH/M2-CHP     = 0
		KWH/M2-SES     = 0
		KWH/M2-HEAT-PUMP     = 0
		KWH/M2-HEAT-DEMAND   = 254.278
		KWH/M2-COOL-DEMAND   = 14.9127
		KWH/M2-DEMAND-ALL    = 269.191
		KWH/M2-CONSUM-ALL    = 87.9755
		KG/M2-CO2      = 12.6062
		PRIM-KWH/M2    = 134.602
		ACT-AREA       = { 1063, 145.38, 1053, 6.47, 1066, 15.34, 1060, 8.66 }
*/
/*=== Constructors ===*/
SbemBuildingData::SbemBuildingData(){}
SbemBuildingData::SbemBuildingData(std::string objectName) : SbemObject(objectName) {}
SbemBuildingData::SbemBuildingData(std::string objectName, std::vector<std::string> propertyStrings) : SbemObject(objectName, propertyStrings) {}
// Constants
const std::string SbemBuildingData::OBJECT_NAME = "BUILDING-DATA";
/*=== Getters ===*/

/*=== Setters ===*/

/*=== The rest ===*/
std::string SbemBuildingData::toString() {
	return "\"" + name + "\" = " + OBJECT_NAME + "\n" + propertiesString() + "\n" + OBJECT_END;
}