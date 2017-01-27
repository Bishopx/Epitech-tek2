#ifndef _EX05_HPP_
#define _EX05_HPP_

#include <iostream>
#include <string>

template<class T>
class			array {
private:
	int 		size;
	int 		number;
	array 		**store;
public:
	array<T>() : size(0), number(0), store(NULL){

	}
	array<T>(unsigned int n) {
		int i = 0;
		this->store = new array *[n];

		this->size = n;
		while (i < n) {
			this->store[i] = new array;
			this->store[i]->number = 0;
			i++;
		}
	}
	const array<T> &operator=(array const &other) {
		size = other.size;
		number = other.number;
		store = other.store;
		return *this;
	}

	T &operator[](int i) const {
          if( i > this->size )
          {
              // return first element.
              return this->store[0]->number;
          }
          return this->store[i]->number;
  	}	




};

#endif