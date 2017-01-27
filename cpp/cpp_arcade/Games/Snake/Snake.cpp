#include "Snake.hpp"
#include "Food.hpp"

Part::Part(int col,int row)
{
	x=col;
	y=row;
}

Part::Part()
{
	x=0;
	y=0;
}

Snake::Snake() {
	for (int i = 0; i < 4; i++)
		snake.push_back(Part(18+i, 18));
	direction = 'l';
	get = false;
	point = 0;
	delay = 110;
	width = 400;
	height = 400;
}

Snake::~Snake() {

}

void Snake::moveSnake() {
	if (!get && direction != 's') {
		last = snake.back();
		snake.pop_back();
	}
	if(direction == 'l')
		snake.insert(snake.begin(),Part(snake[0].x-1,snake[0].y));
	else if(direction == 'r')
		snake.insert(snake.begin(),Part(snake[0].x+1,snake[0].y));
	else if(direction == 'u')
		snake.insert(snake.begin(),Part(snake[0].x,snake[0].y-1));
	else if(direction == 'd')
		snake.insert(snake.begin(),Part(snake[0].x,snake[0].y+1));
}

void Snake::restart() {
	snake.clear();
	for (int i = 0; i < 4; i++)
		snake.push_back(Part(18+i, 18));
	direction = 'l';
	get = false;
	point = 0;
	delay = 110;	
}

bool 	Snake::collision(Food *food) {
	Part f;

	f = food->getFood();
	if(snake[0].x == 0 || snake[0].x == width / 10 - 1
		|| snake[0].y == 0 || snake[0].y == height / 10 - 1)
		return true;
	for (unsigned int i = 2; i < snake.size(); i++)
		if (snake[0].x == snake[i].x && snake[i].y == snake[0].y)
			return true;
	if (snake[0].x == f.x && snake[0].y == f.y) {
		get = true;
		delay -= 2;
		point += 10;
		while (1) {
			food->putFood();
			int tmpx = food->getFood().x;
			int tmpy = food->getFood().y;
			for(unsigned int i=0;i< snake.size();i++)
				if(snake[i].x == tmpx && snake[i].y == tmpy)
					continue;
			if(tmpx >= width / 10 - 2 || tmpy >= height / 10 - 3)
				continue;
			break;
		}
	}
	else
		get = false;
	return false;
}

void Snake::setDirection(const char &dir) {
	direction = dir;
}

void 	Snake::setWidth(int w) {
	width = w;
}

void 	Snake::setHeight(int h) {
	height = h;
}

void 	Snake::setDelay(int d) {
	delay = d;
}

std::vector<Part> Snake::getSnake() {
	return snake;
}

Part 			Snake::getLast() {
	return last;
}

const char &Snake::getDirection() const {
	return direction;
}

int 		Snake::getDelay() {
	return delay;
}

int 		Snake::getPoint() {
	return point;
}

int 		Snake::getHeight() {
	return height;
}