#ifndef PARSER_HPP
#define PARSER_HPP
#include <unordered_map>
#include "Lexer.hpp"

class Parser{
	public:
		Parser(){
			actions[Pop] = Parser::pop;
		}
		Parser(const Parser & other);
		Parser const & operator=(Parser const & other);
		~Parser(){}
		void getToken(eOption option, IOperand * operand){

		}
		void pop(IOperand * operand){
			operands.pop(operand);
		}
		unordered_map<eOption, void (Parser::*)(IOperand *)> actions;
		std::deque<IOperand*> operands;
};

#endif