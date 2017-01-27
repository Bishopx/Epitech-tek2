
#include <iostream>
#include <string>
#include "Priest.hh"
#include "Warrior.hh"

Priest::Priest(std::string const &Name, int Level) :Character(Name, Level), Mage(Name, Level){
	this->Agility = 2;
	this->Spirit = 21;
	this->Strength = 4;
	this->Stamina = 4;
	this->Intelligence = 42;
	std::cout << Name << " enters in the order" << std::endl;
}

int Priest::CloseAttack() {
	if (this->power < 10) {
		std::cout << this->name << " out of power" << std::endl;
		return (0);
	}	
	this->power -= 10;
	std::cout << this->name << " uses a spirit explosion" << std::endl;
	return (10 + this->Spirit);
} 

int Priest::RangeAttack() {
	if (this->power < 25) {
		std::cout << this->name << " out of power" << std::endl;
		return (0);
	}
	std::cout << this->name << " launches a fire ball" << std::endl;
	this->power -= 25;
	return (20 + this->Spirit);
}

void Priest::Heal() {
	if (this->power >= 10) {
		this->power -= 10;
		if (this->pv <= 30)
			this->pv += 70;
		else
			this->pv = 100;
		std::cout << this->name << " casts a little heal spell" << std::endl;
	}
}