//Eli Koslofsky
//2/15/2018
//ExportJpeg.h:
//Header file contains function prototypes for functions
//found in Jpeg.cpp and member variables for the class

#ifndef JPEG_H
#define JPEG_H

#include <iostream>
using std::string;

class Jpeg
{
    private:
        string cameraMake;
        string cameraModel;
        double imgWidth;
        double imgHeight;
        string imgDateTime;
        double latitude;
        double longitude;
        string name;
		string fullFilePath;
		string ext;

    public:
        void readJpeg(string);
        string getCameraMake();
        string getCameraModel();
        double getImgWidth();
        double getImgHeight();
        string getImgDateTime();
        double getLat();
        double getLong();
        string getName();
		string getFullFilePath();
		string getExt();

};

#endif
