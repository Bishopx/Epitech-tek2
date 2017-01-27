#include "Powerup.hpp"

Part::Part(int col,int row)
{
	x = col;
	y = row;
}

Part::Part()
{
	x = 0;
	y = 0;
}

Powerup::Powerup() {
	 for (int i = 6; i < 34; i += 2) {
        for (int y = 6; y < 35; y += 2){
            powerup.push_back(Part(i, y));
        }    
    }
}

Powerup::~Powerup() {

}


std::vector<Part> const &Powerup::getPowerup() const {
	return powerup;
}
void 					Powerup::removePowerUp(int i){
	powerup.erase(powerup.begin() + i);
}