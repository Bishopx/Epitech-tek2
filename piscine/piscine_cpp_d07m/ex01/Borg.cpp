#include <iostream>
#include <string>
#include "Borg.hh"

Borg::Ship::Ship() {
	this->_side = 300;
	this->_maxWrap = 9;
	std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
	std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
	std::cout << "Resistance is futile." << std::endl;
}

void Borg::Ship::setupCore(WarpSystem::Core *core) {
	this->_core = core;
}

void Borg::Ship::checkCore() {
	if (this->_core->checkReactor()->isStable() == true)
		std::cout << "Everything is in order." << std::endl;
	else
		std::cout << "Critical failure imminent." << std::endl;
}
