#pragma once
/*===
	Incnludes
===*/
// Native
#include <vector>
#include <string>
#include <unordered_map>
// Project
#include "sbem_numeric_property.h"
#include "sbem_string_property.h"
#include "sbem_property_error.h"
/*
	SBEM object

	Base class for SBEM objects for all models including Actual, Reference, Notional, S63,
	BER (Ireland), and EPC.

	Object constist of a header with a name and type. Objects have zero or more properties. E.g

		"No heating or cooling" = HVAC-SYSTEM
			TYPE	= No Heating or Cooling
		 ..
	Objects are terminated by " ..". No idea why the space is necessary but it breaks when it's 
	note there.

	Objects have string, enum, int, and float values. String and enum are stored as SbemStringProperty,
	int and float as SbemNumericProperty.
*/
class SbemObject {
public:
	/*=== Constructors ===*/
	/* Default */
	SbemObject();
	/* Create named blank object with unknown SBEM type */
	SbemObject(std::string objectName);
	/* Create a named complete object with unknown SBEM type*/
	SbemObject(std::string objectName, std::vector<std::string> propertyStrings);
	// Static methods
	/* 
		Validate and parse header line
	
		Determine if the line is an SBEM object header line and return a confirmation (bool),
		and name and object.

		Tuple:
			bool:	Is a header line
			string:	Object name
			string:	Object type
	*/
	static std::tuple<bool, std::string, std::string> isHeaderLine(std::string line);
	/* Check to see if line is a close SBEM object line " .." */
	static bool isCloseLine(std::string line);
	/*=== Static members ===*/
	/* SBEM close object line */
	static const std::string OBJECT_END;
	/*=== Instance members ===*/
	/* The objects name: "Object name" = SOME-TYPE */
	std::string name; // Please don't fuck with me unless you know I won't be referenced by something else
	/*=== Instance methods ===*/
	/* Get a safe copy of the errors vector.*/
	std::vector<SbemPropertyError> getErrors();
	// Exist...ors...
	/* Check if object has a int/float property */
	bool hasNumericProperty(const std::string& key);
	/* Check if object has a enum/string property */
	bool hasStringProperty(const std::string& key);
	/*=== Getters ===*/
	/* Get an SbemNumericProperty if it exists. Otherwise nullptr */
	SbemNumericProperty* getNumericProperty(const std::string& key);
	/* Get an SbemStringProperty if it exists. Otherwise nullptr */
	SbemStringProperty* getStringProperty(const std::string& key);
	/*=== Setters ===*/
	/* Set an SbemNumericProperty IF it exists */
	bool setNumericProperty(const std::string& key, float value);
	/* Set an SbemStringProperty IF it exists */
	bool setStringProperty(const std::string& key, std::string value);
	/* Add or set an SbemNumericProperty */
	void addNumericProperty(const std::string& key, float value);
	/* Add or set an SbemStringProperty */
	void addStringProperty(const std::string& key, std::string value);
	/* Remove an SbemNumericProperty */
	void removeNumericProperty(const std::string& key, float value);
	/* Remove an SbemStringProperty */
	void removeStringProperty(const std::string& key, std::string value);
	/*=== The rest ===*/
	/*
		Convert properties vector map to an SBEM object properties string. E.g

			TYPE = Flued forced-convection air heaters
			HEAT-SOURCE = Air heater
	*/
	std::string propertiesString();
protected:
	/*=== Instance members ===*/
	/* List of current numeric property names */
	std::vector<std::string> numericPropertyKeys;
	/* List of current string property names */
	std::vector<std::string> stringPropertyKeys;
	/* All SbemNumericProperty */
	std::unordered_map<std::string, SbemNumericProperty> numericProperties;		// floats
	/* All SbemStringProperty */
	std::unordered_map<std::string, SbemStringProperty> stringProperties;	// strings
	/* List of errors. See SbemPropertyError::ErrorCodes */
	std::vector<SbemPropertyError> errors;
};


