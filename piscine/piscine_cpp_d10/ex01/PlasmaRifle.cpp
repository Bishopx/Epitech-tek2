#include "PlasmaRifle.hh"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21) {}

void	PlasmaRifle::attack()  {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}