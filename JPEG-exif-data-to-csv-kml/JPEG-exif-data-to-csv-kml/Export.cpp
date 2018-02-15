#include <fstream>
#include <iostream>
#include <string>
#include "exif.h"
#include "Jpeg.h"
#include "Export.h"
#include <vector>
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;


void exportCSV(vector<Jpeg> inputVect) {
	ofstream outputCSV;
	outputCSV.open("jpeg.csv");

	outputCSV << "Name, Camera Make, CameraModel, Image Width, Image Height, Image Date\\Time, Latitude, Longitude\n";
	for (int i = 0; i<inputVect.size(); i++) {
		outputCSV << inputVect[i].getName() << "," << inputVect[i].getCameraMake() << "," << inputVect[i].getCameraModel() << ","
			<< inputVect[i].getImgWidth() << "," << inputVect[i].getImgHeight() << "," << inputVect[i].getImgDateTime() << ","
			<< inputVect[i].getLat() << "," << inputVect[i].getLong() << "\n";
	}
	outputCSV.close();
};