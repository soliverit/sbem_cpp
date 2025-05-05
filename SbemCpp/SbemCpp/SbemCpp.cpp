// SbemKeeper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*===
 Includes
===*/
// Native
#include <iostream>
#include <fstream>
#include <filesystem>
// Project
#include "sbem_model.h"
#include "sbem_building_data.h"
const std::string ROOT_DIR = "c:/workspaces/sbem_keeper/";
const std::string SBEM_ROOT = "c:/ncm/6.1.e/ ";
const std::string SBEM_MODEL = "c:/workspaces/sbem_keeper/Project/model.inp";
const std::string TEST_MODELS = "c:/workspaces/__shared_data__/epc/";
const std::string TEST_OUT = "c:/workspaces/__sandbox__/sbem_ml_copy/";
int main()
{
	std::cout << "- Entered -";
	std::string f = "c:\\workspaces\\";
	bool b = std::filesystem::exists(f);
	std::cout << b;

	time_t seconds;
	seconds = time(NULL);
	int i = 0;
	for (const auto& entry : std::filesystem::directory_iterator(TEST_MODELS)) {
		std::ifstream inFile(entry.path().string() + "/model.inp");
		if (inFile.good()) {
			std::cout << "\n" << entry.path().string();
			std::stringstream strStream;
			strStream << inFile.rdbuf(); //read the file
			SbemModel	model = SbemModel::parseInpContent(strStream.str());
			if (model.hasErrors()) {
				std::vector<SbemError> errors = model.getErrors();
				for (int i = 0; i < errors.size(); i++) {
					std::cout << "\n" << errors[i].message;
				}
			}
			/*
				Play with features
			*/
			float areas[4] = {model.area(), model.wallArea(), model.windowArea(), model.wallSurfaceArea()};
			std::cout << "\n";
			std::cout << areas;
			i++;
		}
	}
	std::cout << "\n" << (time(NULL) - seconds);
	return 0;
	std::string path = SBEM_MODEL;
	SbemModel	model = SbemModel::parseInpFile(path);

	if (model.hasErrors()) {
		std::cout << "--- Errors found ---";
		std::vector<SbemError> errors = model.getErrors();
		for (int i = 0; i < errors.size(); i++)
			std::cout << errors[i].toString() << "\n";
	}
	else {

	}
	model.dropRecUsers();
	std::cout << "\n" << model.toString();

	std::ofstream out(SBEM_MODEL);
	out << model.toString();
	out.close();

}
