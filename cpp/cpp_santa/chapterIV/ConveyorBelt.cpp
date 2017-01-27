#include "ConveyorBelt.hh"

IConveyorBelt::~IConveyorBelt()
{}

ConveyorBeltPePeNoel::ConveyorBeltPePeNoel() : free(1), _obj(new Object *), _index(0)
{}

ConveyorBeltPePeNoel::~ConveyorBeltPePeNoel()
{}

ConveyorBeltPePeNoel::ConveyorBeltPePeNoel(ConveyorBeltPePeNoel const &c)
{
    this->free = c.free;
    this->_obj = c._obj;
    this->_index = c._index;
}

ConveyorBeltPePeNoel& ConveyorBeltPePeNoel::operator=(ConveyorBeltPePeNoel const &oldPepe)
{
    if (this != &oldPepe) {
      free = oldPepe.free;
      _obj = oldPepe._obj;
    }
    return *this;
}

void 	ConveyorBeltPePeNoel::Put(Object * const &obj, int type)
{
    if (free == true)
    {
        _obj[_index] = obj;
        if (type == 1)
        	_index += 1;
        else
        	free = false;
    }
}

Object *ConveyorBeltPePeNoel::Take() {
	if (free == false) {
		free = true;
		return _obj[_index];
	} else {
		std::cout << "There is nothing to take on the Conveyor" << std::endl;
		return NULL;
	}
}

Object *ConveyorBeltPePeNoel::In() {
	Object *obj;

	if (free == true) {
		if (_index > 0) {
			free = false;
			obj = _obj[_index - 1];
			_index -= 1;
			return (obj);
		} else {
			std::cerr << "There is no more Wrap on the Conveyor" << std::endl;
			return NULL;
		}
	} else {
		std::cerr << "There is already a Wrap on the Conveyor" << std::endl;
		return NULL;
	}
}

void 	ConveyorBeltPePeNoel::Out(Object *obj) {
	if (free == false) {
		std::cout << "Sending gift : " << obj->getTitle() << std::endl;
		free = true;
	}
}

std::string 		*ConveyorBeltPePeNoel::Look() {
	std::string 	*tab = new std::string[_index + 1];
	int 			i;

	i = 0;
	while (i < _index) {
		tab[i] = (_obj[i]->getType() == 4 ? "Box" : "GifPaper");
		i++;
	}
	tab[i] = "";
	return tab;
}
