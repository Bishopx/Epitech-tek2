#include "Coconut.h"

Coconut::Coconut() :
	Fruit(15, "coconut") {

}

Coconut::~Coconut() {

}

std::string const &Coconut::getName() const {
	return _name;
}

int const 			&Coconut::getVitamins() const {
	return _vitamins;
}

