#include "Object.hh"

Object::Object(obj_type type, std::string const &title) : 
_title(title), _type(type), _taken(false),
_open(true), _full(false) {

}

Object::Object(obj_type type) : 
_title(""), _type(type), _taken(false),
_open(true), _full(false) {

}

Object::~Object() {
	std::cout << "Et les jouets ne sont plus" << std::endl;
}

Object::Object(Object & other) : 
_title(other._title), _type(other._type) , _taken(other._taken),
_open(other._open), _full(other._full)
{

}

Object &Object::operator=(Object &other)
{
	_title = other._title;
	_type = other._type;
	_full = other._full;
	_taken = other._taken;
	_open = other._open;
  	return (*this);
}

std::string const &Object::getTitle() const {
	return _title;
}

bool 	const &Object::getOpen() const {
	return _open;
}

bool 	const &Object::getFull() const {
	return _full;
}

bool 	const &Object::getTaken() const {
	return _taken;
}

obj_type const	&Object::getType() const {
	return _type;
}

std::ostream &operator<<(std::ostream &os, Object *gift) {
	if (gift->getFull()){
		if (gift->getOpen())
			os << "Try to close the gift before sending it, or a child will be very sad..." << std::endl;
		else
			os << "The gift is ready to be sent to a kind child and it contains a " << gift->getTitle() << "." << std::endl;
	}
	else
		os << "Please fill the box before sending it.." << std::endl;
	return os;
}