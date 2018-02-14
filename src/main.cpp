#include <fstream>
#include <iostream>
#include <string>
#include "exif.h"
#include "jpeg.h"
using std::ifstream;
using std::fill_n;
using std::string;
using std::cout;
using std::endl;
using std::cin;

int main(){
Jpeg test;
test.readJpeg("C:\\Users\\Eli Koslofsky\\Desktop\\photos\\test.jpg");

cout<<test.getCameraMake()<<endl;
cout<<test.getCameraModel()<<endl;
cout<<test.getImgWidth()<<endl;
cout<<test.getImgHeight()<<endl;
cout<<test.getImgDateTime()<<endl;
cout<<test.getLat()<<endl;
cout<<test.getLong()<<endl;

cout<<"Press any key to exit"<<endl;
cin.get();

return 0;
}
