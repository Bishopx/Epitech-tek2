
#include <iostream>
#include <string>
#include "Character.hh"
#include "Warrior.hh"
#include "Priest.hh"
#include "Mage.hh"

Character::Character(std::string const &Name, int Level) : 
	name(Name), level(Level), pv(100), power(100),
	Strength(5), Stamina(5), Agility(5), Intelligence(5), Spirit(5), Range(CLOSE) {

		std::cout << Name << " Created" << std::endl;
}

const std::string	&Character::getName() const{
	return (name);
}

int const			&Character::getLvl() const{
	return level;
}

int const			&Character::getPv() const{
	return pv;
}

int const			&Character::getPower() const{
	return power;
}

int					Character::CloseAttack() {
	if (this->power < 10) {
		std::cout << this->name << " out of power" << std::endl;
		return (0);
	}
	this->power -= 10;
	std::cout << this->name << " strikes with a wood stick" << std::endl;
	return (this->Strength + 10);
}

int					Character::RangeAttack() {
	if (this->power < 10) {
		std::cout << this->name << " out of power" << std::endl;
		return (0);
	}	
	this->power -= 10;
	std::cout << this->name << " launches a stone" << std::endl;
	return (this->Strength + 5);
}

void				Character::Heal() {
	if (this->pv <= 50)
		this->pv += 50;
	else
		this->pv = 100;
	std::cout << this->name << " takes a potion" << std::endl;
}

void				Character::RestorePower() {
	this->power = 100;
	std::cout << this->name << " eats" << std::endl;
}

void				Character::TakeDamage(int damage) {
	this->pv -= damage;
	if (this->pv <= 0)
		std::cout << this->name << " out of combat" << std::endl;
	else
		std::cout << this->name << " takes " << damage << " damage" << std::endl;
}