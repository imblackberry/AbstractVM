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

IOperand const * OperandFactory::createOperand(eOperandType type, std::string const & value ) const {
	CreateFunctions f = _factory.at(type);
	return (this->*f)(value);
}

IOperand const * OperandFactory::createInt8(std::string const & value) const{
	return new Operand<int8_t>(value);
}
IOperand const * OperandFactory::createInt16(std::string const & value) const{
	return new Operand<int16_t>(value);

}
IOperand const * OperandFactory::createInt32(std::string const & value) const{
	return new Operand<int32_t>(value);

}
IOperand const * OperandFactory::createFloat(std::string const & value) const{
	return new Operand<float>(value);
}

IOperand const * OperandFactory::createDouble(std::string const & value) const{
	return new Operand<double>(value);
}
