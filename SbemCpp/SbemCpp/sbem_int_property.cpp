#include "sbem_int_property.h"
/*=== Constructors ===*/
SbemIntProperty::SbemIntProperty(){}
SbemIntProperty::SbemIntProperty(const std::string& key, unsigned int intValue) : SbemProperty(name), value(intValue) {}
/*=== Getters ===*/
unsigned int SbemIntProperty::getValue() { return value; }
/*=== Setters ===*/
void SbemIntProperty::setValue(unsigned int newValue) { value = newValue; }
/*=== The rest ===*/