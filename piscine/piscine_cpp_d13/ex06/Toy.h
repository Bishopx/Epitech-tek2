#ifndef _TOY_H_
#define _TOY_H_

#include "Picture.h"

class Toy {
public:
	class Error {
	public:
		enum ErrorType {
			UNKNOWN,
			PICTURE,
			SPEAK
		};
		ErrorType type;
	public:
		std::string what() const;
		std::string where() const;

	};

public:
	enum ToyType {
		BASIC_TOY,
		ALIEN,
		WOODY,
		BUZZ
	};
protected:
	ToyType 	type;
	std::string name;
	Picture 	picture;
	Error::ErrorType 	error;
public:
	Toy();
	Toy(ToyType const&type, std::string const &name, std::string const &file);
	~Toy();
	Toy(Toy const &);
	Toy &operator=(Toy const &);
	void operator<<(std::string const &);
public:
	ToyType const 		&getType() const;
	std::string const 	&getName() const;
	std::string const 	&getAscii() const;

	Toy::Error 			getLastError() const;
	void 				setName(std::string const &);
	bool 				setAscii(std::string const &);
	virtual bool 		speak_es(std::string const &);
	virtual bool 		speak(std::string const &statement);
};


std::ostream &operator<<(std::ostream &, Toy const &);

#endif