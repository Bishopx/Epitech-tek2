#ifndef _LITTLEHAND_H_
#define _LITTLEHAND_H_

#include <iostream>
#include <string>
#include "FruitBox.h"
#include "Coconut.h"

class LittleHand {
public:
	LittleHand();
	~LittleHand();
	static void sortFruitBox(FruitBox& unsorted,
								FruitBox& lemons,
								FruitBox& bananas,
								FruitBox& limes);
	static FruitBox * const * organizeCoconut(Coconut const * const *);	
};

#endif