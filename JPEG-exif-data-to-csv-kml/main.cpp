//Eli Koslofsky
//2/15/2018
//Main function:
//Command line program that prompts the user for a file path to
//a folder of JPEGS. it then reads the JPEG EXIF information
//and exports it to a CSV and google earth KML file.

#include <fstream>
#include <iostream>
#include <string>
#include "exif.h"
#include "ExportJpeg.h"
#include "Jpeg.h"
#include <vector>
#include <experimental/filesystem>
using std::ifstream;
using std::ofstream;
using std::fill_n;
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;
namespace fs = std::experimental::filesystem; //filesystem only compiles in c++14 forward

int main(){
	cout << "Enter the path of the folder that contains the jpegs" << endl;
	cout << "you'd like to process. Enter the path using forward" << endl;
	cout << "slashes or double backslashes" << endl;
	cout << "For example:" << endl;
	cout << "\"C:\\\\Users\\\\You\\\\Desktop\\\\photos\" or"<< endl;
	cout << "\"C:/Users/You/Desktop/photos.\"" << endl;
	cout << "Do not type quotation marks." << endl;
	
	string inputFolderPath;
	getline(cin, inputFolderPath);
	fs::path p = inputFolderPath;
	
	//vector that will store the file paths of the jpegs to be processed
	vector<string> jpegPathStrings;
	
	//test to ensure valid path to directory was entered, and if so, read exif data from
	//jpegs in that directory
	try {
		if (exists(p)){    // does p actually exist?
		  if (is_regular_file(p))        // is p a regular file?   
			cout << "This is a file, not a directory. No jpegs were processed." << '\n';

		  else if (is_directory(p)){    // is p a directory?
			  for (auto& p : fs::directory_iterator(inputFolderPath)) {
				  jpegPathStrings.push_back(p.path().string());
			  }
			  cout << "CSV and KML files written to folder containing .exe file" << endl;
		  }
		  else
			cout << p << " exists, but is neither a regular file nor a directory. No jpegs were processed.\n";
		}
		else
		  cout << "No directory at this location exists. No jpegs were processed.\n";
	  }

	catch (const fs::filesystem_error& ex){
		cout << ex.what() << '\n';
	}
	
	//use file paths of jpegs in director to create Jpeg objects
    Jpeg jpegVect;
    vector<Jpeg> testVect;
	for (int i = 0; i < jpegPathStrings.size(); i++) {
		testVect.push_back(jpegVect);
	}

	//read exif information from all jpeg objects in vector
	for (int i = 0; i < jpegPathStrings.size(); i++) {
			testVect[i].readJpeg(jpegPathStrings[i]);
		}
	
	//export CSV and KML of information read from jpegs
	exportCSV(testVect);
	exportKML(testVect);

	cout<< "Press enter to exit" << endl;
    cin.get();


return 0;
}
