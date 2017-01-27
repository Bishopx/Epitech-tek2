
#include <iostream>
#include <string>
#include "Warrior.hh"

Warrior::Warrior(std::string const &Name, int Level) : Character(Name, Level){
	this->Agility = 7;
	this->Spirit = 5;
	this->Strength = 12;
	this->Stamina = 12;
	this->Intelligence = 6;
	this->weaponName = "hammer";
	std::cout << "I'm " << Name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

int Warrior::CloseAttack() {
	if (this->power < 30) {
		std::cout << this->name << " out of power" << std::endl;
		return (0);
	}	
	this->power -= 30;
	std::cout << this->name << " strikes with his " << this->weaponName << std::endl;
	return (20 + this->Strength);
} 

int Warrior::RangeAttack() {
	if (this->power < 10) {
		std::cout << this->name << " out of power" << std::endl;
		return (0);
	}
	std::cout << this->name << " intercepts" << std::endl;
	this->power -= 10;
	this->Range = CLOSE;
	return (0);
}