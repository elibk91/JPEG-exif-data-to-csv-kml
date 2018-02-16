//Eli Koslofsky
//2/15/2018
//ExportJpeg.cpp:
//Contains functions used to export jpeg exif data to CSV and KML

#include <fstream>
#include <iostream>
#include <string>
#include "Jpeg.h"
#include "ExportJpeg.h"
#include <vector>
using std::ofstream;
using std::string;
using std::vector;
namespace fs = std::experimental::filesystem; //filesystem only compiles in c++14 forward

//export jpeg exif data to CSV
void exportCSV(vector<Jpeg> inputVect) {
	ofstream outputCSV;
	outputCSV.open("jpeg.csv"); //CSV will be written to location where exe is run
	outputCSV << "Name, Camera Make, CameraModel, Image Width, Image Height"
	<< ", Image Date\\Time, Latitude, Longitude\n";
	
		for (int i = 0; i < inputVect.size(); i++) { //only write files read that are jpegs
			if ((inputVect[i].getExt() == ("jpeg")) || (inputVect[i].getExt() == ("jpg"))
			|| (inputVect[i].getExt() == ("JPEG")) || (inputVect[i].getExt() == ("JPG"))) {
				outputCSV << inputVect[i].getName() << "," << inputVect[i].getCameraMake();
				outputCSV << "," << inputVect[i].getCameraModel() << ",";
				outputCSV << inputVect[i].getImgWidth() << "," << inputVect[i].getImgHeight();
				outputCSV << "," << inputVect[i].getImgDateTime() << "," << inputVect[i].getLat();
				outputCSV << "," << inputVect[i].getLong() << "\n";
			}
		}
	outputCSV.close();
};

//export jpeg exif data to KML
void exportKML(vector<Jpeg> inputVect) {
	ofstream outputKML; //KML will be written to location where exe is run
	outputKML.open("jpeg.kml");

	outputKML << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << "\n";
	outputKML << "<kml xmlns=\"http://www.opengis.net/kml/2.2\" ";
	outputKML << "xmlns:gx=\"http://www.google.com/kml/ext/2.2\" ";
	outputKML << "xmlns:kml=\"http://www.opengis.net/kml/2.2\" ";
	outputKML << "xmlns:atom=\"http://www.w3.org/2005/Atom\">" << "\n";
	outputKML << "<Document>" << "\n\t" << "<name>Photo Locations</name>" << "\n";

	
	for (int i = 0; i < inputVect.size(); i++) { //only write files read that are jpegs
		if ((inputVect[i].getExt() == ("jpeg")) || (inputVect[i].getExt() == ("jpg"))
			|| (inputVect[i].getExt() == ("JPEG")) || (inputVect[i].getExt() == ("JPG"))) {
			outputKML << "\t<Placemark>" << "\n";
			outputKML << "\t\t<name>" << inputVect[i].getName() << "</name>\n";
			outputKML << "\t\t<description><![CDATA[" << "Camera Make: ";
			outputKML << inputVect[i].getCameraMake() << "\n\t\t\t<br>Camera Model: ";
			outputKML << inputVect[i].getCameraModel() << "\n\t\t\t<br>Image Width: ";
			outputKML << inputVect[i].getImgWidth() << "\n\t\t\t<br>Image Height: ";
			outputKML << inputVect[i].getImgHeight() << "\n\t\t\t<br>Image Date/Time: ";
			outputKML << inputVect[i].getImgDateTime() << "<br>";
			outputKML << "\n<img style=\"max-width:500px; \" src=\"file:///";
			outputKML << inputVect[i].getFullFilePath() << "\">]]></description>";
			outputKML << "\t\t<Point>\n\t\t\t<coordinates>" << inputVect[i].getLong() << ",";
			outputKML << inputVect[i].getLat() << ",0</coordinates>\n\t\t</Point>\n";
			outputKML << "\t</Placemark>\n";
		}
	}
	outputKML << "</Document>\n</kml>\n";
	outputKML.close();
};