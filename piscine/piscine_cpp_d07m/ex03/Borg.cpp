#include <iostream>
#include <string>
#include "Borg.hh"

Borg::Ship::Ship(int weapon) {
	this->_side = 300;
	this->_maxWarp = 9;
	this->_home = UNICOMPLEX;
	this->_weaponFrequency = weapon;
	this->_shield = 100;
	this->_repair = 3;
	std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
	std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
	std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::Ship(int weapon, int repair) {
	this->_side = 300;
	this->_maxWarp = 9;
	this->_home = UNICOMPLEX;
	this->_weaponFrequency = weapon;
	this->_shield = 100;
	this->_repair = repair;
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

int Borg::Ship::getShield() {
	return this->_shield;
}

void Borg::Ship::setShield(int shield) {
	this->_shield = shield;
}

int Borg::Ship::getWeaponFrequency() {
	return this->_weaponFrequency;
}

void Borg::Ship::setWeaponFrequency(int weapon) {
	this->_weaponFrequency = weapon;
}

short Borg::Ship::getRepair() {
	return this->_repair;
}

void Borg::Ship::setRepair(short repair) {
	this->_repair = repair;
}

void Borg::Ship::fire(Federation::Starfleet::Ship *ship) {
	ship->setShield(ship->getShield() - this->_weaponFrequency);
	std::cout << "Firing on target with " << this->_weaponFrequency <<"GW frequency." << std::endl;
}

void Borg::Ship::fire(Federation::Ship *ship) {
	ship->getCore()->checkReactor()->setStability(false);
	std::cout << "Firing on target with " << this->_weaponFrequency <<"GW frequency." << std::endl;	
}

void Borg::Ship::repair() {
	if (this->_repair > 0) {
		this->_repair -= 1;
		this->_shield = 100;
		std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
	} else
		std::cout << "Energy cells depleted, shield weakening." << std::endl;	
}