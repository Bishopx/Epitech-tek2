#include "Sorcerer.hh"
#include "Peon.hh"

Peon::Peon(std::string const &Name) : 
Victim(Name) {
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon() {
	std::cout << "Bleuark..." << std::endl;
}

void 				Peon::getPolymorphed() const {
	std::cout << _name << " has been turned into a pink pony !" << std::endl;
}