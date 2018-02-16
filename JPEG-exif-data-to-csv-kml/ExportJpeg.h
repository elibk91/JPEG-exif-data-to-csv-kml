//Eli Koslofsky
//2/15/2018
//ExportJpeg.h:
//Header file contains function prototypes for functions
//found in ExportJpeg.cpp

#ifndef EXPORTJPEG_H
#define EXPORTJPEG_H

#include "Jpeg.h"
#include <vector>
#include <string>
using std::vector;

void exportCSV(vector<Jpeg>);
void exportKML(vector<Jpeg>);

#endif
