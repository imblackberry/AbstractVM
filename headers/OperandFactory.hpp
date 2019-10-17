#ifndef OPERANDFACTORY_HPP
#define OPERANDFACTORY_HPP
#include <iostream>
#include <unordered_map>
#include "Operand.hpp"


class OperandFactory{
	typedef std::unique_ptr<IOperand const> (OperandFactory::*CreateFunctions)(std::string const &) const;

	public:
		OperandFactory();
		OperandFactory(const OperandFactory & other);
		const OperandFactory& operator=(const OperandFactory & other);
		~OperandFactory();
		std::unique_ptr<IOperand const> createOperand(enum eOperandType type, std::string const & value ) const;

	private:
		std::unique_ptr<IOperand const> createInt8(std::string const & value) const;
		std::unique_ptr<IOperand const> createInt16(std::string const & value) const;
		std::unique_ptr<IOperand const> createInt32(std::string const & value) const;
		std::unique_ptr<IOperand const> createFloat(std::string const & value) const;
		std::unique_ptr<IOperand const> createDouble(std::string const & value) const;

		std::unordered_map<enum eOperandType, CreateFunctions > _factory; //todo: array
};


#endif
