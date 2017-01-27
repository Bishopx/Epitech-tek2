#ifndef _FRUITNODE_H_
#define _FRUITNODE_H_

#include "Fruit.h"

typedef struct FruitNode {
	Fruit 		*_fruit;
	FruitNode 	*next;
} 				FruitNode;

#endif