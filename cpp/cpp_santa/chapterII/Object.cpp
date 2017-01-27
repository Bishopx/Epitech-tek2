#include "Object.hh"

Object::Object() : _taken(false), _title("") {

}

Object::~Object() {
	std::cout << "Et les jouets ne sont plus" << std::endl;
}

std::string const &Object::getTitle() const {
	return _title;
}