#ifndef ABSTRACTVM_HPP
#define ABSTRACTVM_HPP
#include <iostream>
#include <deque>
#include "Parser.hpp"
#include "IOperand.hpp"
#include "Exception.hpp"
#define NO_ARGS 1
//TODO
//author file???

class AbstractVM{
	typedef void (AbstractVM::*DoOperation)(std::unique_ptr<const IOperand>);
	public:
		AbstractVM();//TODO: read from file
		~AbstractVM();
		AbstractVM(const AbstractVM & other);
		AbstractVM const & operator=(AbstractVM const & other);

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
		void print(std::unique_ptr<const IOperand> );//todo
		void exit(std::unique_ptr<const IOperand> );
		void preArithmeticOp();

		std::unique_ptr<Lexer> _lexer;
		std::unique_ptr<Parser> _parser;
		std::deque<std::unique_ptr<const IOperand> > _operands;
		std::unordered_map<eOperation, DoOperation > operationsMap;

		std::unique_ptr<const IOperand> _tmpOp1 = nullptr;
		std::unique_ptr<const IOperand> _tmpOp2 = nullptr;
		std::unique_ptr<const IOperand> t = nullptr;
};

#endif