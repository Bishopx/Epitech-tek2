#include <iostream>
#include <string>
#include "Warpsystem.hh"
#include "Federation.hh"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWrap) {
	this->_length = length;
	this->_width = width;
	this->_name = name;
	this->_maxWrap = maxWrap;
	std::cout << "The ship USS " << name <<" has been finished. It is " << length << " m in length and " << width <<" m in width." << std::endl;
	std::cout << "It can go to Warp " << maxWrap << "!" << std::endl;
}

void Federation::Starfleet::Ship::getName() {
	std::cout << this->_name << std::endl;
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core) {
	this->_core = core;
	std::cout << "USS " << this->_name <<": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore() {
	if (this->_core->checkReactor()->isStable() == true)
		std::cout << "USS "<< this->_name << ": The core is stable at the time." << std::endl;
	else
		std::cout << "USS "<< this->_name << ": The core is unstable at the time." << std::endl;
}

Federation::Ship::Ship(int length, int width, std::string name) {
	this->_length = length;
	this->_width = width;
	this->_name = name;
	this->_maxWrap = 1;
	std::cout << "The independant ship " << name <<" just finished its construction. It is " << length << " m in length and " << width <<" m in width." << std::endl;

}

void Federation::Ship::getName() {
	std::cout << this->_name << std::endl;
}

void Federation::Ship::setupCore(WarpSystem::Core *core) {
	this->_core = core;
	std::cout << this->_name <<": The core is set." << std::endl;
}

void Federation::Ship::checkCore() {
	if (this->_core->checkReactor()->isStable() == true)
		std::cout << this->_name << ": The core is stable at the time." << std::endl;
	else
		std::cout << this->_name << ": The core is unstable at the time." << std::endl;
}