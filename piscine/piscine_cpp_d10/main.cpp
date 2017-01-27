#include <iostream>
#include <string>
#include "Character.hh"
#include "AEnemy.hh"
#include "PlasmaRifle.hh"
#include "PowerFist.hh"
#include "AWeapon.hh"
#include "SuperMutant.hh"
#include "RadScorpion.hh"

int main() {
 Character* zaz = new Character("zaz");

 std::cout << *zaz;

 AEnemy* b = new RadScorpion();

 AWeapon* pr = new PlasmaRifle();
 AWeapon* pf = new PowerFist();

 zaz->equip(pr);
 std::cout << *zaz;
 zaz->equip(pf);

 zaz->attack(b);
 std::cout << *zaz;
 zaz->equip(pr);
 std::cout << *zaz;
 zaz->attack(b);
 std::cout << *zaz;
 zaz->attack(b);
 std::cout << *zaz;

 return 0;
}