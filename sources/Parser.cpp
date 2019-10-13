#include "Parser.hpp"

Action::Action() {};
Action::~Action() {};

Action::Action(eOperation operation, const IOperand * operand) :
			_operation(operation), _operand(operand){};

Action::Action(const Action & other){ *this = other; };

Action const & Action::operator=(Action const & other) {
	if (this != & other) {
		_operation = other._operation;
		_operand = other._operand;
	}
	return *this;
}

Parser::Parser() {};
Parser::~Parser() {};

Parser::Parser(std::vector<Lexem*> & lexems):
		_lexems(std::move(lexems))
{ }

Parser::Parser(const Parser & other) { *this = other; }

Parser const & Parser::operator=(Parser const & other) {
	if (this != &other) {
		_currLexem = other._currLexem;
		_currLine = other._currLine;
		actions = other.actions;
		_lexems = other._lexems;
	}
	return *this;
}

bool Parser::nextCurrLexem() {
	_currLexem++;
	if (_currLexem >= static_cast<int>(_lexems.size()))
		return false;
	if (_lexems[_currLexem]->type == eLexemType::Operation)
		_currLine++;
	return true;
}
Lexem * Parser::getCurrLexem() { return _lexems[_currLexem]; }

bool Parser::hasOperand(const eOperation operation){
	if (operation == Push || operation == Assert)
		return true;
	return false;
}
eOperation Parser::getOperation() {
	Lexem * lexem = getCurrLexem();
	if (lexem->type == eLexemType::Operation) {
		auto it = std::find_if(validOps.begin(), validOps.end(), [&lexem](std::string op){
			return op == lexem->capacity ? true : false;
		});
		if (it != validOps.end())
			return static_cast<eOperation>(it - validOps.begin());
	}
	throw Exception("an instruction is unknown");
}

enum eOperandType Parser::getOperandType() {
	nextCurrLexem();
	Lexem * lexem = getCurrLexem();
	if (lexem->type == eLexemType::eOperandType) {
		auto it = std::find_if(validTypes.begin(), validTypes.end(), [&lexem](std::string op){
			return op == lexem->capacity ? true : false;
		});
		if (it != validTypes.end())
			return static_cast<enum eOperandType>(it - validTypes.begin());
	}
	throw Exception("a value type is unknown");
}

const IOperand * Parser::getOperand() {
	OperandFactory factory;
	enum eOperandType type = getOperandType();
	nextCurrLexem();
	Lexem * operandLexem = getCurrLexem();
	if (operandLexem->type == Value)
		return factory.createOperand(type, operandLexem->capacity);
	return nullptr;
}

void Parser::addAction(){
	eOperation operation = getOperation();
	const IOperand * operand = nullptr;
	if (hasOperand(operation))
		operand = getOperand();
	actions.push_back({operation, operand});

}
void Parser::run(){
	while (nextCurrLexem()) {
		std::cout << "----------------" << std::endl;
		addAction();

		for (auto ac: actions){
			std::cout << "ac._operand = " << validOps[static_cast<size_t>(ac._operation)] << std::endl;
			if (ac._operand) {
				std::cout << "ac._operandType = " << validTypes[ac._operand->getPrecision()] << std::endl;
				std::cout << "ac._operand = " << ac._operand->toString() << std::endl;
			}
		}
		std::cout << "----------------" << std::endl;
	}
}

std::list<Action> & Parser::getActions() { return actions; }