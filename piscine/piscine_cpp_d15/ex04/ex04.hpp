#ifndef _EX04_HPP
#define _EX04_HPP

#include <iostream>
#include <string>

template<typename T>
bool equal(const T &a,const T  &b);

template<class T>
class			Tester {
public:
	bool equal(const T &, const T &);
};

#endif