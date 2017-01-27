#ifndef __TOYSTORY_H__
#define __TOYSTORY_H__

#include <string>
#include <fstream>

#include "Toy.h"

typedef bool (Toy::*toy_func)(std::string const message);

class ToyStory {
public:
	ToyStory();
	~ToyStory();

	static bool tellMeAStory(std::string const & filename, Toy & character1, bool (Toy::*)(const std::string&), Toy & character2, bool (Toy::*)(const std::string&));

};

#endif