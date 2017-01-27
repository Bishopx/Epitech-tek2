#ifndef _PARSER_H_
#define _PARSER_H_

# include <stack>
# include <string>
# include <iostream>
# include <vector>
#include <sstream>

class Parser {
private:
	int 					_result;
	std::stack<int> 		_stack;
	std::stack<char> 		_stack_op;

public:
	Parser();
	~Parser();
	void 	feed(const std::string &);
	int 	result() const;
	void 	reset();
};

#endif