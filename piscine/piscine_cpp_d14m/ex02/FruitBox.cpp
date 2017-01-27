#include "FruitBox.h"

FruitBox::FruitBox(int size) : _size(size), _nbFruits(0), _head(NULL) {
}

FruitBox::~FruitBox() {

}

int 		FruitBox::nbFruits() const {
	return _nbFruits;
}	

Fruit 		*FruitBox::pickFruit() {
	Fruit 	*fruit;

	if (_nbFruits > 0) {
		fruit = _head->_fruit;
		FruitNode *cur = _head;
		_head = cur->next;
		_nbFruits--;
		return fruit;
	} else
		return NULL;
}

FruitNode 	*FruitBox::head() const {
	if (_nbFruits > 0)
		return _head;
	else
		return NULL;
}

bool 		FruitBox::putFruit(Fruit *fruit) {
	FruitNode *fruitNode = new FruitNode;

	fruitNode->_fruit = fruit;
	fruitNode->next = NULL;
	if (_nbFruits == 0) {
		_head = fruitNode;
		_nbFruits++;
		return true;
	}
	else if (_nbFruits < _size) {
		fruitNode->_fruit = fruit;
		fruitNode->next = NULL;

		FruitNode *cur = _head;
		while(cur) {
			if (fruitNode->_fruit == cur->_fruit)
				return false;
			if(cur->next == NULL) {
				cur->next = fruitNode;
				_nbFruits++;
				return true;
			}
			cur = cur->next;
		}
		return true;			
	}
	else {
		return false;	
	}
}

bool FruitBox::alreadyExist(Fruit *fruit) {
	FruitNode *list = _head;
	while(list) {
		if (list->_fruit == fruit)
			return false;
		list = list->next;
	}
	return true;
}

void FruitBox::display() {
	FruitNode *list = _head;
	while(list) {
		std::cout << list->_fruit->getName() << " ";
		list = list->next;
	}
	std::cout << std::endl;
}
