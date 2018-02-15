#include <fstream>
#include <iostream>
#include <string>
#include "exif.h"
#include "jpeg.h"
#pragma warning(disable:4996)
using std::ifstream;
using std::fill_n;
using std::string;
using std::cout;
using std::endl;
using std::cin;

void Jpeg::readJpeg(string filePath) {
	FILE *fp = fopen(filePath.c_str(), "rb");
	if (!fp) {
		printf("Can't open file.\n");
	}
	fseek(fp, 0, SEEK_END);
	unsigned long fsize = ftell(fp);
	rewind(fp);
	unsigned char *buf = new unsigned char[fsize];
	if (fread(buf, 1, fsize, fp) != fsize) {
		printf("Can't read file.\n");
		delete[] buf;
	}
	fclose(fp);

	// Parse EXIF
	easyexif::EXIFInfo result;
	int code = result.parseFrom(buf, fsize);
	delete[] buf;
	if (code) {
		printf("Error parsing EXIF: code %d\n", code);
	}

	cameraMake = result.Make.c_str();
	cameraModel = result.Model.c_str();
	imgWidth = result.ImageWidth;
	imgHeight = result.ImageHeight;
	imgDateTime = result.DateTime.c_str();
	latitude = result.GeoLocation.Latitude;
	longitude = result.GeoLocation.Longitude;


	if (filePath.find_last_of('\\') == -1) {
	}
	else {
		int pos = filePath.find_last_of('\\');
		name = filePath.substr(pos + 1);
	}

	if (filePath.find_last_of('/') == -1) {
	}
	else {
		int pos = filePath.find_last_of('/');
		name = filePath.substr(pos + 1);
	}
}



string Jpeg::getCameraMake(){
    return cameraMake;
};
string Jpeg::getCameraModel(){
    return cameraModel;
};
double Jpeg::getImgWidth(){
    return imgWidth;
};
double Jpeg::getImgHeight(){
    return imgHeight;
};
string Jpeg::getImgDateTime(){
    return imgDateTime;
};
double Jpeg::getLat(){
    return latitude;
};
double Jpeg::getLong(){
    return longitude;
};
string Jpeg::getName(){
    return name;
};