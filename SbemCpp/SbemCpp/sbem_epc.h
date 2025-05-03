#pragma once
/*===
	Includes
===*/
// Native

// Project
#include "sbem_object.h"
/*
	SBEM EPC (_epc.inp, not .inp)

	Object in _epc.inp that contains the key results. BER, SER, KWH-PRIM/NOT, etc

		TYPE      = England
		SER       = 5.54267
		TYR       = 11.7281
		TER       = 0
		EPC-LANGUAGE    = ENGLISH
		BER       = 12.6062
		NOS-LEVEL    = Level 3
		TRANSACTION-TYPE   = Voluntary (No legal requirement for an EPC)
		MAIN-FUEL-TYPE  = Grid Supplied Electricity
		BUILDING-ENVIRONMENT  = Heating and Natural Ventilation

	NOTE:	The above is for England, Scotland (excluding SER), and Wales, standard
			SBEM simluation. Section 63 (Scotland) and NEAP (Republic of Ireland) omit
			some properties and add others. NEAP, for example, has focuses on primary
			energy.
*/
class SbemEpc : public SbemObject {
public:
	/*=== Constructors ===*/
	/* Default */
	SbemEpc();
	/* Create blank EPC */
	SbemEpc(std::string objectName);
	/* Create complete EPC*/
	SbemEpc(std::string objectName, std::vector<std::string> propertyStrings);

	/*=== Static methods===*/
	/* SBEM object name EPC */
	static const std::string OBJECT_NAME;
	/*=== Instance methods ===*/
	/* Convert to an .inp object. See example */
	std::string toString();
};