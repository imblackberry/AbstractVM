#include "AbstractVM.hpp"
AbstractVM::AbstractVM() {
	operationsMap[Push] = &AbstractVM::push;
	operationsMap[Pop] = &AbstractVM::pop;
	operationsMap[Dump] = &AbstractVM::dump;
	operationsMap[Assert] = &AbstractVM::assertF;
	operationsMap[Add] = &AbstractVM::add;
	operationsMap[Sub] = &AbstractVM::sub;
	operationsMap[Mul] = &AbstractVM::mul;
	operationsMap[Div] = &AbstractVM::div;
	operationsMap[Mod] = &AbstractVM::mod;
	operationsMap[Print] = &AbstractVM::print;
	//operationsMap[Exit] = &AbstractVM::exit;
};
AbstractVM::~AbstractVM() {
	for (auto op :_operands)
		delete op;
};

AbstractVM::AbstractVM(const AbstractVM & other){ *this = other; };

AbstractVM const & AbstractVM::operator=(AbstractVM const & other) {
	if (this != &other) {
        //_lexer = std::move(other._lexer);//should nullptr???
        //_parser = std::move(other._parser);//should nullptr???
        _operands = other._operands;
	}
	return *this;
}
void AbstractVM::run(std::string fileName)
{
    if (fileName != "")
    {
        std::ifstream file(fileName);
        _lexer = std::make_unique<Lexer>(file);
    }
    else
        _lexer = std::make_unique<Lexer>(std::cin);
    _lexer->makeLexems();
    _parser = std::make_unique<Parser>(_lexer->getLexems());
    _parser->run();
	runActions(_parser->getActions());
}

void AbstractVM::runActions(std::list<Action> & actions) {
	for (auto ac : actions) {
		auto doOperation = operationsMap[ac._operation];
		(this->*doOperation)(ac._operand);
	}
}

void AbstractVM::push(const IOperand* operand) {
	if (operand)
		_operands.push_front(operand);
}

void AbstractVM::pop(const IOperand*)
{
	if (_operands.size() == 0)
		throw Exception("stack is empty");
	delete _operands.front();
	_operands.pop_front();
}

void AbstractVM::dump(const IOperand*) {
	for (auto op : _operands)
		std::cout << op->toString() << std::endl;
}

void AbstractVM::assertF(const IOperand* operand) {
	if (_operands.empty())
		throw Exception("stack is empty");
		if (operand)
		{
			if (operand->getType() != _operands.front()->getType() ||
					operand->toString() != _operands.front()->toString())
			{
				delete operand;
				throw Exception("assertion is failed");
			}
			delete operand;
		}
}

void AbstractVM::add(const IOperand*) {
	preArithmeticOp();
	_operands.push_front(*_tmpOp1 + *_tmpOp2);
	delete _tmpOp1;
	delete _tmpOp2;
}

void AbstractVM::sub(const IOperand*) {
	preArithmeticOp();
	_operands.push_front(*_tmpOp1 - *_tmpOp2);
	delete _tmpOp1;
	delete _tmpOp2;
}

void AbstractVM::mul(const IOperand*) {
	preArithmeticOp();
	_operands.push_front(*_tmpOp1 * *_tmpOp2);
	delete _tmpOp1;
	delete _tmpOp2;
}

void AbstractVM::div(const IOperand*) {
	preArithmeticOp();
	if (_tmpOp2->toString() == "0")
		throw Exception("division by 0");
	_operands.push_front(*_tmpOp1 / *_tmpOp2);
	delete _tmpOp1;
	delete _tmpOp2;
}

void AbstractVM::mod(const IOperand*) {
	preArithmeticOp();
	if (_tmpOp2->toString() == "0")
		throw Exception("modulo by 0");
	_operands.push_front(*_tmpOp1 % *_tmpOp2);
	delete _tmpOp1;
	delete _tmpOp2;
}

void AbstractVM::print(const IOperand*) {
	if (_operands.empty())
		throw Exception("stack is empty");
	IOperand const * op = this->_operands.front();
	if (op->getType() != eOperandType::Int8)
		throw Exception("operand with type int8 required");
	std::cout << static_cast<char>(std::stoi(op->toString())) << std::endl;
	delete _tmpOp1;
	delete _tmpOp2;
}

void AbstractVM::preArithmeticOp() {
	if (_operands.size() < MIN_SIZE_FOR_MATH_OP)
		throw Exception("stack is too small");
	_tmpOp1 = _operands.front();
	_operands.pop_front();
	_tmpOp2 = _operands.front();
	_operands.pop_front();
}