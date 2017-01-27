#include "LittleHand.h"
#include "Lemon.h"
#include "Banana.h"
#include "Lime.h"
#include "FruitBox.h"

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