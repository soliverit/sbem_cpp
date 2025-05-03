#pragma once
/*===
	Includes
===*/
// Native
#include <string>
#include <vector>
// Project
#include "sbem_building_data.h"
#include "sbem_cchp_generator.h"
#include "sbem_compliance.h"
#include "sbem_construction.h"
#include "sbem_dhw_generator.h"
#include "sbem_door.h"
#include "sbem_door_tm_bridge.h"
#include "sbem_epc.h"
#include "sbem_general.h"
#include "sbem_glass.h"
#include "sbem_hvac_system.h"
#include "sbem_improvement_measure.h"
#include "sbem_pvs.h"
#include "sbem_rec_project.h"
#include "sbem_rec_user.h"
#include "sbem_ses.h"
#include "sbem_shower.h"
#include "sbem_wall.h"
#include "sbem_wind_generator.h"
#include "sbem_window.h"
#include "sbem_window_tm_bridge.h"
#include "sbem_zone.h"
#include "sbem_object_set.h"

#include "sbem_error.h"
/*
	SBEM model

	The object model for SBEM .inp models.

	Structure:
		GENERAL
		COMPLIANCE
		CONSTURCTION[]
		GLASS[]
		SHOWER[]
		DHW-GENERATOR[]
		HVAC-SYSTEM[]
			ZONE[]
				WALL[]
					DOOR[]
					WINDOW[]
					TM-BRIDGE-WINDOW
					TM-BRIDGE-DOOR
		REC-USER[]
*/

class SbemModel {
public:
	SbemModel();
	/*=== Static methods ===*/
	static SbemModel parseInpFile(const std::string& path);
	static SbemModel parseInpContent(const std::string& content);
	static SbemModel createBasicModel();
	/*=== Static members ===*/
	static const std::string MIN_INP;
	/*=== Instance methods ===*/
	/*-- Building property getters --*/
	// Factors
	float electricEquivalentEmissionFactor();
	float electricEquivalenEmissionFactorCool();
	// Areas
	float area();
	float coolArea();
	float heatedArea();
	float mechVentArea();
	float mechVentAreaCool();
	float wallArea();
	float wallAreaCool();
	float windowArea();
	float windowAreaCool();
	// Envelopes
	float averageWallUValue();
	float averageWallUValueCool();
	float averageWindowUValue();
	float averageWindowUValueCool();
	//- Equivalents
	float electricEquivalentAverageWallUValue();
	float electricEquivalentAverageWindoeUValue();
	
	// Heating and cooling
	float averageSSEFF();
	float averageCoolSSEER();
	float averageCoolGenSEER();
	//- Equivalents
	float electricEquivalentSSEFF();

	// Ventilation 
	float freshAirRate();
	// Auxiliary

	// Lighting
	float lightingPowerDensity();
	

	/*-- Common methods --*/
	std::string toString();
	/* Something went wrong, somewhere. Add a note of it*/
	void addError(int errorCode, std::string errorMessage);
	/* Did something go wrong, somewhere? */
	bool hasErrors();
	/* User Recs are usually dead weight. Drop them */
	void dropRecUsers();
	/*
		Merge object defaults - A method for completing partial models.

		This library was written for modding games. Rather than integrate it into
		every game mod, the library acts as an external service that games send requests
		to. For example, Dungeon Keeper translates dungeons into partial models with DHWs, 
		HVACs, zones, walls, and windows. It does not define every property necessary for SBEM.

		We need to define these missing properties somehow, which is where this method comes in.

		We parse the partial model as if it were any other model. Then we iterate over each object
		and compare its properties to those of the base object of the given type from its static
		method for creating a generic instance. E.g, SbemHvacSystem::createBasic(). 

			IF a property is absent in the partial model, the property is added to the partial object
			with the value defined in the base object. 

		NOTE: SBEM is good at ignoring properties it isn't interested in. However, I wouldn't take bet
		money on it doing it every time.

		TODO: Now that I've wrote that note, the intermediary survey data object SbemSurvey/SbemSurveyObject
		has a field dedicated to properties to be removed. However, the toInpModel() method that creates the
		partial model, doesn't have a means of passing those keys. 
	*/
	void mergeObjectDefaults();
	std::vector<SbemError> getErrors();
	/*=== Instance members ===*/
	// SBEM Objects
	SbemGeneral								general;
	SbemCompliance							compliance;
	SbemRecProject							recProject;
	SbemPvs									pvs;
	SbemSes									ses;
	SbemWindGenerator						windGenerator;
	SbemObjectSet<SbemConstruction>			constructions;	
	SbemObjectSet<SbemGlass>				glasses;		
	SbemObjectSet<SbemDhwGenerator>			dhws;			
	SbemObjectSet<SbemCchpGenerator>		cchps;			
	SbemObjectSet<SbemShower>				showers;		
	SbemObjectSet<SbemHvacSystem>			hvacs;			
	SbemObjectSet<SbemRecUser>				recUsers;
	SbemObjectSet<SbemImprovementMeasure>	improvementMeasures;

protected:
	bool					hasSes;
	bool					hasPvs;
	bool					hasCchpGenerator;
	bool					hasWindGenerator;
	std::vector<SbemError>	errors;
};