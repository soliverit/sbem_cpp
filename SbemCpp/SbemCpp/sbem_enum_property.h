#pragma once
/*===
	Incnludes
===*/
// Native
#include <string>
// Project
#include "sbem_property.h"
/*
	SBEM enumerated property 

	DEPRECATED: An object for storing string-like properties that have predefined
	acceptable values. For example, B-TYPE:

		A1/A2 Retail and Financial/Professional services
		A3/A4/A5 Restaurant and Cafes/Drinking Establishments and Hot Food takeaways
		B1 Offices and Workshop businesses
		B2 to B7 General Industrial and Special Industrial Groups
		B8 Storage or Distribution
		C1 Hotels
		C2 Residential Institutions - Hospitals and Care Homes
		C2 Residential Institutions - Residential schools
		C2 Residential Institutions - Universities and colleges
		C2A Secure Residential Institutions
		Residential spaces
		D1 Non-residential Institutions - Community/Day Centre
		D1 Non-residential Institutions - Libraries Museums and Galleries
		D1 Non-residential Institutions - Education
		D1 Non-residential Institutions - Primary Health Care Building
		D1 Non-residential Institutions - Crown and County Courts
		D2 General Assembly and Leisure plus Night Clubs and Theatres
		Others - Passenger terminals
		Others - Emergency services
		Others - Miscellaneous 24hr activities
		Others - Car Parks 24 hrs
		Others - Stand alone utility block

	A later decision led to the complete separation of SbemObject and SbemValidatorObject,
	and having validator verify the model post build.
*/
class SbemEnumProperty : public SbemProperty{
public:
	/* === Constructors === */
	/* Default constructor */
	SbemEnumProperty();
	/* Actually populating the property */
	SbemEnumProperty(const std::string& key, std::string value);
	//instance

	/*=== Getters ===*/

	/*=== Setters ===*/
	void setValue(std::string newValue);
	/*=== The rest ===*/
	
protected:
	std::string value;
};


