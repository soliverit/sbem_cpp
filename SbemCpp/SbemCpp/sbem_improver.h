#pragma once
/*===
	Includes
===*/
// Native
#include <memory>
// Project
#include "sbem_model.h"
/*
	Improver (abstract)
*/
class SbemImprover {
public:
	/*=== Constructors ===*/
	SbemImprover();
	SbemImprover(std::shared_ptr<SbemModel> sbemModel);

	/*
		Apply the improvement

		Whatever  you do to the SbemModel to change its energy performance, it
		happens here. For example, lighting template replacement

			For each zone
				1) identify existing template. E.g Tungsten or Halogen
				2) Replace with LED
				3) add modification fro cost 
	*/
	virtual void apply() = 0;
	/*
		Calculate the cost


		Normally, this would be a set of common methods lim m2, count, kW etc, but
		since it's c++ we're defning these on a per improvement or improvement class
		basis. For example: 

		--- Improvement-specific ---
		class InstallPvs{
			float cost() override { return kWp * unitCost;}
		}

		--- Category-specific ---
		class LightingImprovement{
			LightingImprovement(float lampUnitCost);
			std::vector<SbemZone> modifiedZones;
			float unitCost;
			float cost() override{return m2 * unitCost;}
			float m2{
				float area;
				for(size_t zoneID = 0; zoneID < modifieddZones.size(); zoneID++)
					area += modifiedZones[zoneID].numericProperties["AREA"].getValue();
				return area;
			}
		}
		class TungstenReplacement : public {
			TungstenReplacement(float lampUnitCost);
		}
		TungstenReplacement::TungstenReplacement(float lampUnitCost) : LightingImrpovement(lampUnitCost){}
	*/
	virtual float cost() = 0;

	SbemModel getModel();
protected:

	std::shared_ptr<SbemModel> model;
};