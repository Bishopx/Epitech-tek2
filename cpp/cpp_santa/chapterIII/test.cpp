#include "Teddy.hh"
#include "LittlePony.hh"
#include "Box.hh"
#include "GiftPaper.hh"

Object **MyUnitTests() 
{
  Object **tab = new Object*;
  tab[0] = new LittlePony(LITTLEPONY, "gay pony");
  tab[1] = new Teddy(TEDDY, "bisounours");

  return (tab);
}

int 	sizeObj(Object **obj) {
	int i;

	i = 0;
	while (obj[i])
		i++;
	return (i);
}

Object **GetObjects() {
  	Object **obj = 	new Object*;	
	obj[0] =		new LittlePony(LITTLEPONY,"gay pony"),
	obj[1] =		new Box(BOX);
	obj[2] =		new GiftPaper(GIFTPAPER);
	return obj;
}

Object 				*MyUnitTests(Object **obj) {
	Object 			*gift;

	if (sizeObj(obj) != 6) {
      std::cerr << "Usage : tab[0] : Teddy, / LittlePony tab[1] : 1 Box, tab[2] : 1 GiftPaper" << std::endl;
      	return NULL;
	}
	if (obj[0]->getType() != LITTLEPONY && obj[0]->getType() != TEDDY)
		return NULL;
	
	if (obj[1]->getType() != BOX)
		return NULL;
	
	if (obj[2]->getType() != GIFTPAPER)
		return NULL;
	std::cout << "Prend Toy :";
	obj[0]->isTaken();
	std::cout << "Prend la box :";
	obj[1]->isTaken();
	obj[1]->closeMe();

	std::cout << "Wrap de la box avec le " << obj[0]->getTitle() << " :";
	obj[1]->wrapMeThat(obj[0]);
	obj[1]->wrapMeThat(obj[0]);
	obj[1]->closeMe();
	std::cout << "La box est-elle fermée ? : " << (obj[1]->getOpen() ? "Non" : "Oui") << std::endl;
	std::cout << "Prend le Papier Cadeau : ";
	obj[2]->isTaken();
	std::cout << "Wrap le Papier Cadeau : ";
	obj[2]->wrapMeThat(obj[1]);
	gift = obj[2];
	std::cout << "Le cadeau est-il fermé ? : " << (gift->getOpen() == false ? "Oui" : "Non") << std::endl;
	std::cout << "Le cadeau est-il rempli ? : " << (gift->getFull() == true ? "Oui" : "Non") << std::endl;
	return gift;
}


int main() {
	Object **o;
	Object *obj;

	o = GetObjects();
	if ((obj = MyUnitTests(o)) == NULL)
		return (-1);
	std::cout << obj;
	return 0;
}