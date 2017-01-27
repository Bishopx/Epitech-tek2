#include "Table.hh"

ITable::~ITable()
{}

TablePePeNoel::TablePePeNoel() : free(0), _obj(new Object *), _index(0)
{
}

TablePePeNoel::~TablePePeNoel()
{}

TablePePeNoel::TablePePeNoel(TablePePeNoel const &t)
{
    this->free = t.free;
    this->_obj = t._obj;
    this->_index = t._index;
}

TablePePeNoel &TablePePeNoel::operator=(TablePePeNoel const &oldPepe)
{
    if (this != &oldPepe) {
      free = oldPepe.free;
      _obj = oldPepe._obj;
      _index = oldPepe._index;
    }
    return *this;
}

void TablePePeNoel::Put(Object * const &obj)
{
	obj->isTaken();
	if (obj->getTaken() == true)
	{
	   _obj[_index] = obj;
	   _index++;
	   obj->setTaken(false);
	}
	 else
	    std::cerr << "The elf doesn't have an object with him" << std::endl;
}

std::string 		*TablePePeNoel::Look() {
	std::string 	*tab = new std::string[sizeObj(_obj) + 1];
	int 			i;

	i = 0;
	while (i < sizeObj(_obj)) {
		tab[i] = _obj[i]->getTitle();
		i++;
	}
	tab[i] = "";
	return tab;
}