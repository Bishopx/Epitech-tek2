#include "AssaultTerminator.hh"

AssaultTerminator::AssaultTerminator() {
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::~AssaultTerminator() {
	std::cout << "I’ll be back ..." << std::endl;
}

AssaultTerminator *AssaultTerminator::clone() const {
}

void 			AssaultTerminator::battleCry() const {
	std::cout << "This code is unclean. PURIFY IT !" << std::endl;
}

void 			AssaultTerminator::rangedAttack() const {
	std::cout << "* does nothing *" << std::endl;
}

void 			AssaultTerminator::meleeAttack() const {
	std::cout << "* attacks with chainsword *" << std::endl;
}