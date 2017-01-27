#include "Toy.hh"

Toy::Toy(obj_type type, std::string const &t) : Object(type, t) {
}

Toy::~Toy() {
}

Toy::Toy(Toy & other) : Object(other._type, other._title)
{
	_full = other._full;
	_taken = other._taken;
	_open = other._open;	
}

Toy &Toy::operator=(Toy &other)
{
	_title = other._title;
	_type = other._type;
	_full = other._full;
	_taken = other._taken;
	_open = other._open;
  	return (*this);
}