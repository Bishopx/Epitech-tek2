#ifndef _EX03_HPP_
#define _EX03_HPP_

#include <iostream>
#include <string>

template<typename U>
void print(const U &a) {
	std::cout << a << std::endl;
}

template<typename T>
void foreach(T *a, void (&print)(const T &a), int size) {
	int i = 0;

	while (i < size) {
		print(a[i]);
		i++;
	}
}

#endif