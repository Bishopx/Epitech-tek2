#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <iostream>
#include <string>

class Object {
protected:
	bool _taken;
	std::string _title;
public:
	Object();
	virtual ~Object();
	virtual void isTaken() = 0;
	std::string const &getTitle() const;
};

#endif /* _OBJECT_H_ */