#include "PowerFist.hh"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50) {}

void	PowerFist::attack() {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
