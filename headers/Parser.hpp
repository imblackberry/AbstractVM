#ifndef PARSER_HPP
#define PARSER_HPP
#include <unordered_map>
#include "Lexer.hpp"
#include "IOperand.hpp"
#include "OperandFactory.hpp"
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
	NN
};

class Action {
	public:
		Action(){};
		Action(eOperation operation, IOperand * operand) : 
			_operation(operation), _operand(operand){};
		Action(const Action & other);
		Action const & operator=(Action const & other);
		~Action(){};

		void run(){};
	private:
		eOperation _operation;
		IOperand * _operand;
};

class Parser{
	public:
		Parser() {};
		Parser(std::list<Lexem*> & lexems);
		Parser(const Parser & other);
		Parser const & operator=(Parser const & other);
		~Parser(){}
		bool hasOperand(const eOperation operation){
			if (operation == Push || operation == Assert)
				return true;
			return false;
		}
		enum eOperation getOperation() {
			auto lexem = _lexems.begin();
			if (lexem.type == eLexemType::Operation) {
				for (size_t i = 0; i < N_OPS; i++) {
					if (validOps[i] == lexem.capacity){
						_lexems.pop_front();
						return static_cast<eOperation>(i);
					}
				}
			}
			return eOperation::NN;
		}
		void addAction(){
			eOperation operation = getOperation();
			IOperand * operand = nullptr;
			if (hasOperand(operation))
				operand = getOperand();
			actions.push_back();
			
			
		}
		void run(){
			for (lineNum = 0; _lexems < _lexems.end(); lineNum++) {
				addAction();
			}
		}
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
		size_t lineNum;
		std::list<Action> actions;
		std::list<Lexem*> _lexems;
		constexpr size_t N_OPS = 11;
		constexpr size_t N_TYPES = 5;
		const std::string validOps[N_OPS] = {"push", "pop", "dump", "assert", "add",
							"sub", "mull", "div", "mod", "print", "exit"};
		const std::string validTypes[N_TYPES] = {"int8", "int16", "int32", "float",
							"double"};
};

#endif