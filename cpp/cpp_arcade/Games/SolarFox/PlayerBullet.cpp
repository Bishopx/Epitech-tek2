#include "PlayerBullet.hpp"

PlayerBullet::PlayerBullet(char d, int x, int y){
	dir = d;

	if (dir == 'l')
		bullet = Part(x-1, y);
	if (dir == 'r')
		bullet = Part(x+1, y);
	if (dir == 'd')
		bullet = Part(x, y+1);
	if (dir == 'u')
		bullet = Part(x, y-1);
	// move();
}

PlayerBullet::~PlayerBullet(){

}

void 	PlayerBullet::move(){
	lastBullet = bullet;
	if (bullet.x == lastBullet.x+2)
		bullet = lastBullet;
	if (dir == 'l') {
		bullet.x -= 2;
	}
	else if (dir == 'r') {
		bullet.x += 2;
	}
	else if (dir == 'd') {
		bullet.y += 2;
	}
	else if (dir == 'u') {
		bullet.y -= 2;
	}
}

Part const &PlayerBullet::	getBullet() const{
	return bullet;
}
Part const &PlayerBullet::getLastBullet() const{
	return lastBullet;
}