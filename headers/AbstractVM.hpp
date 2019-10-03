#ifndef ABSTRACTVM_HPP
#define ABSTRACTVM_HPP
#include <iostream>
#include <deque>
#include "Lexer.hpp"
#include "IOperand.hpp"
#define NO_ARGS 1

class AbstractVM{
	public:
		AbstractVM() : lexer(std::cin) { } //TODO: read from file
		~AbstractVM() {}
		void launch(std::string fileName = std::string());
	private:
		Lexer lexer;
		//Parser parser;
		std::deque<IOperand*> _operands;

};

#endif