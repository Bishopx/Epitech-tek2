#include "Parser.h"

bool Operator(char input) {
	char ops[] = {'-', '+', '*', '/', '%'};
	for (int i = 0; i < 5; i++) {
		if (input == ops[i])
			return true;
	}
	return false;
}	

int calcul(int result, int a, int b, char c) {
	if (c == '%')
		result = a % b;
	else if (c == '/')
		result = a / b;
	else if (c == '+')
		result = a + b;
	else if (c == '-')
		result = a - b;
	else if (c == '*')
		result = a * b;
	return result;
}

std::string ReplaceAll(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

Parser::Parser() : _result(0) {
}

Parser::~Parser() {

}

void Parser::feed(const std::string &feed) {
	int i = 0, n = 0, a = 0, b = 0;
	std::string sup_space;

	sup_space = ReplaceAll(feed, " ", "");
	while (sup_space[i]) {
		if (sup_space[i] >= '0' && sup_space[i] <= '9') {
			n = sup_space[i] - 48;
			while (sup_space[i + 1] >= '0' && sup_space[i + 1] <= '9') {
				n = n * 10 + (sup_space[i + 1] - 48);
				i++;
			}
			_stack.push(n);
		}
		if (Operator(sup_space[i])) {
			_stack_op.push(sup_space[i]);
		}
		if (sup_space[i] == ')' || sup_space[i] == sup_space[sup_space.size()]) {
			b = _stack.top();
			_stack.pop();
			a = _stack.top();
			_stack.pop();
			_result = calcul(_result, a, b, _stack_op.top());
			_stack.push(_result);
			_stack_op.pop();
		}
		i++;
	}
	if (_stack.size() == 1) {
		_stack_op.push('+');
	}
	if (_stack_op.size() > 0 && _stack.size() > 1) {
		b = _stack.top();
		_stack.pop();
		a = _stack.top();
		_stack.pop();
		_result = calcul(_result, a, b, _stack_op.top());
		_stack.push(_result);
		_stack_op.pop();		
	}
}

int 	Parser::result() const {
	return _result;
}

void 	Parser::reset() {
	_result = 0;
	_stack.pop();
}