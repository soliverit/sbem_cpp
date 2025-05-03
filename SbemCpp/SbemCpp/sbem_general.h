#pragma once
/*===
	Includes
===*/
// Native

// Project
#include "sbem_object.h"
/*
	SBEM General

	Top-level information about the building and accredited assesor

			P-NAME    = "Spaceballs: The property"
			UPRN      = "11111111"
			B-INSP-DATE     = { 1987, 06, 1 }
			B-TYPE    = B8 Storage or Distribution
			B-ADDRESS-0     = "Unit 1"
			B-ADDRESS-1     = ""
			B-ADDRESS-2     = "Cliffs Road"
			B-ADDRESS-4     = ""
			B-ADDRESS-5     = "CR11 4FF"
			BUILDING-AREA   = 175.9
			C-NAME    = "Dark Helmet"
			C-TELEPHONE     = "1-800 Druidia"
			C-EMAIL      = "d.helmet@spaceballs.net"
			C-ADDRESS    = "12 Space Road"
			C-CITY    = "Space"
			C-POSTCODE   = "SP1 1BA"
			C-ACCRED-SCHEME    = Elmhurst Energy Systems
			C-REG-NUMBER    = "EES/123445656"
			C-EMP-TRAD-NAME    = "Spaceballs"
			C-EMP-TRAD-ADDRESS = "12 Space Road"
			C-REL-PART-DISC    = Not related to the owner
			C-QUALIFICATIONS   = NOS4
			C-INSURER    = "Fictional insurance provider"
			C-INS-POL-NUMBER   = "Spaceballs doesn't have insurance"
			C-INS-EFF-DATE  = "1987-07-1"
			C-INS-EXP-DATE  = "1987-07-1"
			C-INS-PI-LIMIT  = "500000000000"
			SOFT-COMP-NAME  = G-ISBEM Ltd
			CENGINE      = "SBEM"
			CENGINE-VAL     = SBEM
			CENGINE-VERSION    = "v6.1.e.0"
			INTERFACE    = G-ISBEM
			INTERFACE-VERSION  = v25.3
			PATH-FILE-INTERFACE   = "c:\ncm\5.6.b\projects|project.nct"
			PATH-FILE-ENGINE   = "projects\zmodel.inp"
			PAUSE-KNOWN-ERRORS = YES
			PRODUCE-MESSAGES   = YES
			COMPRESS-XML-MESSAGES = YES
*/
class SbemGeneral : public SbemObject {
public:
	/*=== Constructors ===*/
	/* Default */
	SbemGeneral();
	/* Create blank GENERAL */
	SbemGeneral(std::string objectName);
	/* Create complete GENERAL */
	SbemGeneral(std::string objectName, std::vector<std::string> propertyStrings);
	/*=== Static methods===*/
	/* SBEM object name GENERAL */
	static const std::string OBJECT_NAME;
	/*=== Instance methods ===*/
	/* Convert to an .inp object. See example */
	std::string toString();
};