#ifndef OPERANDFACTORY_HPP
#define OPERANDFACTORY_HPP
#include "Operand.hpp"
#include <iostream>

class OperandFactory{
	public:
	OperandFactory();
	// OperandFactory(const OperandFactory & other);
	// const OperandFactory& operator=(const OperandFactory & other);
	~OperandFactory();
		IOperand const * createOperand(eOperandType type, std::string const & value ) const;
	
	private:
		IOperand const * createInt8(std::string const & value) const;
		IOperand const * createInt16(std::string const & value) const;
		IOperand const * createInt32(std::string const & value) const;
		IOperand const * createFloat(std::string const & value) const;
		IOperand const * createDouble(std::string const & value) const;

		std::vector<IOperand const * (OperandFactory::*)(std::string const &) const > factory;
};

#endif
