#include "Ratatouille.h"

Ratatouille::Ratatouille() {

}

Ratatouille::~Ratatouille() {
	oss.str("");
}

Ratatouille &Ratatouille::operator=(const Ratatouille &other) {
	oss.str(other.oss.str());

	return *this;
}

Ratatouille::Ratatouille(Ratatouille const &other) {
    std::string str;

    str = other.oss.str();
    oss << str;
}

Ratatouille &Ratatouille::addVegetable(unsigned char n) {
	oss << n;
	return *this;
}

Ratatouille &Ratatouille::addCondiment(unsigned int n) {
	oss << n;
	return *this;
}

Ratatouille &Ratatouille::addSpice(double n) {
	oss << n;
	return *this;
}

Ratatouille &Ratatouille::addSauce(const std::string &str) {
	oss << str;
	return *this;
}

std::string Ratatouille::kooc(void) {
	return oss.str();
}