# JPEG-exif-data-to-csv-kml
Project takes directory of JPEG files, reads their exif data, and exports them to csv/kml.

Contains an exe that can be run that features a command line program that prompts the user
for a directory of jpegs, and then exports them to google earth kml using their lat/long
and exports the exif data into a csv file.

Project is written in C++ and utilizes the std::filesystem, which compiles with C++14 and up.
http://en.cppreference.com/w/cpp/experimental/fs/directory_iterator

Project also utilizes easyexif library by Mayank Lahiri to parse the exif data from the jpeg
files.
https://github.com/mayanklahiri/easyexif/blob/master/README.md
