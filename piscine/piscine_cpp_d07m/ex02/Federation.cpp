#include <iostream>
#include <string>
#include "Destination.hh"
#include "Warpsystem.hh"
#include "Federation.hh"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp) {
	this->_length = length;
	this->_width = width;
	this->_name = name;
	this->_maxWarp = maxWarp;
	this->_home = EARTH;
	this->_location = EARTH;
	std::cout << "The ship USS " << name <<" has been finished. It is " << length << " m in length and " << width <<" m in width." << std::endl;
	std::cout << "It can go to Warp " << maxWarp << "!" << std::endl;
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

void Federation::Starfleet::Ship::promote(Captain *captain) {
	this->_captain = captain;
	std::cout << captain->getName() << ": I'm glad to be the captain of the USS " << this->_name << "." << std::endl;
}

bool Federation::Starfleet::Ship::move(int warp, Destination d) {
	if ((short)warp <= this->_maxWarp && d != this->_location && this->_core->checkReactor()->isStable() == true) {
		this->_location = d;
		return true;
	} else
		return false;
}

bool Federation::Starfleet::Ship::move(int warp) {
	if (this->_location != this->_home && (short)warp <= this->_maxWarp && this->_core->checkReactor()->isStable() == true) {
		this->_location = this->_home;
		return true;
	} else
		return false;
}

bool Federation::Starfleet::Ship::move(Destination d) {
	if (d != this->_location && this->_core->checkReactor()->isStable() == true) {
		this->_location = d;
		return true;
	} else
		return false;
}

bool Federation::Starfleet::Ship::move() {
	if (this->_location != this->_home && this->_core->checkReactor()->isStable() == true) {
		this->_location = this->_home;
		return true;
	} else
		return false;
}

Federation::Ship::Ship(int length, int width, std::string name) {
	this->_length = length;
	this->_width = width;
	this->_name = name;
	this->_maxWarp = 1;
	this->_home = VULCAN;
	this->_location = VULCAN;
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

bool Federation::Ship::move(int warp, Destination d) {
	if ((short)warp <= this->_maxWarp && d != this->_location && this->_core->checkReactor()->isStable() == true) {
		this->_location = d;
		return true;
	} else
		return false;
}

bool Federation::Ship::move(int warp) {
	if (this->_location != this->_home && (short)warp <= this->_maxWarp && this->_core->checkReactor()->isStable() == true) {
		this->_location = this->_home;
		return true;
	} else
		return false;
}

bool Federation::Ship::move(Destination d) {
	if (d != this->_location && this->_core->checkReactor()->isStable() == true) {
		this->_location = d;
		return true;
	} else
		return false;
}

bool Federation::Ship::move() {
	if (this->_location != this->_home && this->_core->checkReactor()->isStable() == true) {
		this->_location = this->_home;
		return true;
	} else
		return false;
}

Federation::Starfleet::Captain::Captain(std::string name) {
	this->_name = name;
}

std::string Federation::Starfleet::Captain::getName() {
	return this->_name;
}

int Federation::Starfleet::Captain::getAge() {
	return this->_age;
}

void Federation::Starfleet::Captain::setAge(int age) {
	this->_age = age;
}

Federation::Starfleet::Ensign::Ensign(std::string name) {
	this->_name = name;
	std::cout << "Ensign " << name <<", awaiting orders." << std::endl;
}