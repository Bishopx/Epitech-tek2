#include "GiftPaper.hh"

GiftPaper::GiftPaper(obj_type type) : Wrap(type) {
}

GiftPaper::~GiftPaper() {

}

GiftPaper::GiftPaper(GiftPaper & other) : Wrap(other._type)
{
	_full = other._full;
	_taken = other._taken;
	_open = other._open;	
}

GiftPaper &GiftPaper::operator=(GiftPaper &other)
{
	_type = other._type;
	_full = other._full;
	_taken = other._taken;
	_open = other._open;
  	return (*this);
}

void	GiftPaper::wrapMeThat(Object *obj) {
	if (obj->getType() == BOX) {
		if (_full == false) {
			_open = false;
			_title = obj->getTitle();
			std::cout << "tuuuut tuuut tuut" << std::endl;
			_full = true;
		} else
			std::cerr << "The gift is already ready to be sent" << std::endl;
	} else
		std::cerr << "You can only wrap Box with GiftPapers" << std::endl;
}
