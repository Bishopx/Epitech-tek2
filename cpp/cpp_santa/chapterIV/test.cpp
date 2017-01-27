#include "Teddy.hh"
#include "LittlePony.hh"
#include "Box.hh"
#include "GiftPaper.hh"
#include "ConveyorBelt.hh"
#include "Table.hh"

int 	sizeObj(Object **obj) {
	int i;

	i = 0;
	while (obj[i])
		i++;
	return (i);
}

void 	aff_string(std::string *tab) {
	int i;

	i = 0;
	while (tab[i] != "") {
		std::cout << i + 1 << ") " << tab[i] << std::endl;
		i++;		
	}
}

Object **GetObjects() {
  	Object **obj = 	new Object*;	
	obj[0] =		new LittlePony(LITTLEPONY,"gay pony"),
	obj[1] =		new Box(BOX);
	obj[2] =		new GiftPaper(GIFTPAPER);
	return obj;
}

Object **MyUnitTests() 
{
  Object **tab = new Object*;
  tab[0] = new LittlePony(LITTLEPONY, "gay pony");
  tab[1] = new Teddy(TEDDY, "bisounours");

  return (tab);
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
	std::cout << "----- Building a GIFT -----" <<std::endl;
	std::cout << "Take the Toy :";
	obj[0]->isTaken();
	std::cout << "Take the box :";
	obj[1]->isTaken();
	obj[1]->closeMe();

	std::cout << "Wrap of the box with " << obj[0]->getTitle() << " :";
	obj[1]->wrapMeThat(obj[0]);
	obj[1]->wrapMeThat(obj[0]);
	obj[1]->closeMe();
	std::cout << "Is the Box closed ? : " << (obj[1]->getOpen() ? "No" : "Yes") << std::endl;
	std::cout << "Take the GiftPaper : ";
	obj[2]->isTaken();
	std::cout << "Wrap the GiftPaper : ";
	obj[2]->wrapMeThat(obj[1]);
	gift = obj[2];
	std::cout << "Is the gift closed ? : " << (gift->getOpen() == false ? "Yes" : "No") << std::endl;
	std::cout << "Is the Gift filled ? : " << (gift->getFull() == true ? "Yes" : "No") << std::endl;
	std::cout << gift;
	std::cout << "----------- END ----------" <<std::endl << std::endl;	
	return gift;
}

ITable 			*createTable() {
	ITable 		*table = new TablePePeNoel;
	int 		i;

	std::cout << "----- Table Building -----" <<std::endl;
	i = 0;	
	while (i < 2) {
		Object *t = new Teddy(TEDDY, "bisounours");
		Object *p = new LittlePony(LITTLEPONY, "gay pony");
		std::cout << "Putting a Teddy on the table" << std::endl;
		table->Put(t);
		std::cout << "Putting a LittlePony on the table" << std::endl;
		table->Put(p);
		i += 2;
	}
	std::cout << "----------- END ----------" <<std::endl << std::endl;	
	return table;
}

IConveyorBelt 	*createConveyorBelt() {
	IConveyorBelt *conveyor = new ConveyorBeltPePeNoel;
	Object 			**obj;
	int 			i;

	obj = new Object *;
	std::cout << "----- Conveyor Building -----" << std::endl; 
	i = 0;
	while (i < 4) {
		if (i % 2 == 0) {
			obj[i] = new Box(BOX);			
			std::cout << "Putting a box on the conveyor" << std::endl;
			conveyor->Put(obj[i], 1);
		} else {
			obj[i] = new GiftPaper(GIFTPAPER);
			std::cout << "Putting a giftpaper on the conveyor" << std::endl;
			conveyor->Put(obj[i], 1);
		}
		i++;
	}
	std::cout << "----------- END ----------" <<std::endl << std::endl;
	return conveyor;
}

int main() {

	IConveyorBelt *conveyor;
	ITable 			*table;
	Object 			**array_obj;
	Object 			*obj;
	std::string 	*tab;

	array_obj = GetObjects();
	if ((obj = MyUnitTests(array_obj)) == NULL)
		return (-1);
	table = createTable();
	conveyor = createConveyorBelt();
	table = table;
	
	tab = table->Look();
	std::cout << "Looking on the table : " << std::endl;
	aff_string(tab);
	tab = conveyor->Look();	
	std::cout << "Looking on the Conveyor : " << std::endl;
	aff_string(tab);
	obj = conveyor->In();
	obj = conveyor->Take();
	obj = conveyor->In();
	obj = conveyor->Take();	
	conveyor->Put(obj, 0);
	conveyor->Out(obj);
	tab = conveyor->Look();
	std::cout << "Looking on the Conveyor : " << std::endl;
	aff_string(tab);	

	obj = conveyor->In();
	obj = conveyor->Take();
	obj = conveyor->In();
	obj = conveyor->Take();
	conveyor->Put(obj, 0);	
	conveyor->Out(obj);
	tab = conveyor->Look();
	std::cout << "Looking on the Conveyor : " << std::endl;
	aff_string(tab);
	return 0;
}
