#include "Toy.hh"

Toy::Toy() : Object() {

}

Toy::~Toy() {
	std::cout << "Et les jouets ne sont plus" << std::endl;
}

Teddy::Teddy(std::string const &t) : Toy() {
	_title = t;
	std::cout << "Bonjour je suis un nounours et je m'appelle " << t << std::endl;
}

void	Teddy::isTaken() {
	_taken = true;
	std::cout << "gra hu" << std::endl;
}

LittlePony::LittlePony(std::string const &t) : Toy() {
	_title = t;
	std::cout << "Bonjour je suis un petit poney et je m'appelle " << t << std::endl;
}

void	LittlePony::isTaken() {
	_taken = true;
	std::cout << "yo man" << std::endl;
}

Object **MyUnitTests() {
	Object **obj = new Object *;
	obj[0] =	new Teddy("bisounours"),
	obj[1] =	new LittlePony("test");

	return obj;
}

int main() {
	Object **o;

	o = MyUnitTests();
	o[1]->isTaken();
	return 0;
}