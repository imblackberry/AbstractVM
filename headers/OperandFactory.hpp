#ifndef OPERANDFACTORY_HPP
#define OPERANDFACTORY_HPP
#include "IOperand.hpp"
#include <functional>
#include <vector>

class OperandFactory{
	OperandFactory();
	// OperandFactory(const OperandFactory & other);
	// const OperandFactory& operator=(const OperandFactory & other);
	~OperandFactory();
	public:
		IOperand const * createOperand(eOperandType type, std::string const & value ) const;
	
	private:
		// IOperand const * createInt8(std::string const & value) const;
		// IOperand const * createInt16(std::string const & value) const;
		// IOperand const * createInt32(std::string const & value) const;
		IOperand const * createFloat(std::string const & value) const;
		IOperand const * createDouble(std::string const & value) const;

		std::vector<std::function<IOperand const *(std::string const & value)> > factory;
};

#endif