#ifndef _FRUITBOX_H_
#define _FRUITBOX_H_

#include <iostream>
#include <string>
#include "FruitNode.h"

class FruitBox {
private:
	FruitBox(FruitBox const &);		
protected:
	int 		_size;
	int 		_nbFruits;
	FruitNode 	*_head;
public:
	FruitBox(int);
	~FruitBox();
	int 		nbFruits() const;
	bool 		putFruit(Fruit *);
	Fruit 		*pickFruit();
	FruitNode 	*head() const;
	void 		display();
	bool 		alreadyExist(Fruit *);
};

#endif