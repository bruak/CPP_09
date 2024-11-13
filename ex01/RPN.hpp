#pragma once 
#include <iostream>
#include <stack>
#include <string>
#include <sstream>

#define DIV_BY_ZERO "Error: Division by zero"
#define INVALID_TOKEN "Invalid token: "
#define NOT_ENOUGH_OPERANDS "Not enough operands for operator: "
#define INVALID_OPERATOR "Invalid operator: "
#define INVALID_EXPRESSION "Invalid RPN expression"
#define ARG_ERROR "Error: invalid number of arguments"

class RPN {

	public:
		RPN(const std::string &);
		~RPN();
		RPN& operator=(const RPN &);
		RPN(const RPN &);
		void calculate(const std::string &);
		void StringToNumber(const std::string &token);
		int giveTopAndPop();
		void Calculate(int a, int b, char op);
		bool ValidationCheck(const std::string &token);
		bool isOperator(const std::string &token);
		bool isNumber(const std::string &token);

	private:
		std::stack<int> _stack;
};