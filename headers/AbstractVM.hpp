#ifndef ABSTRACTVM_HPP
#define ABSTRACTVM_HPP
#include <iostream>
#include <deque>
#include "IOperand.hpp"

class AbstractVM{
	private:
	Lexer lexerVM;
	Parser parserVM;
	std::deque<IOperator*>;
};

#endif