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
	operationsMap[Exit] = &AbstractVM::exit;
};
AbstractVM::~AbstractVM() {};

AbstractVM::AbstractVM(const AbstractVM & other){ *this = other; };

AbstractVM const & AbstractVM::operator=(AbstractVM const &) { return *this; }

void AbstractVM::run(std::string fileName)
{
    std::ifstream file;
    if (fileName != "")
    {
		file.open(fileName);
		if (!file)
			throw Exception("unable to open file " + fileName);
        _lexer = std::make_unique<Lexer>(file);
    }
    else
        _lexer = std::make_unique<Lexer>();
    _lexer->makeLexems();
	if (file)
		file.close();
    _parser = std::make_unique<Parser>(_lexer->getLexems());
    _parser->run();
	runActions(std::move(_parser->getActions()));
}

void AbstractVM::runActions(std::vector<Action> actions) {
	for (auto it = actions.begin(); it != actions.end(); it++) {
		if (it->operation == Exit)
			return ;
		auto doOperation = operationsMap[it->operation];
		auto operand = it->getOperand();
		(this->*doOperation)(std::move(operand));
	}
	if (actions.back().operation != Exit)
		throw Exception("last instruction must be exit");
}

void AbstractVM::push(std::unique_ptr<const IOperand> operand) {
	if (operand)
		_operands.push_front(std::move(operand));
}

void AbstractVM::pop(std::unique_ptr<const IOperand>)
{
	if (_operands.size() == 0)
		throw Exception("stack is empty");
	_operands.pop_front();
}

void AbstractVM::dump(std::unique_ptr<const IOperand>) {
	for (size_t i = 0; i < _operands.size(); i++)
		std::cout << _operands[i]->toString() << std::endl;
}

void AbstractVM::assertF(std::unique_ptr<const IOperand> operand) {
	if (_operands.empty())
		throw Exception("stack is empty");
	if (operand) {
		if (operand->getType() != _operands.front()->getType() ||
				operand->toString() != _operands.front()->toString())
			throw Exception("assertion is failed");
	}
}

void AbstractVM::add(std::unique_ptr<const IOperand>) {
	preArithmeticOp();
	const IOperand * res = *_tmpOp1 + *_tmpOp2;
	_tmpRes.reset(res);
	_operands.push_front(std::move(_tmpRes));
}

void AbstractVM::sub(std::unique_ptr<const IOperand>) {
	preArithmeticOp();
	const IOperand * res = *_tmpOp1 - *_tmpOp2;
	_tmpRes.reset(res);
	_operands.push_front(std::move(_tmpRes));
}

void AbstractVM::mul(std::unique_ptr<const IOperand>) {
	preArithmeticOp();
	const IOperand * res = *_tmpOp1 * *_tmpOp2;
	_tmpRes.reset(res);
	_operands.push_front(std::move(_tmpRes));
}

void AbstractVM::div(std::unique_ptr<const IOperand>) {
	preArithmeticOp();
	const IOperand * res = *_tmpOp1 / *_tmpOp2;
	_tmpRes.reset(res);
	_operands.push_front(std::move(_tmpRes));
}

void AbstractVM::mod(std::unique_ptr<const IOperand>) {
	preArithmeticOp();
	const IOperand * res = *_tmpOp1 % *_tmpOp2;
	_tmpRes.reset(res);
	_operands.push_front(std::move(_tmpRes));
}

void AbstractVM::print(std::unique_ptr<const IOperand>) {
	if (_operands.empty())
		throw Exception("stack is empty");
	auto op = std::move(_operands.front());
	if (op->getType() != eOperandType::Int8)
		throw Exception("operand with type int8 required");
	std::cout << static_cast<char>(std::stoi(op->toString())) << std::endl;
}

void AbstractVM::exit(std::unique_ptr<const IOperand>) { }

void AbstractVM::preArithmeticOp() {
	if (_operands.size() < MIN_SIZE_FOR_MATH_OP)
		throw Exception("stack is too small");
	_tmpOp1 = std::move(_operands.front());
	_operands.pop_front();
	_tmpOp2 = std::move(_operands.front());
	_operands.pop_front();
}