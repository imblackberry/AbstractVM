#ifndef PARSER_HPP
#define PARSER_HPP
#include <unordered_map>
#include "Lexer.hpp"
#include "IOperand.hpp"

// std::string validOp[11] = {"push", "pop", "dump", "assert", "add",
//							"sub", "mull", "div", "mod", "print", "exit"};

// 	std::string validTypes[5] = {"int8", "int16", "int32", "float", "double"};

enum eOperation{
	Pop,
	Dump,
	Assert,
	Add,
	Sub,
	Mul,
	Div,
	Mod,
	Print,
	Exit
};

class Parser{
	public:
		Parser(){
			actions[Pop] = Parser::pop;
			// actions[Dump] = Parser::dump;
			// actions[Assert] = Parser::assert;
			// actions[Add] = Parser::add;
			// actions[Sub] = Parser::sub;
			// actions[Mul] = Parser::mul;
			// actions[Div] = Parser::div;
			// actions[Mod] = Parser::mod;
			// actions[Print] = Parser::print;
			// actions[Exit] = Parser::exit;
		}
		Parser(const Parser & other);
		Parser const & operator=(Parser const & other);
		~Parser(){}
		void pop(IOperand *){
			operands.pop_front();//or back
		}
		// unordered_map<eOption, void (Parser::*)(IOperand *)> actions;
		std::deque<IOperand*> operands;//
};

#endif