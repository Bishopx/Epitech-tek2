#include <iostream>
#include <string>
#include "Hunter.hh"
#include "Warrior.hh"
#include "Paladin.hh"

Hunter::Hunter(std::string const &Name, int Level) : Character(Name, Level),Warrior(Name, Level){
	this->Agility = 24;
	this->Spirit = 6;
	this->Strength = 9;
	this->Stamina = 9;
	this->Intelligence = 5;
	this->weaponName = "sword";
	std::cout << Name << " is born from a tree" << std::endl;
}

int Hunter::CloseAttack() {
	if (this->power < 30) {
		std::cout << this->name << " out of power" << std::endl;
		return (0);
	}	
	this->power -= 30;
	std::cout << this->name << " strikes with his " << this->weaponName << std::endl;
	return (20 + this->Strength);
} 

int Hunter::RangeAttack() {
	if (this->power < 25) {
		std::cout << this->name << " out of power" << std::endl;
		return (0);
	}
	std::cout << this->name << " uses his bow" << std::endl;
	this->power -= 25;
	return (this->Agility + 20);
}

void Hunter::RestorePower() {
	this->power = 100;
	std::cout << this->name << " meditates" << std::endl;
}