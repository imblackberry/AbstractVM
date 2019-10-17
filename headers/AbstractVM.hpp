#ifndef ABSTRACTVM_HPP
#define ABSTRACTVM_HPP
#include <iostream>
#include <deque>
#include "Parser.hpp"
#include "IOperand.hpp"
#include "Exception.hpp"
#define NO_ARGS 1

class AbstractVM{
	typedef void (AbstractVM::*DoOperation)(std::unique_ptr<const IOperand>);
	public:
		AbstractVM();
		~AbstractVM();
		AbstractVM(const AbstractVM & other);
		AbstractVM const & operator=(AbstractVM const &);

		void run(std::string fileName = std::string());
	private:
		void runActions(std::vector<Action> actions);
		void push(std::unique_ptr<const IOperand>  operand);
		void pop(std::unique_ptr<const IOperand> );
		void dump(std::unique_ptr<const IOperand> );
		void assertF(std::unique_ptr<const IOperand>  operand);
		void add(std::unique_ptr<const IOperand> );
		void sub(std::unique_ptr<const IOperand> );
		void mul(std::unique_ptr<const IOperand> );
		void div(std::unique_ptr<const IOperand> );
		void mod(std::unique_ptr<const IOperand> );
		void print(std::unique_ptr<const IOperand> );
		void exit(std::unique_ptr<const IOperand> );
		void preArithmeticOp();

		std::unique_ptr<Lexer> _lexer;
		std::unique_ptr<Parser> _parser;
		std::deque<std::unique_ptr<const IOperand> > _operands;
		std::unordered_map<eOperation, DoOperation > operationsMap;

		std::unique_ptr<const IOperand> _tmpOp1;
		std::unique_ptr<const IOperand> _tmpOp2;
		std::unique_ptr<const IOperand> _tmpRes;
};

#endif