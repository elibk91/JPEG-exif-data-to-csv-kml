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

    public:
        void readJpeg(string);
        string getCameraMake();
        string getCameraModel();
        double getImgWidth();
        double getImgHeight();
        string getImgDateTime();
        double getLat();
        double getLong();


};

#endif
