#ifndef _DO_FIND_HPP
#define _DO_FIND_HPP

#include <algorithm>
#include <iostream>
#include <string>

template<typename T>
typename T::iterator do_find(T &a, int b) {
	return (find(a.begin(), a.end(), b));
}

#endif