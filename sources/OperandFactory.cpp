#include "OperandFactory.hpp"
OperandFactory::OperandFactory(){
	(void)factory;
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

// IOperand const * OperandFactory::createOperand(eOperandType type, std::string const & value ) const{
// 	return factory[type](value);
// }

// IOperand const * OperandFactory::createInt8(std::string const & value) const{
// 	return new Int(value);
// }
// IOperand const * OperandFactory::createInt16(std::string const & value) const{
// 	return new Int(value);

// }
// IOperand const * OperandFactory::createInt32(std::string const & value) const{
// 	return new Int(value);

// }
// IOperand const * OperandFactory::createFloat(std::string const & value) const{
// 	IOperand  *tmp = new Operand<float, 32>(std::stof(value));
// 	return tmp;
// }

// IOperand const * OperandFactory::createDouble(std::string const & value) const{
// 	return new Operand<double, 64>(std::stod(value));
// }
