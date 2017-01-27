#include "Box.hh"

Box::Box(obj_type type) : Wrap(type) {
}

Box::~Box() {

}

Box::Box(Box & other) : Wrap(other._type)
{
	_full = other._full;
	_taken = other._taken;
	_open = other._open;	
}

Box &Box::operator=(Box &other)
{
	_type = other._type;
	_full = other._full;
	_taken = other._taken;
	_open = other._open;
  	return (*this);
}

void	Box::wrapMeThat(Object *obj) {
	if (obj->getType() == LITTLEPONY || obj->getType() == TEDDY) {
		if (_open == true) {
			if (_full == false) {
				std::cout << "tuuuut tuuut tuut" << std::endl;
				_title = obj->getTitle();
				_taken = false;
				_full = true;
			} else
				std::cerr << "This box already have a Toy in it" << std::endl;
		} else
			std::cerr << "This box already have a " << obj->getTitle() << " in it and is close" << std::endl;
	} else
		std::cerr << "You can only put Toy in a box" << std::endl;
}

void	Box::openMe() {
	if (_open == false && _full == true) {
		_open = true;
		_full = false;
		_title = "";
	} else
		std::cerr << "This box is already empty and open" << std::endl;
}

void	Box::closeMe() {
	if (_open == true) {
		if (_full == false)
			std::cerr << "You are trying to close an empty box" << std::endl;
		else
			_open = false;
	} else
		std::cerr << "This box is already closed" << std::endl;
}