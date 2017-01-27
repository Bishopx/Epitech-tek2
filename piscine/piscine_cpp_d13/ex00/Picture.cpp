#include "Picture.h"
#include <fstream>

Picture::Picture() : data("") {

}

Picture::Picture(const std::string &file) {
	std::ifstream 	myfile;
	char 			c;

  	myfile.open(file.c_str(), std::ios::in);
  	if (myfile.is_open()) {
       while (myfile.get(c))
        data += c;
        myfile.close();
  	} else {
  		data = "ERROR";
  	}
}

Picture::~Picture() {

}

Picture::Picture(Picture const &other) : data(other.data) {

}

Picture &Picture::operator=(Picture const &other) {
	this->data = other.data;
	return *this;
}

bool 				Picture::getPictureFromFile(const std::string &file) {
	std::ifstream 	myfile;
	char 			c;

  	myfile.open(file.c_str(), std::ios::in);
  	if (myfile.is_open()) {
       while (myfile.get(c))
         data += c;
         myfile.close();
         return true;
  	} else {
  		data = "ERROR";
  		return false;
  	}
}