#include "OperandFactory.hpp"
OperandFactory::OperandFactory(){
	(void)createArr;
}

OperandFactory::OperandFactory(const OperandFactory & other){
	(void) other;
}

const OperandFactory& OperandFactory::operator=(const OperandFactory & other){
	(void) other;
}

OperandFactory::~OperandFactory(){

}

IOperand const * OperandFactory::createOperand(eOperandType type, std::string const & value ) const{
	return createArr[type](value);
}

IOperand const * createInt8(std::string const & value) const{
	return new <>(value);
}
IOperand const * createInt16(std::string const & value) const;
IOperand const * createInt32(std::string const & value) const;
IOperand const * createFloat(std::string const & value) const;
IOperand const * createDouble(std::string const & value) const;
