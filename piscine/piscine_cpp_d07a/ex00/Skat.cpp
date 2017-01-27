#include <iostream>
#include <string>
#include "Skat.hh"

Skat::Skat(std::string const& name, int stimPaks) {
	this->_name = name;
	this->_stimPaks = stimPaks;
}

Skat::~Skat() {

}

int &Skat::stimPaks() {
	return (_stimPaks);
}

std::string const &Skat::name() const {
	return (_name);
}

void Skat::shareStimPaks(int number, int &stock) {
	if (this->_stimPaks < number)
		std::cout << "Don’t be greedy" << std::endl;
	else {
		stock += number;
		this->_stimPaks -= number;
		std::cout << "Keep the change." << std::endl;
	}
}

void Skat::addStimPaks(unsigned int number) {
	if (this->_stimPaks == 0)
		std::cout << "Hey boya, did you forget something ?" << std::endl;
	this->_stimPaks += number;
}

void Skat::useStimPaks() {
	if (this->_stimPaks > 0)
		std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
	else
		std::cout << "Mediiiiiic" << std::endl;	
}

void Skat::status() {
	std::cout << "Soldier " << this->_name << " reporting " << this->_stimPaks << " stimpaks remaining sir" << std::endl;
}