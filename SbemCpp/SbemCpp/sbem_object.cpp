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
SbemObject::SbemObject(std::string objectName, std::vector<std::string> propertyStrings) : name(objectName) {
	static const std::regex numberPattern(R"(^-?\d+(\.\d+)?$)");
	for (size_t propertyStringID = 0; propertyStringID < propertyStrings.size(); propertyStringID++) {
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
		
		if(std::regex_match(value, numberPattern))
			addNumericProperty(key, std::stof(value));
		else
			addStringProperty(key, value);
	}
}

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
// Exist...ors...

bool SbemObject::hasNumericProperty(const std::string& key) { return numericProperties.find(key) != numericProperties.end();}
bool SbemObject::hasStringProperty(const std::string& key) { return stringProperties.find(key) != stringProperties.end(); }
/*=== Getters ===*/
SbemNumericProperty* SbemObject::getNumericProperty(const std::string& key) {
	if (hasNumericProperty(key)) {
		return &numericProperties[key];
	}
	return nullptr;
}
SbemStringProperty* SbemObject::getStringProperty(const std::string& key) {
	if (hasStringProperty(key)) {
		return &stringProperties[key];
	}
	return nullptr;
}

/*=== Setters ===*/

bool SbemObject::setNumericProperty(const std::string& key, float value) {
	if (hasNumericProperty(key)) {
		numericProperties[key].setValue(value);
		return true;
	}
	return false;
}

bool SbemObject::setStringProperty(const std::string& key, std::string value) {
	if (hasStringProperty(key)) {
		stringProperties[key].setValue(value);
		return true;
	}
	return false;
}

void SbemObject::addNumericProperty(const std::string& key, float value) {
	if (!hasNumericProperty(key)) {
		numericPropertyKeys.push_back(key);
		numericProperties[key] = SbemNumericProperty(key, value);
		return;
	}
	numericProperties[key].setValue(value);
}

void SbemObject::addStringProperty(const std::string& key, std::string value) {
	if (!hasStringProperty(key)) {
		stringPropertyKeys.push_back(key);
		stringProperties[key] = SbemStringProperty(key, value);
		return;
	}
	stringProperties[key].setValue(value);
}
void SbemObject::removeNumericProperty(const std::string& key, float value) { numericProperties.erase(key);}
void SbemObject::removeStringProperty(const std::string& key, std::string value) { stringProperties.erase(key);}
/*=== The rest ===*/
std::string SbemObject::propertiesString() {
	std::string properties;
	if (stringProperties.size() > 0)
		properties = stringProperties[stringPropertyKeys[0]].toString();
	else if (numericProperties.size() > 0)
		properties = numericProperties[stringPropertyKeys[0]].toString();
	else
		return "";

	for (size_t propertyID = 1; propertyID < stringPropertyKeys.size(); propertyID++)
		properties += "\n" + stringProperties[stringPropertyKeys[propertyID]].toString();
	return properties;
}

std::vector<SbemPropertyError> SbemObject::getErrors() {
	std::vector<SbemPropertyError> errorsClone(errors);
	return errorsClone;
}