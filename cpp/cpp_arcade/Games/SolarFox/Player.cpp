#include "Player.hpp"
#include "Powerup.hpp"

Player::Player() {
	player = Part(18, 18);
	direction = 'l';
	count = 1;
	get = false;
	point = 0;
	delay = 100;
	width = 400;
	height = 400;
}

Player::~Player() {

}

void Player::movePlayer() {
	last = player;
	if(direction == 'l')
		player.x -= 1;
	else if(direction=='r')
		player.x += 1;
	else if(direction=='u')
		player.y -= 1;
	else if(direction=='d')
		player.y += 1;
	else if(direction=='s')
		shoot();
}

void Player::restart() {
	player = Part(21, 21);
	direction = 'l';
	get = false;
	point = 0;
	delay = 110;	
}

bool 	Player::collision(Powerup *up, Enemy *enemy) {
	std::vector<Part> f;
	std::vector<EPart> eb;

	f = up->getPowerup();
	eb = enemy->getEnemyBullet();
	for (unsigned int i = 0; i < f.size(); i ++){
		if(player.x == 0 || player.x == width / 10 - 1
			|| player.y == 0 || player.y == height / 10 - 1)
			return true;
		if (bullet.x == f[i].x && bullet.y == f[i].y) {
			get = true;
			// delay -= 2;
			eatPowerUp = bullet;
			point += 10;
			up->removePowerUp(i);
			// count = 1;
		}
		else	
			get = false;
	}
	for (unsigned int i = 0; i < eb.size(); i++) {
		if (player.x == eb[i].x && player.y == eb[i].y)
			return true;
	}
	return false;
}


void Player::shoot() {
	lastBullet = bullet;
	if (direction == 'l'){
		bullet.x = player.x-count;
		bullet.y = player.y;
	}
	if (direction == 'r'){
		bullet.x = player.x+count;
		bullet.y = player.y;
	}
	if (direction == 'd'){
		bullet.x = player.x;
		bullet.y = player.y+count;
	}
	if (direction == 'u'){
		bullet.x = player.x;
		bullet.y = player.y-count;
	}
	if (count < 2)
		count+= 1;
	else
		count = 1;
}

Part const  &Player::getBullet() const{
	return bullet;
}

Part const  &Player::getLastBullet() const{
	return lastBullet;
}
Part const &Player::getEatPowerUp() const {
	return eatPowerUp;
}
void 		Player::moveBullet(){
	lastBullet = bullet;
	if (bullet.x == lastBullet.x+2)
		bullet = lastBullet;
	if (direction == 'l') {
		bullet.x -= 2;
	}
	else if (direction == 'r') {
		bullet.x += 2;
	}
	else if (direction == 'd') {
		bullet.y += 2;
	}
	else if (direction == 'u') {
		bullet.y -= 2;
	}
}

void Player::setDirection(const char &dir) {
	direction = dir;
}

void 	Player::setWidth(int w) {
	width = w;
}

void 	Player::setHeight(int h) {
	height = h;
}

void 	Player::setDelay(int d) {
	delay = d;
}

Part Player::getPlayer() {
	return player;
}

Part 			Player::getLast() {
	return last;
}

const char &Player::getDirection() const {
	return direction;
}

int 		Player::getDelay() {
	return delay;
}

int 		Player::getPoint() {
	return point;
}

int 		Player::getHeight() {
	return height;
}

int 		Player::getPartX() {
	return player.x;
}

int 		Player::getPartY() {
	return player.y;
}