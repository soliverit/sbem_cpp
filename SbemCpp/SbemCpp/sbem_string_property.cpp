#include "sbem_string_property.h"
/*=== Constructors ===*/
SbemStringProperty::SbemStringProperty(){}
SbemStringProperty::SbemStringProperty(const std::string& key, std::string stringValue) : SbemProperty(key), value(stringValue) {}

/*=== Getters ===*/
std::string SbemStringProperty::getValue() { return value; }
std::string SbemStringProperty::getQuotelessValue() {
    std::string s   = value;
    if (!s.empty() && s.front() == '=') {
        s.erase(0, 1);
    }
    if (!s.empty() && s.back() == '=') {
        s.pop_back();
    }
    return s;
}
/*=== Setters ===*/
void SbemStringProperty::setValue(std::string newValue) { value = newValue; }
/*=== The rest ===*/
std::string SbemStringProperty::toString() {
	return name + " = " + value;
}