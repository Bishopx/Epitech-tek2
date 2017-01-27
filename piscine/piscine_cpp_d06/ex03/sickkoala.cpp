#include <iostream>
#include <algorithm>
#include <string>
#include "sickkoala.h"

SickKoala::SickKoala(std::string Name) {
		this->name = Name;
}

SickKoala::~SickKoala() {
	std::cout << "Mr." << this->name << ": Kreooogg !! Je suis gueriiii !" << std::endl;
}

void SickKoala::poke() {
	std::cout << "Mr." << this->name << ": Gooeeeeerrk !! :'(" << std::endl;
}

void SickKoala::overDrive(std::string drive) {
	size_t	pos;

	pos = drive.find("Kreog !");
	if (pos != std::string::npos) {
			drive.replace(pos, 7, "1337 !");
			overDrive(drive);
	} else
 		std::cout << "Mr." << this->name << ": " <<  drive << std::endl;
}

bool SickKoala::takeDrug(std::string drug) {
	if (drug.compare("Buronzand") == 0) {
		std::cout << "Mr." << this->name << ": Et la fatigue a fait son temps !" << std::endl;
		return true;
	}
	std::transform(drug.begin(), drug.end(), drug.begin(), ::tolower);
	if (drug.compare("mars") == 0) {
			std::cout << "Mr." << this->name << ": Mars, et ca kreog !" << std::endl;
			return true;
		}
		std::cout << "Mr." << this->name << ": Goerkreog !" << std::endl;
		return false;
}
