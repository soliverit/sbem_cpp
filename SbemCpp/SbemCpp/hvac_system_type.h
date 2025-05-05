#pragma once
#include <iostream>
#include <unordered_map>
/*
    HVAC System Type

    A struct with SBEM Database HVAC-SYSTEM:TYPE property data. Records
    contain defaults and descriptions for HVAC systems. For example, can be used
    mixed-mode, has ventilation and cooling etc.

    TODO: Make this a SBEM version thing for v5 and v6 SBEM
*/
struct HvacSystemType {
    /* Static members */
    // Dictionary to lookup up structs based on .inp HVAC-SYSTEM:TYPE property
    static std::unordered_map<std::string, HvacSystemType> DICTIONARY;
    // String used to determine if the HVAC type has no heating or cooling
    static std::string NO_HEATING_OR_COOLING;
    // String used to determine if the HVAC type has no cooling
    static std::string NO_COOLING_TEXT;
    // String used to determine if the HVAC type has no mechanical ventilation
    static std::string NO_MECH_VENTILATION_TEXT;
    /* Instance methods */
    // Does the system  support cooling (not necessarily has it.
    bool hasCooling() const;
    // Does the system have heating
    bool hasHeating() const;
    // Does the system have mechanical ventilation
    bool hasMechanicalVentilation() const;
    /* Instance members */
    /*
        Struct Properties from the SBEM database table. 
    */
    float ID;
    float ORDER;
    std::string CODE;
    float CATEGORY;
    float CATEGORY1;
    float MIXED_MODE;
    float tCSSEER;
    float tHSSeff;
    float tAEnergy;
    float Variable_Speed_Pump;
    float tCSFPb;
    float tCSFPa;
    float tCSFPd;
    float tCDLb;
    float tCDLa;
    float tCDLd;
    float tCEFFd;
    float tCCtrl1;
    float tCCtrl2;
    float tCCtrld;
    float tHSFPb;
    float tHSFPa;
    float tHSFPd;
    float tHDLb;
    float tHDLa;
    float tHDLd;
    float tHEFFd;
    float tHCtrl1;
    float tHCtrl2;
    float tHCtrld;
    float tASFPb;
    float tASFPa;
    float tASFPd;
    float tADLb;
    float tADLa;
    float tADLd;
    float tACtrl1;
    float tACtrl2;
    float tACtrld;
    std::string DESCRIPTION;
    std::string HVAC_vent_text;
    std::string HVAC_cool_text;
    std::string HVAC_syst_adj;
    std::string ZONE_vent_text;
    std::string ZONE_vent_unflued_warning;
};
