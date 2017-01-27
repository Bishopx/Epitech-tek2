#include "Wrap.hh"

Wrap::Wrap(obj_type type) : Object(type) {

}

Wrap::~Wrap() {
	std::cout << "Plus de paquet cadeau" << std::endl;
}

Wrap::Wrap(Wrap & other) : Object(other._type)
{
	_full = other._full;
	_taken = other._taken;
	_open = other._open;	
}

Wrap &Wrap::operator=(Wrap &other)
{
	_type = other._type;
	_full = other._full;
	_taken = other._taken;
	_open = other._open;
  	return (*this);
}

void	Wrap::isTaken() {
	if (_taken == false) {
		std::cout << "whistles while working" << std::endl;
		_taken = true;
	} else
		std::cerr << "You are already holding this object" << std::endl;	
}