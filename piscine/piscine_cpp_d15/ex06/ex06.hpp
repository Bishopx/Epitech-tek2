#ifndef _EX06_H_
#define _EX06_H_

#include <iostream>
#include <string>
#include <sstream>


template<typename T>
std::string str(T a) {
	a = a;
	return ("???");
}

template<>
std::string str(int a) {
	std::stringstream oss;

	oss << "int:" << a;
	return (oss.str());
}

template<>
std::string str(float a) {
	std::stringstream oss;

	oss << "float:" << a << "f";
	return (oss.str());
}

template<>
std::string str(std::string a) {
	std::stringstream oss;

	oss << "string:\"" << a << "\"";
	return (oss.str());
}

template<class T, class U = T>
class			Tuple {
public:
	T 	a;
	U 	b;

	std::string 	toString() {
		return ("[TUPLE [" + str(a) + "] [" + str(b) + "]]");
	}
};

// template<> class Tuple<int> { static const char* name() {return "int";} };
#endif