#include "sbem_numeric_property.h"
/*=== Constructors ===*/
SbemNumericProperty::SbemNumericProperty(){}
SbemNumericProperty::SbemNumericProperty(const std::string& key, float floatValue) : SbemProperty(name), value(floatValue) {};
/*=== Getters ===*/
float SbemNumericProperty::getValue() { return value; }
/*=== Setters ===*/
void SbemNumericProperty::setValue(float newValue) { value = newValue; }
/*=== The rest ===*/
std::string SbemNumericProperty::toString() {
 std::stringstream ss;
 ss << std::fixed << std::setprecision(6) << value; // Set precision to 6 decimal places

 std::string floatString = ss.str();

 // Trim trailing zeros after the decimal point if they exist
 size_t found = floatString.find_last_not_of('0');
 if (found != std::string::npos && floatString[found] == '.')
  found--; // Remove the decimal point if it's the last character
 floatString = floatString.substr(0, found + 1);

 return floatString;
}