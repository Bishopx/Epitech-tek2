#include "Food.hpp"

Food::Food() {
	while (1) {
		food = Part(rand() % WIDTH / 10 + 1, rand() % HEIGHT / 10 + 1);
		if(food.x >= WIDTH / 10 - 2 || food.y >= HEIGHT / 10 - 3)
			continue;
		break;
	}
}

Food::~Food() {

}

void Food::putFood() {
	food = Part(rand() % WIDTH / 10 + 1, rand() % HEIGHT / 10 + 1);
}

Part const &Food::getFood() const {
	return food;
}
