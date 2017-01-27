#include <iostream>
#include <string>
#include "Borg.hh"

Borg::Ship::Ship() {
	this->_side = 300;
	this->_maxWarp = 9;
	this->_home = UNICOMPLEX;
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

bool Borg::Ship::move(int warp, Destination d) {
	if ((short)warp <= this->_maxWarp && d != this->_location && this->_core->checkReactor()->isStable() == false) {
		std::cout << this->_location << std::endl;
		this->_location = d;
		return true;
	} else
		return false;
}

bool Borg::Ship::move(int warp) {
	if (this->_location != this->_home && (short)warp <= this->_maxWarp && this->_core->checkReactor()->isStable() == true) {
		this->_location = this->_home;
		return true;
	} else
		return false;
}

bool Borg::Ship::move(Destination d) {
	if (d != this->_location && this->_core->checkReactor()->isStable() == true) {
		this->_location = d;
		return true;
	} else
		return false;
}

bool Borg::Ship::move() {
	if (this->_location != this->_home && this->_core->checkReactor()->isStable() == true) {
		this->_location = this->_home;
		return true;
	} else
		return false;
}