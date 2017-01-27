#include "Protocol.hpp"
#include "CoreFox.hpp"

CoreFox::CoreFox(IGui *t) : 
player(new Player), enemy(new Enemy), up(new Powerup), gui(t) 
{
	srand(time(NULL));
	last_dir = 'l';
}

CoreFox::~CoreFox() {
	delete player;
	delete enemy;
	delete up;
}

void CoreFox::drawGame() {
	std::string 		p;
	std::ostringstream 	convert;
	std::vector<Part> 	last, pu, elb;
	std::vector<EPart> 	en, eb;
	Part 				pb, lpb, ePw;

	last = enemy->getEnemyLast();
	en = enemy->getEnemy();
	eb = enemy->getEnemyBullet();
	elb = enemy->getEnemyLastBullet();
	pu = up->getPowerup();
	pb = player->getBullet();
	lpb = player->getLastBullet();
	ePw = player->getEatPowerUp();

	gui->initDraw();
	convert << player->getPoint();
	p = convert.str();
	//enemy last
	for (unsigned int i = 0; i < last.size(); i++)
		gui->drawRect(last[i].x * BLOCK, last[i].y * BLOCK, BLACK);
	//enemy
	for (unsigned int i = 0; i < en.size(); i++)
		gui->drawRect(en[i].x * BLOCK, en[i].y * BLOCK, BLUE);
	//Enemy last bullet
	for (unsigned int i = 0; i < elb.size(); i++)
			gui->drawRect(elb[i].x * BLOCK, elb[i].y * BLOCK, BLACK);
	//enemy bullets
	for (unsigned int i = 0; i < eb.size(); i++)
		gui->drawRect(eb[i].x * BLOCK, eb[i].y * BLOCK, RED);
	//last player bullet
	gui->drawRect(lpb.x * BLOCK, lpb.y * BLOCK, BLACK);
	//player bullet
	gui->drawRect(pb.x * BLOCK, pb.y * BLOCK, WHITE);
	//power up eat
	gui->drawRect(ePw.x * BLOCK, ePw.y * BLOCK, BLACK);
	gui->drawText(p, 0, player->getHeight());	
	gui->drawRect(player->getLast().x* BLOCK, player->getLast().y* BLOCK,BLACK);		
	//power up
	for (unsigned int i = 0; i < pu.size(); i++){
		// if (pu[i].x == ePw.x && pu[i].y == ePw.y)
		// 	gui->drawRect(pu[i].x * BLOCK, pu[i].y * BLOCK, BLACK);
		// else 
			gui->drawRect(pu[i].x * BLOCK, pu[i].y * BLOCK, BLUE);

	}
	gui->drawRect(player->getPlayer().x* BLOCK, player->getPlayer().y* BLOCK,GREEN);
	gui->endDraw();
	usleep(player->getDelay() * 1000);
}

void CoreFox::setDirection() {
	char dir;

	dir = gui->HandleEvent();
	if (player->getDirection() !='r' && dir == 'l') {
		last_dir = dir;		
		player->setDirection(dir);
	}
	if (player->getDirection() !='l' && dir == 'r') {
		last_dir = dir;		
		player->setDirection(dir);	
	}
	if (player->getDirection() !='d' && dir == 'u') {
		last_dir = dir;		
		player->setDirection(dir);
	}
	if (player->getDirection() !='u' && dir == 'd') {
		last_dir = dir;		
		player->setDirection(dir);
	}
	if (dir != 'r' && dir != 'l' && dir != 'u' && dir != 'd' && dir != '\0')
		player->setDirection(dir);	
}

char CoreFox::PlayGame() {
	while (1) {
		player->setDirection(last_dir);		
		if (player->collision(up, enemy) || player->getDirection() == 's') {
			return ('g');
		}
		drawGame();
		setDirection();
		if (player->getDirection() == '2' || player->getDirection() == '3' || player->getDirection() == '4' || player->getDirection() == '5')
			return (player->getDirection());		
		if (player->getDirection() == 'q') {
			return ('q');
		}
		if (player->getDirection() != 'p'){
			player->setDirection(last_dir);
			player->movePlayer();
			player->shoot();
			enemy->move();
			enemy->shoot(player->getPlayer());
			enemy->moveShoot();
		}
	}
}

int CoreFox::getPoint() const {
	return (player->getPoint());
}

void CoreFox::setGui(IGui *_gui) {
	gui = _gui;
}

extern "C" {
	IGame *create_game(IGui *t)
	{
		return new CoreFox(t);
	}
}