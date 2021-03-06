#include "OperandFactory.hpp"

OperandFactory::OperandFactory(){
	_factory[Int8] = &OperandFactory::createInt8;
	_factory[Int16] = &OperandFactory::createInt16;
	_factory[Int32] = &OperandFactory::createInt32;
	_factory[Float] = &OperandFactory::createFloat;
	_factory[Double] = &OperandFactory::createDouble;
}

OperandFactory::OperandFactory(const OperandFactory & other){
	*this = other;
}

const OperandFactory& OperandFactory::operator=(const OperandFactory & other){
	if (this != &other)
		_factory = other._factory;
	return *this;
}

OperandFactory::~OperandFactory(){

}

std::unique_ptr<IOperand const> OperandFactory::createOperand(eOperandType type, std::string const & value ) const {
	CreateFunctions f = _factory.at(type);
	return (this->*f)(value);
}

std::unique_ptr<IOperand const> OperandFactory::createInt8(std::string const & value) const{
	return std::make_unique<Operand<int8_t>>(value);
}
std::unique_ptr<IOperand const> OperandFactory::createInt16(std::string const & value) const{
	return std::make_unique<Operand<int16_t>>(value);

}
std::unique_ptr<IOperand const> OperandFactory::createInt32(std::string const & value) const{
	return std::make_unique<Operand<int32_t>>(value);

}
std::unique_ptr<IOperand const> OperandFactory::createFloat(std::string const & value) const{
	return std::make_unique<Operand<float>>(value);
}

std::unique_ptr<IOperand const> OperandFactory::createDouble(std::string const & value) const{
	return std::make_unique<Operand<double>>(value);
}
