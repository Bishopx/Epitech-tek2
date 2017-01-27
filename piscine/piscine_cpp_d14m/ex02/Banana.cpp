#include "Banana.h"

Banana::Banana() :
	Fruit(5, "banana") {

}

Banana::~Banana() {

}

std::string const &Banana::getName() const {
	return _name;
}

int const 			&Banana::getVitamins() const {
	return _vitamins;
}

