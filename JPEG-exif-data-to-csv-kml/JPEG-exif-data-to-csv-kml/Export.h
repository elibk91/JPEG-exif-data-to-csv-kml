#ifndef EXPORT_H
#define EXPORT_H

#include <fstream>
#include <iostream>
#include <string>
#include "exif.h"
#include "jpeg.h"
#include <vector>
using std::string;
using std::vector;

void exportCSV(vector<Jpeg> inputVect);
#endif
