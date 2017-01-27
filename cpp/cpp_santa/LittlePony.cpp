#include "LittlePony.hh"

LittlePony::LittlePony(obj_type type, std::string const &t) : Toy(type, t) {
}

LittlePony::~LittlePony() {
	std::cout << "LittlePony is dead" << std::endl;
}

LittlePony::LittlePony(LittlePony & other) : Toy(other._type, other._title)
{
	_full = other._full;
	_taken = other._taken;
	_open = other._open;	
}

LittlePony &LittlePony::operator=(LittlePony &other)
{
	_title = other._title;
	_type = other._type;
	_full = other._full;
	_taken = other._taken;
	_open = other._open;
  	return (*this);
}

void	LittlePony::isTaken() {
	_taken = true;
	std::cout << "yo man" << std::endl;
}