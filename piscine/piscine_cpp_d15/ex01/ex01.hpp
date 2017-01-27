#ifndef _EX01_HPP_
#define _EX01_HPP_

template<typename T>
int compare(T const &a, T const &b) {
	if (a == b)
		return 0;
	else if (a < b)
		return -1;
	else
		return 1;
}

#endif