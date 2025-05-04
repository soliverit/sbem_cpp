#pragma once
#include <iostream>
#include <unordered_map>
struct HvacSystemType {
    /* Static members */
    static std::unordered_map<std::string, HvacSystemType> DICTIONARY;
    static std::string NO_HEATING_OR_COOLING;
    static std::string NO_COOLING_TEXT;
    static std::string NO_MECH_VENTILATION_TEXT;
    /* Instance methods */
    bool hasCooling() const;
    bool hasHeating() const;
    bool hasMechanicalVentilation() const;
    /* Instance members */
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
