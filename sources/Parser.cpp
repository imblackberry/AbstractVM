#include "Parser.hpp"

// Action::Action() : _operation(eOperation::N_OPS), _operand(nullptr) {};
// Action::~Action() {};

// Action::Action(eOperation operation, std::unique_ptr<IOperand const> operand) :
// 	_operation(operation), _operand(std::move(operand)) {};

// Action::Action(const Action & other){ *this = other; };

// Action const & Action::operator=(Action const & other) {
// 	if (this != & other) {
// 		_operation = other._operation;
// 		//_operand = std::move(other._operand);
// 	}
// 	return *this;
// }

std::unique_ptr<IOperand const> Action::getOperand() {
	return std::move(_operand);
}

Parser::Parser() {};
Parser::~Parser() {
	// for (auto ac : actions){
	// 	(void)ac._operand;
	// 	std::cout << "DESTRUCTOR" << std::endl;
	// 	std::cout << "\n ac._operand = " << validOps[static_cast<size_t>(ac._operation)] << "	";
	// 	if (ac._operand) {
	// 		std::cout << "ac._operandType = " << validTypes[ac._operand->getPrecision()] << "	";
	// 		std::cout << "ac._operand = " << ac._operand->toString();
	// 	}
	 	// if (ac._operand)
			// delete ac._operand;
	// }
};

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

enum eOperandType Parser::getOperandType() {
	nextCurrLexem();
	Lexem lexem = getCurrLexem();
	if (lexem.type == eLexemType::eOperandType) {
		auto it = std::find_if(validTypes.begin(), validTypes.end(), [&lexem](std::string op){
			return op == lexem.capacity ? true : false;
		});
		if (it != validTypes.end())
			return static_cast<enum eOperandType>(it - validTypes.begin());
	}
	throw Exception("a value type is unknown");
}

std::unique_ptr<IOperand const> Parser::getOperand() {
	OperandFactory factory;
	enum eOperandType type = getOperandType();
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
	//auto ac = Action(operation, std::move(operand));
	actions.push_back({operation, std::move(operand)});
	for (auto it = actions.begin(); it != actions.end(); it++) {
	std::cout << "\n it->_option = " << validOps[static_cast<size_t>(it->_operation)] << "	";
	if (it->_operand) {
		std::cout << "it->_operandType = " << validTypes[it->_operand->getPrecision()] << "	";
		std::cout << "it->_operand = " << it->_operand->toString();
	}
	}
}
void Parser::run() {
	while (nextCurrLexem()) {
		addAction();
	}
	if (actions.back()._operation != Exit)
		throw Exception("last instruction must be exit");
}

std::vector<Action> & Parser::getActions() { return actions; }