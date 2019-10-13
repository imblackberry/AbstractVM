#ifndef ABSTRACTVM_HPP
#define ABSTRACTVM_HPP
#include <iostream>
#include <deque>
#include "Parser.hpp"
#include "IOperand.hpp"
#include "Exception.hpp"
#define NO_ARGS 1

class AbstractVM{
	typedef void (AbstractVM::*DoOperation)(const IOperand*);
	public:
		AbstractVM();//TODO: read from file
		~AbstractVM();
		AbstractVM(const AbstractVM & other);
		AbstractVM const & operator=(AbstractVM const & other);

		class stack_error : public std::length_error
		{
			public:
				stack_error(const char *);
				virtual ~stack_error(void) throw();
		};

		void run(std::string fileName = std::string());
	private:
		void runActions(std::list<Action> & actions);
		void push(const IOperand* operand);
		void pop(const IOperand*);
		void dump(const IOperand*);
		void assertF(const IOperand* operand);
		void add(const IOperand*);
		void sub(const IOperand*);
		void mul(const IOperand*);
		void div(const IOperand*);
		void mod(const IOperand*);
		void print(const IOperand*);
		void preArithmeticOp();

		std::unique_ptr<Lexer> _lexer;
		std::unique_ptr<Parser> _parser;
		std::deque<const IOperand*> _operands;
		std::unordered_map<eOperation, DoOperation > operationsMap;

		const IOperand * _tmpOp1 = nullptr;
		const IOperand * _tmpOp2 = nullptr;
};

#endif