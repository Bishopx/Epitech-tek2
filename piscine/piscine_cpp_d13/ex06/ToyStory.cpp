#include "ToyStory.h"
#include <iostream>
#include "Toy.h"
#include "ToyStory.h"
#include "Buzz.h"
#include "Woody.h"

ToyStory::ToyStory() {

}

ToyStory::~ToyStory() {

}

bool ToyStory::tellMeAStory(std::string const & filename, Toy & toy1, bool (Toy::*func1)(const std::string &), Toy & toy2, bool (Toy::*func2)(const std::string &)) {
	std::ifstream 	myfile;
	std::string		buffer;
	int 			file_choice = 0;
	size_t 			pos;

	std::cout << toy1.getAscii() << std::endl;
	std::cout << toy2.getAscii() << std::endl;
  	myfile.open(filename.c_str(), std::ios::in);
  	if (myfile.is_open()) {
       while (getline(myfile, buffer)) {
			if ((pos = buffer.find("picture:")) == std::string::npos) {

				if (file_choice % 2)
					(toy1.*func1)(buffer);
				else 
					(toy2.*func2)(buffer);
			}
			else {
				std::string str = buffer.substr(8);
				std::cout << str << std::endl;
				if (file_choice % 2) {
					toy1.setAscii(str);
					std::cout << toy1.getAscii() << std::endl;
				}
				else {
					toy2.setAscii(str);
					std::cout << toy2.getAscii() << std::endl;
				}
			}
			file_choice++;       	
  		} 
  	} else
  		return false;	
	return true;
}