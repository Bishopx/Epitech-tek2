
#include <iostream>
#include <string>
#include "Character.hh"
#include "Paladin.hh"
#include "Mage.hh"
#include "Priest.hh"

Paladin::Paladin(std::string const &Name, int Level) : 
Character(Name, Level), Warrior(Name, Level), Priest(Name, Level){
	this->Agility = 2;
	this->Spirit = 10;
	this->Strength = 9;
	this->Stamina = 10;
	this->Intelligence = 10;
	std::cout << "the light falls on " << Name << std::endl;
}

int Paladin::CloseAttack() {
	return (this->Warrior::CloseAttack());
}

int Paladin::RangeAttack() {
	return (this->Priest::RangeAttack());
}

int Paladin::Intercept() {
	return (this->Warrior::RangeAttack());
}