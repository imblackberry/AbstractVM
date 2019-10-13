#ifndef PARSER_HPP
#define PARSER_HPP
#include <array>
#include <list>
#include "Lexer.hpp"
#include "IOperand.hpp"
#include "OperandFactory.hpp"
#include "Exception.hpp"
#define MIN_SIZE_FOR_MATH_OP 2


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
	Exit,
	ExitSpec,
	N_OPS
};

class Action {
	public:
		Action();
		~Action();
		Action(eOperation operation, const IOperand * operand);
		Action(const Action & other);
		Action const & operator=(Action const & other);

		void run(){};
	//private:
		eOperation _operation;
		const IOperand * _operand;
};

class Parser{
	public:
		Parser();
		~Parser();
		Parser(std::vector<Lexem*> & lexems);
		Parser(const Parser & other);
		Parser const & operator=(Parser const & other);
		void run();
		std::list<Action> & getActions();

	private:
		bool nextCurrLexem();
		Lexem * getCurrLexem();
		bool hasOperand(const eOperation operation);
		eOperation getOperation();
		enum eOperandType getOperandType();
		const IOperand * getOperand();
		void addAction();
		// void push(void) {
		// 	//OperandFactory factory;
		// 	//factory.createOperand(getOperandType(), );
		// }
		// void pop(void) {
		// 	operands.pop_front();
		// }
		// void dump(void) {
		// 	for (auto operand : operands)
		// 		std::cout << operand->toString() << std::endl;
		// }
		// // void assert(void) {}
		// void add(void) {
		// 	if (operands.size() < MIN_SIZE_FOR_MATH_OP)
		// 		std::cout << "error" << std::endl; //todo exception
		// 	IOperand const * a = operands[0];
		// 	operands.pop_front();
		// 	IOperand const * b = operands[0];
		// 	operands.pop_front();
		// 	IOperand const * newOp = *a + *b;
		// 	operands.push_front(newOp);

		// }
	private:
		int _currLexem = -1;
		int _currLine = -1;
		std::list<Action> actions;
		std::vector<Lexem*> _lexems;
		static constexpr size_t N_TYPES = 5;
		const std::array<std::string, N_OPS> validOps = { { "push", "pop", "dump", "assert", "add",
							"sub", "mul", "div", "mod", "print", "exit", ";;"} };
		const std::array<std::string, N_TYPES> validTypes = { { "int8", "int16", "int32", "float",
							"double"} };
};

#endif