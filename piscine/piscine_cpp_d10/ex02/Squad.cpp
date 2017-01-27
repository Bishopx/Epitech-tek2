#include "Squad.hh"
#include "TacticalMarine.hh"
#include "AssaultTerminator.hh"


Squad::Squad() {
	this->_count = 0;
	this->squad = new ISpaceMarine *;
}

int Squad::getCount() const {
	return this->_count;
}	

ISpaceMarine *Squad::getUnit(int unit) {

}

int 	Squad::push(ISpaceMarine *unit) {
	int i;

	i = 0;
	while (i < this->getCount())
		i++;
	std::cout << "Test";
	this->squad[i] = new ISpaceMarine;
	std::cout << "Test";
	this->squad[i] = unit;
	this->_count += 1; 
}

int main()
{
ISpaceMarine *ne = new TacticalMarine;
ISpaceMarine* bob = new TacticalMarine;
ISpaceMarine* jim = new AssaultTerminator;
ISquad* vlc = new Squad;

std::cout << vlc->getCount() << std::endl;

vlc->push(ne);
vlc->push(bob);
vlc->push(jim);
for (int i = 0; i < vlc->getCount(); ++i)
{
ISpaceMarine* cur = vlc->getUnit(i);
cur->battleCry();
cur->rangedAttack();
cur->meleeAttack();
}
delete vlc;
return 0;
}