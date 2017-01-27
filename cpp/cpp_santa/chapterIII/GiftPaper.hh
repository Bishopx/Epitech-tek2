#ifndef _GIFTPAPER_H_
#define _GIFTPAPER_H_

#include <iostream>
#include <string>
#include "Wrap.hh"

class GiftPaper : public Wrap
{
public:
	GiftPaper(obj_type);
	virtual ~GiftPaper();
  	GiftPaper(GiftPaper &);
  	GiftPaper &operator=(GiftPaper &);		
	virtual void wrapMeThat(Object *);
};

#endif /* !_GIFTPAPER_H_ */