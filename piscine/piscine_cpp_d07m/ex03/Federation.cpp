#include <iostream>
#include <string>
#include "Destination.hh"
#include "Warpsystem.hh"
#include "Federation.hh"

/*
Starfleet's ships 
*/

Federation::Starfleet::Ship::Ship() {
	this->_length = 289;
	this->_width = 132;
	this->_name = "Entreprise";
	this->_maxWarp = 6;
	this->_photonTorpedo = 20;
	this->_shield = 100;
	this->_home = EARTH;
	this->_location = EARTH;
	std::cout << "The ship USS Entreprise has been finished. It is 289 m in length and 132 m in width. It can go to Warp 6! Weapons are set: 20 torpedoes ready." << std::endl;
}

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo) {
	this->_length = length;
	this->_width = width;
	this->_name = name;
	this->_maxWarp = maxWarp;
	this->_photonTorpedo = torpedo;
	this->_shield = 100;
	this->_home = EARTH;
	this->_location = EARTH;
	std::cout << "The ship USS " << this->_name << " has been finished. It is " << this->_length << " m in length and " << this->_width;
	std::cout << " m in width. It can go to Warp " << this->_maxWarp << "! Weapons are set: " << this->_photonTorpedo << " torpedoes ready." << std::endl;
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

int Federation::Starfleet::Ship::getShield() {
	return this->_shield;
}

void Federation::Starfleet::Ship::setShield(int shield) {
	this->_shield = shield;
}

int Federation::Starfleet::Ship::getTorpedo() {
	return this->_photonTorpedo;
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo) {
	this->_photonTorpedo = torpedo;
}

void Federation::Starfleet::Ship::fire(Borg::Ship *borg) {
	if (this->_photonTorpedo != 0) {
		this->_photonTorpedo -= 1;
		borg->setShield(borg->getShield() - 50);
		if (this->_photonTorpedo != 0)
			std::cout << this->_name <<": Firing on target. " << this->_photonTorpedo <<" torpedoes remaining." << std::endl;
		else
			std::cout << this->_name << ": No more torpedo to fire, " << this->_captain->getName() << "!" << std::endl;
	} else {
		std::cout << this->_name << ": No enough torpedoes to fire, " << this->_captain->getName() << "!" << std::endl;
	}
}

void Federation::Starfleet::Ship::fire(int torpedos, Borg::Ship *borg) {
	if (this->_photonTorpedo >= torpedos) {
		this->_photonTorpedo -= torpedos;
		borg->setShield(borg->getShield() - 50 * torpedos);
		if (this->_photonTorpedo != 0)
			std::cout << this->_name <<": Firing on target. " << this->_photonTorpedo <<" torpedoes remaining." << std::endl;
		else
			std::cout << this->_name << ": No more torpedo to fire, " << this->_captain->getName() << "!" << std::endl;
	} else {
		std::cout << this->_name << ": No enough torpedoes to fire, " << this->_captain->getName() << "!" << std::endl;
	}
}

/*
Independant Ships 
*/
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

WarpSystem::Core *Federation::Ship::getCore() {
	return this->_core;
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