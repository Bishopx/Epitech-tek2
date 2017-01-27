#ifndef _EX02_HPP_
#define _EX02_HPP_

#include <iostream>
#include <string>

template<typename T>
T min(T a, T b) {
	std::cout << "template min" << std::endl;
	if (a <= b)
		return a;
	else
		return b;
}

int min(int a, int b) {
	std::cout << "non-template min" << std::endl;
	if (a <= b)
		return a;
	else
		return b;	
}

template<typename T>
T templateMin(T *tab, int size) {
	int i = 1;
	T ret = tab[0];

	while (i < size)
	{
		ret = min<T>(ret, tab[i]);
		i++;
	}
	return ret;
}

int nonTemplateMin(int *tab, int size) {
	int i = 1;
	int ret = tab[0];

	while (i < size)
	{
		ret = min(ret, tab[i]);
		i++;
	}
	return ret;
}

#endif