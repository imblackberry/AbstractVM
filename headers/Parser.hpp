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
	//private: todo
		eOperation _operation;
		const IOperand * _operand;
};

class Parser{
	public:
		Parser();
		~Parser();
		Parser(std::vector<Lexem> & lexems);
		Parser(const Parser & other);
		Parser const & operator=(Parser const & other);
		void run();
		const std::list<Action> & getActions();
		std::list<Action> actions;

	private:
		bool nextCurrLexem();
		Lexem getCurrLexem();
		bool hasOperand(const eOperation operation);
		enum eOperation getOperation();
		enum eOperandType getOperandType();
		const IOperand * getOperand();
		void addAction();
	private:
		int _currLexem = -1;
		std::vector<Lexem> _lexems;
		static constexpr size_t N_TYPES = 5;
		const std::array<std::string, N_OPS> validOps = { { "push", "pop", "dump", "assert", "add",
							"sub", "mul", "div", "mod", "print", "exit"} };
		const std::array<std::string, N_TYPES> validTypes = { { "int8", "int16", "int32", "float",
							"double"} };
};

#endif