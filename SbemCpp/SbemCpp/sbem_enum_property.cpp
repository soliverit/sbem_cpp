/*===
	Incnludes
===*/
// Native

// Project
#include "sbem_enum_property.h"
/*=== Constructors ===*/
SbemEnumProperty::SbemEnumProperty(){}
SbemEnumProperty::SbemEnumProperty(const std::string& key, std::string stringValue) : SbemProperty(key), value(stringValue) {}
/*=== Getters ===*/

/*=== Setters ===*/
void SbemEnumProperty::setValue(std::string enumValue) { value = enumValue;}
/*=== The rest ===*/