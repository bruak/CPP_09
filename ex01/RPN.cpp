#include "RPN.hpp"


RPN::RPN(const std::string &input) {
	calculate(input);
}

RPN::~RPN() {

}

RPN& RPN::operator=(const RPN &other) {
	if (this != &other) {
		_stack = other._stack;
	}
	return *this;
}

RPN::RPN(const RPN &other) {
	*this = other;
}

bool RPN::isNumber(const std::string &token) {
	return token.length() == 1 && std::isdigit(token[0]);
}

bool RPN::isOperator(const std::string &token) {
	return token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/');
}

bool RPN::ValidationCheck(const std::string &token) {
	return isNumber(token) || (token.length() == 1 && isOperator(token));
}

void RPN::StringToNumber(const std::string &token) {
	_stack.push(token[0] - '0');
}

int RPN::giveTopAndPop() {
	int top = _stack.top();
	_stack.pop();
	return top;
}

void RPN::Calculate(int a, int b, char op) {
	if (b == 0 && op == '/')
		throw std::invalid_argument(DIV_BY_ZERO);
	switch (op) {
		case '+': _stack.push(b + a); break;
		case '-': _stack.push(b - a); break;
		case '*': _stack.push(b * a); break;
		case '/': _stack.push(b / a); break;
		default : throw std::invalid_argument(INVALID_OPERATOR + op);
	}
}

void RPN::calculate(const std::string &RpnValue) {
	std::istringstream iss(RpnValue);
	std::string token;

	while (iss >> token) {
		if (!ValidationCheck(token))
			throw std::invalid_argument(INVALID_TOKEN + token);

		if (isNumber(token)) 
			StringToNumber(token);
		else if (isOperator(token)){
			if (_stack.size() < 2)
				throw std::invalid_argument(NOT_ENOUGH_OPERANDS + token);
			int a = giveTopAndPop();
			int b = giveTopAndPop();
			Calculate(a, b, token[0]);
		}
	}
	if (_stack.size() != 1)
		throw std::invalid_argument(INVALID_EXPRESSION);
	std::cout << _stack.top() << std::endl;
}