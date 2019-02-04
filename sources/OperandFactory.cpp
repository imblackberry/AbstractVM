#include "OperandFactory.hpp"
OperandFactory::OperandFactory(){
	factory[Int8] = &OperandFactory::createInt8;
	factory[Int16] = &OperandFactory::createInt16;
	factory[Int32] = &OperandFactory::createInt32;
	factory[Float] = &OperandFactory::createFloat;
	factory[Double] = &OperandFactory::createDouble;
}

// OperandFactory::OperandFactory(const OperandFactory & other){
// 	(void) other;
// }

// const OperandFactory& OperandFactory::operator=(const OperandFactory & other){
// 	(void) other;
// 	return *this;
// }

OperandFactory::~OperandFactory(){

}

IOperand const * OperandFactory::createOperand(eOperandType type, std::string const & value ) const{
	IOperand const * (OperandFactory::*f)(std::string const &) const;
	f = factory.at(type);
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
