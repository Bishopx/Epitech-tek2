#include "Lime.h"

Lime::Lime() :
	Fruit(2, "lime") {

}

Lime::~Lime() {

}

std::string const &Lime::getName() const {
	return _name;
}

int const 			&Lime::getVitamins() const {
	return _vitamins;
}

