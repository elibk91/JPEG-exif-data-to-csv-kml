#include <fstream>
#include <iostream>
#include <string>
#include "exif.h"
#include "Jpeg.h"
#include "Export.h"
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
namespace fs = std::experimental::filesystem;



int main(){


	vector<string> jpegPathStrings;

	for (auto& p : fs::directory_iterator("C:\\Users\\Eli Koslofsky\\Desktop\\photos")){
		jpegPathStrings.push_back(p.path().string());
	}

	

    Jpeg test1;
    vector<Jpeg> testVect;
	for (int i = 0; i < jpegPathStrings.size(); i++) {
		testVect.push_back(test1);
	}
	for (int i = 0; i < jpegPathStrings.size(); i++) {
		testVect[i].readJpeg(jpegPathStrings[i]);
	}
	


	exportCSV(testVect);


	cout<<"Press enter to exit"<<endl;
    cin.get();


return 0;
}
