#ifndef ABSTRACTVM_HPP
#define ABSTRACTVM_HPP
#include <iostream>
#include <deque>
#include "Lexer.hpp"
#include "IOperand.hpp"
#define NO_ARGS 1
	// actions[Push] = Parser::push;
	// actions[Pop] = Parser::pop;
	// actions[Dump] = Parser::dump;
	// actions[Assert] = Parser::assert;
	// actions[Add] = Parser::add;
	// actions[Sub] = Parser::sub;
	// actions[Mul] = Parser::mul;
	// actions[Div] = Parser::div;
	// actions[Mod] = Parser::mod;
	// actions[Print] = Parser::print;
	// actions[Exit] = Parser::exit;
class AbstractVM{
	public:
		AbstractVM() : lexer(std::cin) { } //TODO: read from file
		~AbstractVM() {}
		void run(std::string fileName = std::string());
	private:
		Lexer lexer;
		//Parser parser;
		std::deque<IOperand*> _operands;

};

#endif