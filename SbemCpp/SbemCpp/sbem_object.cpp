/*===
	Includes
===*/
// Native
#include <iostream>	// TODO: Remove me after testing
#include "regex"
// Project
#include "sbem_object.h"

/*=== Constructors ===*/
SbemObject::SbemObject(){}
SbemObject::SbemObject(std::string objectName) : name(objectName) {}
/*
	Constructor with property strings.

	Takes an SBEM .inp object name and array of property strings from the .inp definition
	like below

	MULTIPLIER = 1
	TYPE = Underground
	TYPE-ENV = Floor or Ceiling
	PITCH = 0
	AREA = 2.88
	ORIENTATION = Horizontal
	CONSTRUCTION = "GF"

	The method splits string into key value pairs and stores them as SbemStringProperty
	or SbemNumericProperty determined by if they look like a number. Hasn't failed us
	yet.
*/
SbemObject::SbemObject(std::string objectName, std::vector<std::string> propertyStrings) : name(objectName) {
	// Number matching pattern
	static const std::regex numberPattern(R"(^-?\d+(\.\d+)?$)");
	// With every .inp file property line string. E.g "SFP-CHECK = YES"
	for (size_t propertyStringID = 0; propertyStringID < propertyStrings.size(); propertyStringID++) {
		// Keep it clean...
		std::string property = propertyStrings[propertyStringID];
		// Must not be zero-length
		if (property.length() == 0) {
			continue;
		}
		// Trim whitespace
		size_t start			= property.find_first_not_of(" \t\r\n");
		size_t end				= property.find_last_not_of(" \t\r\n");
		property				= property.substr(start, end - start + 1);
		// Get property
		size_t equals			= property.find_first_of('=');
		std::string key			= property.substr(start, equals - start + 1);
		size_t keyEnd			= key.find_last_not_of(" \t\r\n");
		key						= key.substr(0, keyEnd - 1);
		// Get value
		std::string value		= property.substr(equals + 1, end - equals);
		size_t valueStart		= value.find_first_not_of(" \t\r\n");
		size_t valueEnd			= value.find_last_not_of(" \t\r\n");
		value					= value.substr(valueStart, valueEnd - valueStart + 1);	
		/* Store property in appropriate variable type */
		// For numeric properties, int, float or double
		if(std::regex_match(value, numberPattern))
			addNumericProperty(key, std::stof(value));
		// For string /anything else
		else
			addStringProperty(key, value);
	}
}
/*
	Is the passed line a SBEM .inp object header line

	Takes strings and looks checks to see if their format is like: "HVAC name" = HVAC-SYSTEM

	returns tuple of name and object type. Both blank if undefined
*/
std::tuple<bool, std::string, std::string> SbemObject::isHeaderLine(std::string line) {
	// Line must start with a name (names are in quotation marks).
	size_t start		= line.find_first_not_of(" \t\r\n");
	if (line[start] != '"')
		return std::make_tuple(false, "", "");
	// Must have two quationa marks.
	size_t end			= line.find_last_not_of(" \t\r\n");
	if (start == end)
		return std::make_tuple(false, "", "");
	// Must have Equals that's after the closing quotation mark.
	size_t closeQuote	= line.find_last_of('"');
	size_t equals		= line.find_last_of('=');
	if (equals == std::string::npos || equals < closeQuote)
		return std::make_tuple(false, "", "");
	// Equals can't be the last character of the line
	if (equals == end)
		return std::make_tuple(false, "", "");
	// The SBEM object type must be all upper case
	size_t typeStart = 0;
	for (size_t charID = equals + 1; charID < line.length(); charID++)
		if (line[charID] != ' ' && line[charID] != '\t') {
			typeStart = charID;
			break;
		}
	std::string typeName = line.substr(typeStart, end - typeStart + 1);
	for (size_t charID = 0; charID < typeName.length(); charID++)
		typeName[charID] = std::toupper(typeName[charID]);
	if(line.substr(typeStart, end - typeStart + 1) != typeName)
		return std::make_tuple(false, "", "");
	return std::make_tuple(true, line.substr(start + 1, closeQuote - start - 1), typeName);
}
bool SbemObject::isCloseLine(std::string line) {
	// Line needs to have something in it.
	if (line.length() == 0)
		return false;
	size_t start	= line.find_first_not_of(" \t\r\n");
	size_t end		= line.find_last_not_of(" \t\r\n");
	// Line needs to have dots
	if (start == std::string::npos)
		return false;
	// Dots should be adjacent
	if (end - start != 1)
		return false;
	// Line should only have two characters
	if (line[start] != '.' || line[end] != '.')
		return false;
	
	return true;
}
/*=== Static members ===*/
const std::string SbemObject::OBJECT_END = " ..";
/*=== Instance methods ===*/
// Does the object have a specific numeric property? E.g SFP
bool SbemObject::hasNumericProperty(const std::string& key) { return numericProperties.find(key) != numericProperties.end();}
// Does the object have a specific string property. E.g SFP-CHECK
bool SbemObject::hasStringProperty(const std::string& key) { return stringProperties.find(key) != stringProperties.end(); }
/*=== Getters ===*/
// Get a numeric property (assumes user did their own checks to make sure the property exists
SbemNumericProperty* SbemObject::getNumericProperty(const std::string& key) {
	return &numericProperties[key];
}
// Get a string property (assumes user did their own checks to make sure the property exists
SbemStringProperty* SbemObject::getStringProperty(const std::string& key) {
	return &stringProperties[key];
}

/*=== Setters ===*/
// Set the value of an existing numeric property. EXCLUSIVELY existing properties
bool SbemObject::setNumericProperty(const std::string& key, float value) {
	// If the property already exists
	if (hasNumericProperty(key)) {
		// Update the value and confirm
		numericProperties[key].setValue(value);
		return true;
	}
	// The property doesn't exist, confirm
	return false;
}
// Set the value of an existing string property. EXCLUSIVELY existing properties
bool SbemObject::setStringProperty(const std::string& key, std::string value) {
	// If the property already exists
	if (hasStringProperty(key)) {
		// Update the value and confirm
		stringProperties[key].setValue(value);
		return true;
	}
	// The property doesn't exist, confirm
	return false;
}
// Set the value of a numeric property. Regardless of whether it exists
void SbemObject::addNumericProperty(const std::string& key, float value) {
	// If the property doesn't exist yet
	if (!hasNumericProperty(key)) {
		// Track the new property key
		numericPropertyKeys.push_back(key);
		// Add the new property to the object and return
		numericProperties[key] = SbemNumericProperty(key, value);
		return;
	}
	// Update the existing property 
	numericProperties[key].setValue(value);
}
// Set the value of a string property. Regardless of whether it exists
void SbemObject::addStringProperty(const std::string& key, std::string value) {
	// If the property doesn't exist yet
	if (!hasStringProperty(key)) {
		// Track the new property key
		stringPropertyKeys.push_back(key);
		// Add the new property to the object and return
		stringProperties[key] = SbemStringProperty(key, value);
		return;
	}
	// Update the existing property 
	stringProperties[key].setValue(value);
}
/*=== Droppers ===*/
// Remove a numeric property if it exists
void SbemObject::removeNumericProperty(const std::string& key, float value) { numericProperties.erase(key);}
// Remove string property if it exists
void SbemObject::removeStringProperty(const std::string& key, std::string value) { stringProperties.erase(key);}
/*=== The rest ===*/
// Create the .inp object properties string. E.g AREA = 10\nVOLUME = 50
std::string SbemObject::propertiesString() {
	std::string properties;
	// Track if we append a string or number at the start so \n works in the next bit
	int stringStartID	= 0;
	int numericStartID	= 0;
	// If there's at least one string property, use the first
	if (stringProperties.size() > 0){
		stringStartID	= 1;
		properties		= stringProperties[stringPropertyKeys[0]].toString();
	}
	// Otherwise, if there's at least one numeric property, use the first
	else if (numericProperties.size() > 0){
		numericStartID	= 1;
		properties		= numericProperties[stringPropertyKeys[0]].toString();
	}
	else
		return "";
	// Add any remaining string properties
	for (size_t propertyID = stringStartID; propertyID < stringPropertyKeys.size(); propertyID++)
		properties += "\n" + stringProperties[stringPropertyKeys[propertyID]].toString();
	// Add any remaining numeri properties
	for (size_t propertyID = numericStartID; propertyID < numericPropertyKeys.size(); propertyID++)
		properties += "\n" + numericProperties[numericPropertyKeys[propertyID]].toString();
	// Return the .inp formatted properties string
	return properties;
}
/*
	Get parseing errors
*/
std::vector<SbemPropertyError> SbemObject::getErrors() {
	std::vector<SbemPropertyError> errorsClone(errors);
	return errorsClone;
}