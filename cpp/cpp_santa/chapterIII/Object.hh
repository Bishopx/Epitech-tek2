#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <iostream>
#include <string>

enum 	obj_type {
	NONE,
	LITTLEPONY,
	TEDDY,
	BOX,
	GIFTPAPER
};

class Object {
protected:
	std::string _title;
	obj_type	_type;
	bool 		_taken;
	bool 		_open;
	bool 		_full;
public:
	Object(obj_type, std::string const &);
	Object(obj_type);
	virtual ~Object();
  	Object(Object &);
  	Object &operator=(Object &);
  	virtual void isTaken() = 0;
	virtual void openMe() {}
	virtual void wrapMeThat(Object *) {}
	virtual void closeMe() {}
	std::string const &getTitle() const;
	bool 		const &getOpen() const;
	bool 		const &getFull() const;
	bool 		const &getTaken() const;
	obj_type 	const &getType() const;
};

std::ostream &operator<<(std::ostream &, Object *);

#endif /* _OBJECT_H_ */