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

	virtual void apply() override;
	virtual float cost() override;
protected:
	std::vector<std::shared_ptr<SbemZone>> modifiedZones;
	float unitCost;
};