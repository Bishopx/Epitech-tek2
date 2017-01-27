
#include <iostream>
#include <string>
#include "Mage.hh"

Mage::Mage(std::string const &Name, int Level) : Character(Name, Level){
	this->Agility = 7;
	this->Spirit = 11;
	this->Strength = 6;
	this->Stamina = 6;
	this->Intelligence = 12;
	std::cout << Name << " teleported" << std::endl;
}

int Mage::CloseAttack() {
	if (this->power < 10) {
		std::cout << this->name << " out of power" << std::endl;
		return (0);
	}	
	this->power -= 10;
	this->Range = RANGE;
	std::cout << this->name << " blinks" << std::endl;
	return (0);
} 

int Mage::RangeAttack() {
	if (this->power < 25) {
		std::cout << this->name << " out of power" << std::endl;
		return (0);
	}
	std::cout << this->name << " launches a fire ball" << std::endl;
	this->power -= 25;
	return (this->Spirit + 20);
}

void Mage::RestorePower() {
	if (this->power + this->Intelligence <= 50)
		this->power += 50 + this->Intelligence;
	else
		this->power = 100;	
	std::cout << this->name << " takes a mana potion" << std::endl;
}