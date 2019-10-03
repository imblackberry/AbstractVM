#ifndef PARSER_HPP
#define PARSER_HPP
#include <unordered_map>
#include "Lexer.hpp"
#include "IOperand.hpp"
#include "OperandFactory.hpp"
#define MIN_SIZE_FOR_MATH_OP 2
// std::string validOp[11] = {"push", "pop", "dump", "assert", "add",
//							"sub", "mull", "div", "mod", "print", "exit"};

// 	std::string validTypes[5] = {"int8", "int16", "int32", "float", "double"};

enum eOperation{
	Push,//v
	Pop,
	Dump,
	Assert,//v
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
		Parser() {};
		Parser(std::list<Lexem*> & lexems);
		Parser(const Parser & other);
		Parser const & operator=(Parser const & other);
		~Parser(){}
		void push(void) {
			//OperandFactory factory;
			//factory.createOperand(getOperandType(), );
		}
		void pop(void) {
			operands.pop_front();
		}
		void dump(void) {
			for (auto operand : operands)
				std::cout << operand->toString() << std::endl;
		}
		// void assert(void) {}
		void add(void) {
			if (operands.size() < MIN_SIZE_FOR_MATH_OP)
				std::cout << "error" << std::endl; //todo exception
			IOperand const * a = operands[0];
			operands.pop_front();
			IOperand const * b = operands[0];
			operands.pop_front();
			IOperand const * newOp = *a + *b;
			operands.push_front(newOp);

		}
		std::unordered_map<eOperation, void (Parser::*)(void)> actions;
		std::deque<IOperand const *> operands;//
		std::list<Lexem*> _lexems;
};

#endif