#include "sbem_property.h"
/*=== Constructors ===*/
SbemProperty::SbemProperty() {}
SbemProperty::SbemProperty(const std::string& key) : name(key) {}
/*=== Getters ===*/
std::string SbemProperty::getName() { return name; }
