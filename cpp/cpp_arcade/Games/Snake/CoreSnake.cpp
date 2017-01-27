#include "Protocol.hpp"
#include "CoreSnake.hpp"

CoreSnake::CoreSnake(IGui *t) : s(new Snake), f(new Food), g(t) {
	srand(time(NULL));
	last_dir = 'l';
}

CoreSnake::~CoreSnake() {
	delete s;
	delete f;
}

void CoreSnake::drawGame() {
	std::string 		p;
	std::ostringstream 	convert;

	g->initDraw();
	convert << s->getPoint();
	p = convert.str();
	g->drawText(p, 0, s->getHeight());	
	g->drawRect(s->getLast().x* BLOCK, s->getLast().y* BLOCK,BLACK);		
	g->drawRect(f->getFood().x * BLOCK, f->getFood().y * BLOCK, PINK);
	for(unsigned int i = 0; i < s->getSnake().size(); i++)
		g->drawRect(s->getSnake()[i].x* BLOCK, s->getSnake()[i].y* BLOCK,GREEN);
	g->endDraw();
	usleep(s->getDelay() * 1000);
}

void CoreSnake::setDirection() {
	char dir;

	dir = g->HandleEvent();
	if (s->getDirection() !='r' && dir == 'l') {
		last_dir = dir;
		s->setDirection(dir);
	}
	else if (s->getDirection() !='l' && dir == 'r') {
		last_dir = dir;
		s->setDirection(dir);	
	}
	else if (s->getDirection() !='d' && dir == 'u') {
		last_dir = dir;
		s->setDirection(dir);
	}
	else if (s->getDirection() !='u' && dir == 'd') {
		last_dir = dir;
		s->setDirection(dir);
	}
	else if (dir == 'p') {
		last_dir = 'p';
		s->setDirection('p');
	}
	else if (dir != 'r' && dir != 'l' && dir != 'u' && dir != 'd' && dir != '\0')
		s->setDirection(dir);	
}

char CoreSnake::PlayGame() {
	while (1) {
		s->setDirection(last_dir);
		if (s->collision(f) || s->getDirection() == 's') {
			return ('g');
		}
		drawGame();
		setDirection();
		if (s->getDirection() == '2' || s->getDirection() == '3' || s->getDirection() == '4' || s->getDirection() == '5')
			return (s->getDirection());		
		if (s->getDirection() == 'q') {
			return ('q');
		}
		s->setDirection(last_dir);					
		if (s->getDirection() != 'p') {
			s->moveSnake();
		}
	}
}

int 	CoreSnake::getPoint() const{
	return (s->getPoint());
}

void CoreSnake::setGui(IGui *gui) {
	g = gui;
}

extern "C" {
	IGame *create_game(IGui *t)
	{
		return new CoreSnake(t);
	}
}