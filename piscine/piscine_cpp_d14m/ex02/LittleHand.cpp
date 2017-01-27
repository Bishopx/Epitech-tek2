#include "LittleHand.h"
#include "Lemon.h"
#include "Banana.h"
#include "Lime.h"
#include "FruitBox.h"
#include "Coconut.h"

LittleHand::LittleHand() {

}

LittleHand::~LittleHand() {

}

void LittleHand::sortFruitBox(FruitBox& unsorted,
	FruitBox& lemons,FruitBox& bananas, FruitBox& limes) {

	FruitNode *uns = unsorted.head();
	while (uns) {
		if (uns->_fruit->getName() == "lemon") {
			if (lemons.putFruit(uns->_fruit)) {
				unsorted.pickFruit();
			}
		}
		if (uns->_fruit->getName() == "lime") {
			if (limes.putFruit(uns->_fruit)) {
				unsorted.pickFruit();
			}
		}
		if (uns->_fruit->getName() == "banana") {
			if (bananas.putFruit(uns->_fruit)) {
				unsorted.pickFruit();
			}
		}
		uns = uns->next;
	}
}

int sizeOfCoconut(Coconut const * const * coconut) {
	int i = 0;

	while (coconut[i])
		i++;
	return i;
}

FruitBox * const * LittleHand::organizeCoconut(Coconut const * const * coconuts_packet) {
	FruitBox **b 	= new FruitBox *[sizeOfCoconut(coconuts_packet) / 5 + 1];
	int 		i 	= 0;
	int 		j 	= 0;
	int 		k 	= 0;

	while (i < sizeOfCoconut(coconuts_packet) / 6 + 1) {
		j = 0;
		b[i] = new FruitBox(6);		
		while (j < 6 && k < sizeOfCoconut(coconuts_packet)) {
			b[i]->putFruit(const_cast<Coconut *>(coconuts_packet[k]));
			j++;
			k++;
		}
		i++;
	}
	b[i] = NULL;
	return b;
}