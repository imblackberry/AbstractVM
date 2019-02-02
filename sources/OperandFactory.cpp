#include "OperandFactory.hpp"
OperandFactory::OperandFactory(){
	factory.push_back(&OperandFactory::createInt8);
	factory.push_back(&OperandFactory::createInt16);
	factory.push_back(&OperandFactory::createInt32);
	factory.push_back(&OperandFactory::createFloat);
	factory.push_back(&OperandFactory::createDouble);
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
	return (this->*factory[type])(value);
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
