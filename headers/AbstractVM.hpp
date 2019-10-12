#ifndef ABSTRACTVM_HPP
#define ABSTRACTVM_HPP
#include <iostream>
#include <deque>
#include "Parser.hpp"
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
		AbstractVM();//TODO: read from file
		~AbstractVM();
		AbstractVM(const AbstractVM & other);
		AbstractVM const & operator=(AbstractVM const & other);
		void run(std::string fileName = std::string());
	private:
		std::unique_ptr<Lexer> _lexer;
		std::unique_ptr<Parser> _parser;
		std::deque<IOperand*> _operands;

};

#endif