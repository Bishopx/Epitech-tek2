#include <iostream>
#include <string>
#include "droid.hh"

Droid::Droid() : Id(""), Energy(50), Attack(25), Toughness(15) , Status(new std::string("Standing by")){
	std::cout << "Droid '' Activated" << std::endl;
}

Droid::Droid(std::string id) : Id(id), Energy(50), Attack(25), Toughness(15) , Status(new std::string("Standing by")) {
	std::cout << "Droid '" << id << "' Activated" << std::endl;
}

Droid::Droid(Droid const &other) : Id(other.Id), Energy(other.Energy), Attack(25), Toughness(15), Status(new std::string(*other.Status)){
	std::cout << "Droid '" << other.Id << "' Activated, Memory Dumped" << std::endl;
}

Droid &Droid::operator=(Droid const &other) {
	if (&other != this) {
		this->Id = other.Id;
		this->Energy = other.Energy;
		this->Status = other.Status;
	}
	return (*this);
}

Droid::~Droid() {
	std::cout << "Droid '" << this->Id << "' Destroyed" << std::endl;
}

/* Getter Fonctions */

std::string const &Droid::getId() const {
	return (Id);
}

size_t const &Droid::getEnergy() const {
	return (Energy);
}

size_t const &Droid::getAttack() const {
	return (Attack);
}

size_t const &Droid::getToughness() const {
	return (Toughness);
}

std::string const &Droid::getStatus() const {
	return (*Status);
}

/* Setter Functions */

void	Droid::setId(std::string Id) {
	this->Id = Id;
}

void	Droid::setEnergy(size_t Energy) {
	if (Energy <= 100)
		this->Energy = Energy;
}

void	Droid::setStatus(std::string *Status) {
	this->Status = Status;
}

/*Operator Overloading member */

Droid  &Droid::operator<<(size_t &Energy) {
	if (this->Energy + Energy > 100) {
		Energy -= 100 - this->Energy;
		this->Energy = 100;
	} else {
		this->Energy += Energy; 
		Energy = 0;
	}
	return *this;
}

/* Operator Overloading non member */

std::ostream &operator<<(std::ostream &os, Droid const &droid) {
	os << "Droid '" << droid.getId() << "', " << droid.getStatus() << ", " <<droid.getEnergy();
	return (os);
}

bool operator==(Droid const &d1, Droid const &d2) {
	if (d1.getId() == d2.getId() && d1.getEnergy() == d2.getEnergy() &&
		d1.getAttack() == d2.getAttack() && d1.getToughness() == d2.getToughness() &&
		d1.getStatus() == d2.getStatus())
		return true;
	else
		return false;
}

bool operator!=(Droid const &d1, Droid const &d2) {
	if (d1.getId() != d2.getId() || d1.getEnergy() != d2.getEnergy() ||
		d1.getAttack() != d2.getAttack() || d1.getToughness() != d2.getToughness() ||
		d1.getStatus() != d2.getStatus())
		return true;
	else
		return false;
}