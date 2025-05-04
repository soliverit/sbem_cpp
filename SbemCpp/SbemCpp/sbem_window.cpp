#include "sbem_window.h"
#include "sbem_window_tm_bridge.h"
/*=== Constructors ===*/
SbemWindow::SbemWindow(){}
SbemWindow::SbemWindow(std::string objectName) : SbemObject(objectName) {}
SbemWindow::SbemWindow(std::string objectName, std::vector<std::string> propertyStrings) : SbemObject(objectName, propertyStrings) {}
/*=== Static methods ===*/
SbemWindow SbemWindow::createBasic(std::string name) {
	SbemWindow window = SbemWindow(name);
	window.addNumericProperty("MULTIPLIER", 1);
	window.addNumericProperty("AREA", 3.67);
	window.addNumericProperty("DEV-PROJ-RATIO", 1);
	window.addNumericProperty("FRAME-FACTOR", 0.1);
	window.addStringProperty("SHADING-POSITION", "None (no shading)");
	window.addNumericProperty("SHADING-FACTOR", 1);
	window.addNumericProperty("ASPECT-RATIO", 1.6757);
	window.addStringProperty("GLASS", "SG METAL");
	window.addStringProperty("BRISE-SOLEIL", "NO");
	return window;
}
// Constants
const std::string SbemWindow::OBJECT_NAME = "WINDOW";
/*=== Getters ===*/
float SbemWindow::area() {
	if(_gotArea)
		return _area;
	// Some windows represent multiple windows. It's stupid in the context of SBEM but since it's there we need to deal with it. 
	if (hasNumericProperty("MULTIPLIER"))
		_area = getNumericProperty("AREA")->getValue() * getNumericProperty("MULTIPLIER)")->getValue();
	else
		_area = getNumericProperty("AREA")->getValue();
	_gotArea = true;
	return _area;
}
/*=== Setters ===*/
void SbemWindow::setThermalBridge(SbemWindowTmBridge thermalBridge) {
	tmBridge			= thermalBridge;
	addedThermalBridge	= true;

}
/*=== The rest ===*/
bool SbemWindow::hasThermalBridge() { return addedThermalBridge; }
void SbemWindow::setGlass(std::shared_ptr<SbemGlass> gls) { glass = glass; }
std::string SbemWindow::toString() {
	setStringProperty("GLASS", "\"" + glass->name + "\"");
	return "\"" + name + "\" = " + OBJECT_NAME + "\n" + propertiesString() + "\n" + OBJECT_END;
}
