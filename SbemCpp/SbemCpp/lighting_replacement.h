#pragma once
/*===
	Includes
===*/
// Native

// Project
#include "sbem_improver.h"
#include "sbem_zone.h"
/*
	Lighting Improvement (category class)

	A base class for lighting retrofits
*/
class LightingReplacement : public SbemImprover {
public:
	LightingReplacement();
	LightingReplacement(float lampUnitCost);
	/*=== Instance methods ===*/
	// Apply the retrofit to the target model
	virtual void apply() override;
	// Calculate the retrofit cost
	virtual float cost() override;
protected:
	// For tracking modified zones.
	std::vector<std::shared_ptr<SbemZone>> modifiedZones;
	// Cost per m2
	float unitCost;
};