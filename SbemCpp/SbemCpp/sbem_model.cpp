/*===
	Includes
===*/
// Native 
#include <fstream>
#include <iostream>
#include <sstream> 
#include <map>
#include <string_view>
#include <sstream>
// Project
#include "sbem_model.h"
/*=== Constructors ===*/
SbemModel::SbemModel(){}
/*=== Static methods ===*/
SbemModel SbemModel::createBasicModel() { return parseInpContent(MIN_INP); }
/*=== Static members ===*/
const std::string SbemModel::MIN_INP = R"(\"SBEM-PROJECT\" = GENERAL
B-TYPE = B8 Storage or Distribution
WEATHER = MAN
B-COUNTRY = England and Wales
P-NAME = \"8 BUSINESS PARK\"
B-ADDRESS-0 = \"Unit (lol)\"
B-ADDRESS-1 = \"Business Centre\"
B-ADDRESS-2 = \"Man Road\"
B-CITY = \"Portford\"
B-POSTCODE = \"PF1 3AS\"
C-NAME = \"Rab C Nisbit\"
C-TELEPHONE = \"01324 555 555\"
C-ADDRESS = \"124 Business Road\"
C-EMAIL = \"info@business.ac.uk\"
C-CITY = \"Business city\"
C-POSTCODE = \"BN1 1NB\"
C-REG-NUMBER = \"EES-007\"
C-ACCRED-SCHEME = Elmhurst Energy Systems
C-EMP-TRAD-NAME = \"Business Energy\"
C-EMP-TRAD-ADDRESS = \"Business Energy trade address\"
C-REL-PART-DISC = Not related to the owner
TRANSACTION-TYPE = Voluntary (No legal requirement for an EPC)
C-QUALIFICATIONS = NOS4
SOFT-COMP-NAME = G-ISBEM Ltd
INTERFACE-VAL = iSBEM
INTERFACE = G-ISBEM
INTERFACE-VERSION = v25.3
PATH-FILE-INTERFACE = \"./BUSINESS PARK.nct\"
ACT-NOT = ACT
BUILDING-AREA = 175.85
FOUNDATION-AREA = 169.38
ELEC-POWER-FACTOR = <0.9
NOS-LEVEL = Level 3
C-INSURER = \"Hillson LTD\"
C-INS-POL-NUMBER = \"PLL3334234-7\"
C-INS-EFF-DATE = \"2022-07-31\"
C-INS-EXP-DATE = \"2023-07-30\"
C-INS-PI-LIMIT = \"5000000\"
B-INSP-DATE = { 2023, 06, 15 }
UPRN = \"UPRN-12345676\"
LIGHT-METERING = 1
BUILD-ORIENTATION = 0
MAX-STOREY = 2
 ..

\"SBEM\" = COMPLIANCE
EPC-TYPE = EPC England
ENG-HERITAGE = NO
BR-STAGE = As built
AIR-CON-INSTALLED = No
 ..)";
/*
	Methods
*/
// Static methods
SbemModel SbemModel::parseInpContent(const std::string& content) {
	SbemModel model = SbemModel();
	/*
		Process the content
	*/
	// Prepare content
	std::stringstream inp(content);
	std::string line;
	/*
		Parsing the model:

		SBEM objects have three compoents: the name/type header, properties, and the close object. For example:

			"Zones without heating or cooling" = HVAC-SYSTEM
				TYPE	= No Heating or Cooling
			..	
		To parse it the folllowing steps are taken:
	*/
	// Tracking objects
	std::shared_ptr<SbemDoor>		currentDoor;
	std::shared_ptr<SbemHvacSystem> currentHvac;
	std::shared_ptr<SbemWall>		currentWall;
	std::shared_ptr<SbemWindow>		currentWindow;
	std::shared_ptr<SbemZone>		currentZone;
	/* We don't have ducktyping like Ruby/Py so we'll cache object definition parts first*/
	std::string						currentName;
	std::string						currentType;
	std::vector<std::string>		currentProperties;
	// Flags
	bool inObject				= false;
	size_t objectStartPosition	= 0;
	size_t objectEndPosition	= 0;
	while (std::getline(inp, line)) {
		/*
			Strip that pesky whitespace. Skip blank lines and comments.
		*/
		size_t start	= line.find_first_not_of(" \t\r\n");
		size_t end		= line.find_last_not_of(" \t\r\n");
		// Skip blank lines
		if (start == std::string::npos || end == std::string::npos) {
			continue;
		}
		line			= line.substr(start, end - start + 1);
		
		// Skip comments
		if (line[0] == '$') {
			continue;
		}
		/*
			Do object stuff
		*/
		if (!inObject) {
			std::tuple<bool, std::string, std::string> headerLine = SbemObject::isHeaderLine(line);
			if (std::get<0>(headerLine)){
				inObject	= true;
				currentName = std::get<1>(headerLine);
				currentType = std::get<2>(headerLine);
				currentProperties.clear();
				
			}
		}else if (inObject) {
			if (SbemObject::isCloseLine(line)) {
				inObject = false;
				std::string_view objectType = currentType;
				if (objectType == SbemCompliance::OBJECT_NAME) {
					model.compliance = SbemCompliance(currentName, currentProperties);
				}
				else if (objectType == SbemConstruction::OBJECT_NAME) {
					model.constructions.push(std::make_shared<SbemConstruction>(currentName, currentProperties));
				}
				else if (objectType == SbemDhwGenerator::OBJECT_NAME) {
					model.dhws.push(std::make_shared<SbemDhwGenerator>(currentName, currentProperties));
				}
				else if (objectType == SbemDoor::OBJECT_NAME) {
					currentWall->doors.push(std::make_shared <SbemDoor>(currentName, currentProperties));
				}
				else if (objectType == SbemDoorTmBridge::OBJECT_NAME) {
					currentDoor->setThermalBridge(SbemDoorTmBridge(currentName, currentProperties));
				}
				else if (objectType == SbemGeneral::OBJECT_NAME) {
					model.general	= SbemGeneral(currentName, currentProperties);
				}
				else if (objectType == SbemGlass::OBJECT_NAME) {
					model.glasses.push(std::make_shared<SbemGlass>(currentName, currentProperties));
				}
				else if (objectType == SbemHvacSystem::OBJECT_NAME) {
					currentHvac		= std::make_shared<SbemHvacSystem>(currentName, currentProperties);
					model.hvacs.push(currentHvac);// std::make_shared<SbemHvacSystem>(currentHvac));
				}
				else if (objectType == SbemImprovementMeasure::OBJECT_NAME) {
					model.improvementMeasures.push(std::make_shared<SbemImprovementMeasure>(currentName, currentProperties));
				}
				else if (objectType == SbemPvs::OBJECT_NAME) {
					model.hasPvs			= true;
					model.pvs		=  SbemPvs(currentName, currentProperties);
				}
				else if (objectType == SbemRecProject::OBJECT_NAME) {
					model.recProject = SbemRecProject(currentName, currentProperties);
				}
				else if (objectType == SbemRecUser::OBJECT_NAME) {
					model.recUsers.push(std::make_shared<SbemRecUser>(currentName, currentProperties));
				}
				else if (objectType == SbemSes::OBJECT_NAME) {
					model.hasSes	= true;
					model.ses		= SbemSes(currentName, currentProperties);
				}
				else if (objectType == SbemShower::OBJECT_NAME) {
					model.showers.push(std::make_shared<SbemShower>(currentName, currentProperties));
				}
				else if (objectType == SbemWall::OBJECT_NAME) {
					currentWall		= std::make_shared<SbemWall>(currentName, currentProperties);
					currentWall->setConstruction(model.constructions.dictionary[currentWall->getStringProperty("CONSTRUCTION")->getQuotelessValue()]);
					currentZone->walls.push(currentWall);
				}
				else if (objectType == SbemWindGenerator::OBJECT_NAME) {
					model.windGenerator = SbemWindGenerator(currentName, currentProperties);
				}
				else if (objectType == SbemWindow::OBJECT_NAME) {
					currentWindow = std::make_shared<SbemWindow>(currentName, currentProperties);
					currentWindow->setGlass(model.glasses.dictionary[currentWindow->getStringProperty("GLASS")->getQuotelessValue()]);
					currentWall->windows.push(currentWindow);
				}
				else if (objectType == SbemWindowTmBridge::OBJECT_NAME) {
					currentWindow->setThermalBridge(SbemWindowTmBridge(currentName, currentProperties));
				}
				else if (objectType == SbemZone::OBJECT_NAME) {
					currentZone = std::make_shared<SbemZone>(currentName, currentProperties);
					currentHvac->zones.push(currentZone);
				}
			}
			else {
				currentProperties.push_back(line);
			}
		}
	}
	/*
		Send it home... and do whatever finishing moves.
	*/
	std::cout << "\nDFJDSLFJ:DSJFL:KSDJFLKJSDKLJF\nKLJDFJSDFJLSDJFLKJSDL:KFJ\nJDFKJDSLJFLSDJFKLSDJF";
	return model;
}
SbemModel SbemModel::parseInpFile(const std::string& path) {
	/*
		Open inp file and check that it exists. Return corrupt model if it doesn't
	*/
	std::ifstream inFile;
	inFile.open(path); 
	if (!inFile.good()) {
		SbemModel model = SbemModel();
		model.addError(SbemError::CONTENT_FILE_NOT_EXISTS, "Inp file '" + path + "' doesn't exist.");
		return model;
	}
	/*
		Parse the content and call the model build method to finish the job.
	*/
	std::stringstream strStream;
	strStream << inFile.rdbuf(); //read the file
	std::string content	= strStream.str(); //str holds the content of the file
	return parseInpContent(content);
}
std::string SbemModel::toString() {
	/*std::cout << "\nSbemModel::toString() exits for testing at opening line\n";
	return "";*/
	std::stringstream content;
	content << general.toString();
	content << "\n" << compliance.toString();
	for (size_t constructionID = 0; constructionID < constructions.size(); constructionID++)
		content << "\n" << constructions.objects[constructionID]->toString();
	for (size_t glassID = 0; glassID < glasses.objects.size(); glassID++)
		content << "\n" << glasses.objects[glassID]->toString();
	if(hasSes)
		content << "\n" << ses.toString();
	if(hasPvs)
		content << "\n" << pvs.toString();
	if(hasWindGenerator)
		content << "\n" << windGenerator.toString();
	for (size_t showerID = 0; showerID < showers.size(); showerID++)
		content << "\n" << showers.objects[showerID]->toString();
	for (size_t dhwID = 0; dhwID < dhws.size(); dhwID++)
		content << "\n" << dhws.objects[dhwID]->toString();
	for (size_t hvacID = 0; hvacID < hvacs.size(); hvacID++)
		content << "\n" << hvacs.objects[hvacID]->toString();
	for (size_t recUserID = 0; recUserID < recUsers.size(); recUserID++)
		content << "\n" << recUsers.objects[recUserID]->toString();
	for (size_t recUserID = 0; recUserID < recUsers.size(); recUserID++)
		content << "\n" << recUsers.objects[recUserID]->toString();
	for (size_t improvementID = 0; improvementID < improvementMeasures.size(); improvementID++)
		content << "\n" << improvementMeasures.objects[improvementID]->toString();
	return content.str();
}
/*=== Instance methods ===*/
void SbemModel::addError(int errorCode, std::string errorMessage) {
	errors.push_back(SbemError(errorCode, errorMessage));
}
bool SbemModel::hasErrors() { return errors.size() > 0; }

std::vector<SbemError> SbemModel::getErrors(){
	std::vector<SbemError> errorsClone(errors);
	return errorsClone;
}
void SbemModel::dropRecUsers(){recUsers.clear(); }
/*
	Instance methods
*/
/*=== Building properties ===*/
float SbemModel::electricEquivalentEmissionFactor() {
	return 0.0;
}
float SbemModel::electricEquivalenEmissionFactorCool() {
	return 0.0;
}
// Areas
float SbemModel::area() {
	float area	= 0;
	for(size_t hvacID = 0; hvacID < hvacs.size(); hvacID++)
		area	+= hvacs.objects[hvacID]->area();
	return area;
}
float SbemModel::coolArea() {
	float area = 0;
	for (size_t hvacID = 0; hvacID < hvacs.size(); hvacID++)
		if(hvacs.objects[hvacID]->hasCooling())
			area += hvacs.objects[hvacID]->area();
	return area;
}
float SbemModel::heatedArea() {
	return 0.0;
}
float SbemModel::mechVentArea() {
	return 0;
}
float SbemModel::mechVentAreaCool() {
	return 0.0;
}
float SbemModel::wallArea() {
	return 0.0;
}
float SbemModel::wallAreaCool() {
	return 0.0;
}
float SbemModel::windowArea() {
	return 0.0;
}
float SbemModel::windowAreaCool() {
	return 0.0;
}
// Envelopes
float SbemModel::averageWallUValue() {
	return 0.0;
}
float SbemModel::averageWallUValueCool() {
	return 0.0;
}
float SbemModel::averageWindowUValue() {
	return 0.0;
}
float SbemModel::averageWindowUValueCool() {
	return 0.0;
}
//- Equivalents
float SbemModel::electricEquivalentAverageWallUValue() {
	return 0.0;
}
float SbemModel::electricEquivalentAverageWindoeUValue() {
	return 0.0;
}
// Heating and cooling
float SbemModel::averageSSEFF(){return 0;}
float SbemModel::averageCoolSSEER() { return 0; };
float SbemModel::averageCoolGenSEER() { return 0; };
//- Equivalents
float SbemModel::electricEquivalentSSEFF() { return 0; };

// Ventilation 
float SbemModel::freshAirRate() { return 0; };
// Auxiliary

// Lighting
float SbemModel::lightingPowerDensity() { return 0; };

// Misc
void SbemModel::mergeObjectDefaults(){};