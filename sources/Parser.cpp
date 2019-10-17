#include "Parser.hpp"

std::unique_ptr<IOperand const> Action::getOperand() {
	return std::move(_operand);
}

Parser::Parser() {};
Parser::~Parser() {};

Parser::Parser(std::vector<Lexem> & lexems):
		_lexems(std::move(lexems))
{ }

Parser::Parser(const Parser & other) { *this = other; }

Parser const & Parser::operator=(Parser const & other) {
	if (this != &other) {
		_currLexem = other._currLexem;
		//actions = other.actions;
		_lexems = other._lexems;
	}
	return *this;
}

bool Parser::nextCurrLexem() {
	_currLexem++;
	if (_currLexem >= static_cast<int>(_lexems.size()))
		return false;
	return true;
}
Lexem Parser::getCurrLexem() { return _lexems[_currLexem]; }

bool Parser::hasOperand(const eOperation operation){
	if (operation == Push || operation == Assert)
		return true;
	return false;
}
enum eOperation Parser::getOperation() {
	Lexem lexem = getCurrLexem();
	if (lexem.type == eLexemType::Operation) {
		auto it = std::find_if(validOps.begin(), validOps.end(), [&lexem](std::string op){
			return op == lexem.capacity ? true : false;
		});
		if (it != validOps.end())
			return static_cast<eOperation>(it - validOps.begin());
	}
	throw Exception("an instruction is unknown");
}

eOperandType Parser::getOperandType() {
	nextCurrLexem();
	Lexem lexem = getCurrLexem();
	if (lexem.type == eLexemType::OperandType) {
		auto it = std::find_if(validTypes.begin(), validTypes.end(), [&lexem](std::string op){
			return op == lexem.capacity ? true : false;
		});
		if (it != validTypes.end())
			return static_cast<eOperandType>(it - validTypes.begin());
	}
	throw Exception("a value type is unknown");
}

std::unique_ptr<IOperand const> Parser::getOperand() {
	OperandFactory factory;
	eOperandType type = getOperandType();
	nextCurrLexem();
	Lexem operandLexem = getCurrLexem();
	if (operandLexem.type == Value)
		return factory.createOperand(type, operandLexem.capacity);
	return std::unique_ptr<IOperand const> {};
}

void Parser::addAction(){
	eOperation operation = getOperation();
	std::unique_ptr<IOperand const> operand = nullptr;
	if (hasOperand(operation))
		operand = getOperand();
	actions.push_back({operation, std::move(operand)});
	// for (auto it = actions.begin(); it != actions.end(); it++) {
	// std::cout << "\n it->_option = " << validOps[static_cast<size_t>(it->operation)] << "	";
	// if (it->_operand) {
	// 	std::cout << "it->_operandType = " << validTypes[it->_operand->getPrecision()] << "	";
	// 	std::cout << "it->_operand = " << it->_operand->toString();
	// }
	// }
}
void Parser::run() {
	while (nextCurrLexem()) {
		addAction();
	}
}

std::vector<Action> & Parser::getActions() { return actions; }