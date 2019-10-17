#ifndef PARSER_HPP
#define PARSER_HPP
#include <array>
#include <unordered_map>
#include <vector>
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

struct Action {
	std::unique_ptr<IOperand const> getOperand();
	eOperation operation;
		std::unique_ptr<IOperand const> _operand;
	private:
};

class Parser{
	public:
		Parser();
		~Parser();
		Parser(std::vector<Lexem> & lexems);
		Parser(const Parser & other);
		Parser const & operator=(Parser const & other);
		void run();
		std::vector<Action> & getActions();

	private:
		bool nextCurrLexem();
		Lexem getCurrLexem();
		bool hasOperand(const eOperation operation);
		enum eOperation getOperation();
		eOperandType getOperandType();
		std::unique_ptr<IOperand const> getOperand();
		void addAction();
	private:
		int _currLexem = -1;
		std::vector<Action> actions;
		std::vector<Lexem> _lexems;
		static constexpr size_t N_TYPES = 5;
		const std::array<std::string, N_OPS> validOps = { { "push", "pop", "dump", "assert", "add",
							"sub", "mul", "div", "mod", "print", "exit"} };
		const std::array<std::string, N_TYPES> validTypes = { { "int8", "int16", "int32", "float",
							"double"} };
};

#endif